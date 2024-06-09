from src.utils.utils import *
import sys
from src.utils.enumeration import *
from Instruction import *

class ISA_Soup:
    def __init__(self, isa_llvm_urls: list[str] | str) -> None:
        self.isa_llvm_urls = [isa_llvm_urls] if isinstance(isa_llvm_urls, str) else isa_llvm_urls
        self.instruction_dict_by_format = None
        self.instruction_formats_list = None
        self.llvm_soups_list = [get_soup_from_request_http(url) for url in self.isa_llvm_urls]

    def get_instruction_dict_by_format(self) -> dict :
        return self.instruction_dict_by_format
    
    def get_instruction_formats_list(self) -> list :
        return self.instruction_formats_list

    def scrape_instruction_formats_list(self) -> None:
        instruction_type_set = set()
        for llvm_soup in self.llvm_soups_list:
            instruction_type_set |= set(self._scrape_instruction_formats_list_aux(llvm_soup))
        self.instruction_formats_list = list(instruction_type_set)

    def _scrape_instruction_formats_list_aux(self, llvm_soup: BeautifulSoup) -> list:
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
        return [element.get_text(strip=True) for element in instruction_formats]
    
    def scrape_instruction_dict_by_format(self) -> None:
        if self.instruction_formats_list == None:
            raise AttributeError("instruction_formats_list is not initialized. Please initialize it before calling this method.") 
        self.instruction_dict_by_format = {}
        for llvm_soup in self.llvm_soups_list:
            instruction_dict_by_format = self._scrape_instruction_dict_by_format_aux(llvm_soup) 
            self.instruction_dict_by_format = merge_dicts(instruction_dict_by_format, self.instruction_dict_by_format)

    def _scrape_instruction_dict_by_format_aux(self, llvm_soup: BeautifulSoup) -> dict:
        instruction_dict_by_format = {}
        section_instructions = llvm_soup.find('section', id='instructions')
        
        if not section_instructions:
            print("The section with ID 'instructions' was not found on the page.")
            sys.exit()

        for instruction_format in self.instruction_formats_list:
            id_section_format = instruction_format.lower().replace(" ", "-")
            section_format = section_instructions.find('section', id=id_section_format)
            if not section_format:
                print(f"The section with ID '{id_section_format}' was not found within the 'instructions' section.")
                sys.exit()
            
            section_content = section_format.find('pre', class_='literal-block')
            if not section_content:
                continue
            
            table = section_content.get_text().split('\n')
            table_soup = section_content.prettify().split('\n')[2:]
            header_line = table.pop(0)
            column_starts = [header_line.find(col) for col in header_line.split()]
            
            section_table = []
            for line, line_soup in zip(table[1:], table_soup):
                if not line.strip():
                    continue
                
                elements = [line[start:end].strip() for start, end in zip(column_starts, column_starts[1:] + [None])]
                instruction = [elements.pop(0)]
                modifiers = [f"{modifier}:MOD" for modifier in elements.pop().split()]
                operands = []
                
                for index, e in enumerate(elements):
                    if e.strip():
                        operand = e.replace(',', '')
                        operand_only = operand.split(':')[0].strip()
                        tag = BeautifulSoup(line_soup, 'html.parser').find('a', class_='reference internal', text=operand_only)
                        href = tag.get('href') if tag else 'N/A'
                        operand = f"{operand}:{href}:{''.join([c for c in header_line.split()[index + 1] if not c.isdigit()])}"
                        operands.append(operand)
                
                instruction.extend(operands)
                instruction.extend(modifiers)
                section_table.append(instruction)
            
            instruction_dict_by_format[instruction_format] = section_table
        return instruction_dict_by_format
        

    def create_instruction_dict_by_format(self) -> None :
        self.scrape_instruction_formats_list()
        self.scrape_instruction_dict_by_format()