from src.utils.utils import *
import sys
from src.utils.enumeration import *
from src.InstructionData.Operand import Operand
import re
import threading
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor


TYPE_SUFFIX = [
    'b512', 'b256', 'b128', 'b64', 'b32', 'b16', 'b8', 
    'u64', 'u32', 'u16', 'u8', 'u4',
    'i64', 'i32', 'i16', 'i8', 'i4',
    'f64', 'f32', 'f16', 'b16',
    'bf16'
]

SUFFIX_AUX = ['x2', 'x4', 'x8', 'x16', 'x32']

TYPE_SUFFIX += [base + suffix for base in TYPE_SUFFIX for suffix in SUFFIX_AUX] + ['fx']

SIZE_SUFFIX = [
    "x2", "x3", "x4", "x8", "x16",
    "x", "xy", "xyz", "xyzw",
    "d16_x", "d16_xy", "d16_xyz", "d16_xyzw",
    "d16_format_x", "d16_format_xy", "d16_format_xyz", "d16_format_xyzw"
]

SIZE_SUFFIX_CORRESPONDING = {
    "x2": "b64", "x3": "b96", "x4": "b128", "x8": "b256", "x16": "b512",
    "x": "b32", "xy": "b64", "xyz": "b96", "xyzw": "b128",
    "d16_x": "b16", "d16_xy": "b16x2", "d16_xyz": "b16x3", "d16_xyzw": "b16x4",
    "d16_format_x": "b16", "d16_format_xy": "b16x2", "d16_format_xyz": "b16x3", "d16_format_xyzw": "b16x4"
}

ENCODING_SUFFIX = ['e32', 'e64', 'dpp', 'sdwa', 'e64_dpp']

class ISA_Soup:
    def __init__(self, isa_llvm_urls):
        self.isa_llvm_urls = [isa_llvm_urls] if isinstance(isa_llvm_urls, str) else isa_llvm_urls
        self.instruction_dict = {}
        self.instruction_formats_list = []
        self.llvm_soups_list = [get_soup_from_request_http(url) for url in self.isa_llvm_urls]

    def get_instruction_dict(self):
        return self.instruction_dict
    
    def get_instruction_formats_list(self):
        return self.instruction_formats_list

    def scrape_instruction_formats_list(self):
        instruction_type_set = set()
        for llvm_soup in self.llvm_soups_list:
            nav_contents = llvm_soup.find('nav', id='contents')
            if not nav_contents:
                print("The nav with ID 'contents' was not found on the page.")
                sys.exit()

            instructions_list = nav_contents.find('a', string='Instructions')
            if not instructions_list:
                print("The list with the title 'Instructions' was not found in the nav 'contents'.")
                sys.exit()

            sub_list = instructions_list.find_next('ul')
            if not sub_list:
                print("No sub-list found for the list 'Instructions'.")
                sys.exit()

            instruction_formats = sub_list.find_all('li')
            instruction_type_set.update(element.get_text(strip=True) for element in instruction_formats)
        
        self.instruction_formats_list = list(instruction_type_set)

    def scrape_instruction_dict(self):
        if not self.instruction_formats_list:
            raise AttributeError("instruction_formats_list is not initialized. Please initialize it before calling this method.") 
        
        href_save_dic = {}
        lock_for_update_instruction_dict = threading.Lock()
        lock_for_href_dict = threading.Lock()

        def scrape_instruction_dict_by_format(instruction_format, llvm_soup):
            def parse_instruction(elements):
                def strip_suffix(base_str, suffixes):
                    for suffix in suffixes:
                        if base_str.endswith(suffix):
                            base_str = base_str[:-len(suffix)]
                            if base_str.endswith('_'):
                                base_str = base_str[:-1]
                            return base_str, suffix
                    return base_str, None

                instruction = elements.pop(0).strip()
                instruction_wo_encoding_suffix, encoding_suffix = strip_suffix(instruction, ENCODING_SUFFIX)
                base_str, size_suffix = strip_suffix(instruction_wo_encoding_suffix, SIZE_SUFFIX)
                type_suffix_src = SIZE_SUFFIX_CORRESPONDING.get(size_suffix, 'b32')
                base_str, type_suffix_src = strip_suffix(base_str, TYPE_SUFFIX) or type_suffix_src
                base_str, type_suffix_dst = strip_suffix(base_str, TYPE_SUFFIX)
                if type_suffix_dst is None:
                    type_suffix_dst = type_suffix_src

                return instruction, instruction_wo_encoding_suffix, type_suffix_dst, type_suffix_src, encoding_suffix
            
            def parse_modifiers(elements):
                return elements.pop().split() if 'MODIFIERS' in header_line else []
                
            def parse_operands(elements, line_soup):
                def get_operand_info(url):
                    new_url = f"https://llvm.org/docs/AMDGPU/{url}"
                    try:
                        print(f"get info for {new_url}")
                        op_soup = get_soup_from_request_http(new_url)
                        op_section = op_soup.find('section')
                        if op_section is None:
                            raise ValueError(f"No section found in the page for URL: {new_url}")

                        informations = {'url': new_url, 'size': 'No size found', 'op': 'No operand found'}
                        lines = op_section.get_text().split('\n')[1:]
                        for line in lines:
                            if 'Size:' in line:
                                informations['size'] = line.split(':', 1)[1].strip()
                            elif 'Operands:' in line:
                                informations['op'] = line.split(':', 1)[1].strip()
                    except Exception as e:
                        print(f"Error occurred while fetching operand info: {e}")
                        informations = {'url': new_url, 'size': 'Error', 'op': 'Error'}

                    return informations

                def parse_operands_aux(operand, index):
                    operand = operand.replace(',', '')
                    operand_split = operand.split(':')

                    operand_name = operand_split.pop(0).strip()
                    operand_role = ''.join([c for c in header_line.split()[index + 1] if not c.isdigit()])
                    operand_type = type_suffix_src if operand_role == 'SRC' else type_suffix_dst
                    operand_is_optional = False
                    operand_is_modifiable = False
                    operand_can_be_dst = False

                    for attribute in operand_split:
                        if attribute == 'opt':
                            operand_is_optional = True
                        elif attribute == 'm':
                            operand_is_modifiable = True
                        elif attribute == 'dst':
                            operand_can_be_dst = True
                        elif attribute in TYPE_SUFFIX:
                            operand_type = attribute
                        else:
                            print(f"Operand attribute '{attribute}' not known for '{operand_name}'")
                    
                    tag = BeautifulSoup(line_soup, 'html.parser').find('a', class_='reference internal', text=operand_name)
                    operand_href = tag.get('href') if tag else 'N/A'

                    with lock_for_href_dict:
                        if operand_href != 'N/A' and operand_href not in href_save_dic:
                            href_save_dic[operand_href] = get_operand_info(operand_href)

                    href_id_match = re.search(r'^(.*?)\.html', operand_href)
                    href_id = href_id_match.group(1) if href_id_match else operand_href

                    return Operand(
                        name=operand_name,
                        type=operand_type,
                        role=operand_role,
                        is_optional=operand_is_optional,
                        is_modifiable=operand_is_modifiable,
                        can_be_dst=operand_can_be_dst,
                        href_id=href_id,
                        href_url=href_save_dic[operand_href]['url'],
                        size=href_save_dic[operand_href]['size'],
                        op=href_save_dic[operand_href]['op']
                    )

                return [parse_operands_aux(op, i) for i, op in enumerate(elements) if op.strip()]

            id_section_format = instruction_format.lower().replace(" ", "-")
            section_format = llvm_soup.find('section', id=id_section_format)
            if not section_format:
                print(f"The section with ID '{id_section_format}' was not found within the 'instructions' section.")
                sys.exit()
            
            section_content = section_format.find('pre', class_='literal-block')
            if not section_content:
                return
            
            table = section_content.get_text().split('\n')
            table_soup = section_content.prettify().split('\n')[2:]
            header_line = table.pop(0)
            column_starts = [header_line.find(col) for col in header_line.split()]

            for line, line_soup in zip(table[1:], table_soup):
                if not line.strip():
                    continue
                
                elements = [line[start:end].strip() for start, end in zip(column_starts, column_starts[1:] + [None])]
                instruction_mnemonic, instruction_mnemonic_wo_encoding_suffix, type_suffix_dst, type_suffix_src, _ = parse_instruction(elements)
                modifiers = parse_modifiers(elements)
                operands = parse_operands(elements, line_soup)

                with lock_for_update_instruction_dict:
                    self.instruction_dict[instruction_mnemonic] = [
                        instruction_format,
                        instruction_mnemonic_wo_encoding_suffix,
                        type_suffix_dst,
                        type_suffix_src,
                        operands,
                        modifiers
                    ]

        def scrape_instruction_dict_by_soup(llvm_soup):
            section_instructions = llvm_soup.find('section', id='instructions')
            if not section_instructions:
                print("The section with ID 'instructions' was not found on the page.")
                sys.exit()

            with ThreadPoolExecutor(max_workers=10) as executor:
                futures = [executor.submit(scrape_instruction_dict_by_format, instruction_format, llvm_soup)
                           for instruction_format in self.instruction_formats_list]
                for future in futures:
                    future.result()
        
        for llvm_soup in self.llvm_soups_list:
            scrape_instruction_dict_by_soup(llvm_soup)

    def create_instruction_dict(self):
        self.scrape_instruction_formats_list()
        self.scrape_instruction_dict()
