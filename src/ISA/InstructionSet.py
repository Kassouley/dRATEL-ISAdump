import re
import threading
import csv
from src.ISA.ISA_Soup import ISA_Soup
from src.ISA.ISA_PDF import ISA_PDF
from src.InstructionData.Instruction import Instruction
from src.InstructionData.Operand import Operand
from src.InstructionData.Format import Format
from src.utils.utils import *
from src.utils.enumeration import *

TYPE_SUFFIX = ['b512', 'b256', 'b128', 'b64', 'b32', 'b16', 'b8', 
               'u64', 'u32', 'u16', 'u8', 'u4',
               'i64', 'i32', 'i16', 'i8', 'i4',
               'f64', 'f32', 'f16', 'b16',
               'bf16'
]
SUFFIX_AUX = ['x2', 'x4', 'x8', 'x16', 'x32']

TYPE_SUFFIX = TYPE_SUFFIX + [base + suffix for base in TYPE_SUFFIX for suffix in SUFFIX_AUX] + ['fx']

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

class InstructionSet :
    def __init__(self, isa_name: str, isa_llvm_urls: list[str] | str, 
                 isa_pdf_path: str, pdf_pages_range: range, pdf_is_double_optable: bool) -> None:
        
        self.isa_name = isa_name
        self.isa_llvm_urls = isa_llvm_urls
        self.isa_llvm_soup = ISA_Soup(isa_llvm_urls)
        self.isa_pdf = ISA_PDF(isa_pdf_path, self.get_pdf_table_format(), pdf_pages_range, pdf_is_double_optable)
        
        self.instructions_dict_lock = threading.Lock()
        self.href_save_dic_lock = threading.Lock()
        self.instructions_dict: dict[str,list[Instruction]] = {}
        self.href_save_dic = {}

    def get_pdf_table_format(self) -> None:
        raise NotImplementedError("This method should be implemented in the subclass")
    
    def set_correct_type(self, instruction, instruction_format_str) -> None :
        raise NotImplementedError("This method should be implemented in the subclass")

    def get_operand_info(self, url: str) -> dict:
        new_url = f"https://llvm.org/docs/AMDGPU/{url}"
        try:
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

    def create_instructions_dict_aux(self, instruction_line: list, instruction_format_str: str) :
        def parse_instruction_suffix(input_str):
            def strip_suffix(base_str, suffixes):
                for suffix in suffixes:
                    if base_str.endswith(suffix):
                        base_str = base_str[:-len(suffix)]
                        if base_str.endswith('_'):
                            base_str = base_str[:-1]
                        return base_str, suffix
                return base_str, None

            base_str = input_str
            base_str_wo_encoding_suffix, encoding_suffix = strip_suffix(base_str, ENCODING_SUFFIX)
            base_str, size_suffix = strip_suffix(base_str_wo_encoding_suffix, SIZE_SUFFIX)
            type_suffix_src = SIZE_SUFFIX_CORRESPONDING.get(size_suffix, 'b32')
            base_str, type_suffix_src = strip_suffix(base_str, TYPE_SUFFIX) or type_suffix_src
            base_str, type_suffix_dst = strip_suffix(base_str, TYPE_SUFFIX)
            return base_str_wo_encoding_suffix, type_suffix_dst, type_suffix_src, encoding_suffix
        
        instruction_mnemonic = instruction_line.pop(0)
        instruction_mnemonic_wo_encoding_suffix, type_suffix_dst, type_suffix_src, _ = parse_instruction_suffix(instruction_mnemonic)
        if type_suffix_dst == None :
            type_suffix_dst = type_suffix_src

        # OPERANDS & MODFIERS CREATION
        instruction_modifier_list = []
        instruction_operand_list = []

        for argument in instruction_line :
            argument_split = argument.split(':')
            if argument_split[-1].strip() == 'MOD' :
                instruction_modifier_list.append(argument_split[0])
            else :
                operand_name = argument_split.pop(0)
                operand_role = argument_split.pop()
                operand_href = argument_split.pop()
                operand_type = type_suffix_src if operand_role == 'SRC' else type_suffix_dst

                operand_is_optional = False
                operand_is_modifiable = False
                operand_can_be_dst = False

                while argument_split:
                    attribute = argument_split.pop()
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
                
                if operand_href not in self.href_save_dic :
                    tmp = self.get_operand_info(operand_href)
                    with self.href_save_dic_lock :
                        if operand_href not in self.href_save_dic :
                            self.href_save_dic[operand_href] = tmp

                href_id_match = re.search(r'^(.*?)\.html', operand_href)
                href_id = href_id_match.group(1) if href_id_match else operand_href

                instruction_operand_list.append(
                    Operand(
                        name=operand_name, 
                        type=operand_type,
                        role=operand_role,
                        is_optional=operand_is_optional,
                        is_modifiable=operand_is_modifiable,
                        can_be_dst=operand_can_be_dst,
                        href_id=href_id, 
                        href_url=self.href_save_dic[operand_href]['url'], 
                        size=self.href_save_dic[operand_href]['size'], 
                        op=self.href_save_dic[operand_href]['op']
                    )
                )

        instruction_type = type_suffix_src if instruction_operand_list else "-"

        # INSTRUCTION CREATION
        instruction = Instruction(mnemonic=instruction_mnemonic, 
                                  type=instruction_type, 
                                  operand_list=instruction_operand_list, 
                                  modifier_list=instruction_modifier_list)
                                  
        
        # OPCODE AND TYPE SET
        pdf_instruction_dict = self.isa_pdf.get_instructions_dict()
        instruction_mnemonic_wo_encoding_suffix = instruction_mnemonic_wo_encoding_suffix.upper()
        if instruction_mnemonic_wo_encoding_suffix in pdf_instruction_dict :
            pdf_instruction_details = pdf_instruction_dict[instruction_mnemonic_wo_encoding_suffix]
            instruction.set_opcode(pdf_instruction_details[ISA_Pdf.OPCODE.value])
        else :
            print(f"No opcode found for : {instruction.get_mnemonic()} ({instruction_format_str})")
            instruction.set_note(
                    f"No opcode found. Instruction exists in LLVM documentation ({self.isa_llvm_urls}) "
                    f"but not in {self.isa_name} documentation"
            )

        self.set_correct_type(instruction, instruction_format_str)
        
        # INSTRUCTION ATOMIC ADD TO DIC
        with self.instructions_dict_lock:
            instruction_format_name = instruction.get_format().name
            if instruction_format_name not in self.instructions_dict:
                self.instructions_dict[instruction_format_name] = []
            self.instructions_dict[instruction_format_name].append(instruction)

    def create_instructions_dict(self) -> None :
        self.isa_llvm_soup.create_instruction_dict_by_format()
        self.isa_pdf.scrape_tables_from_pdf()
        self.isa_pdf.create_format_dict()
        self.isa_pdf.create_instructions_dict()
        isa_llvm_soup_instruction_dict = self.isa_llvm_soup.get_instruction_dict_by_format()

        threads = []
        for instruction_format, instructions_list in isa_llvm_soup_instruction_dict.items() :
            for instruction in instructions_list :
                self.create_instructions_dict_aux(instruction, instruction_format)
                # t = threading.Thread(target=self.create_instructions_dict_aux, args=(instruction, instruction_format,))
                # threads.append(t)
                # t.start()

        # for t in threads:
        #     t.join()

        self.add_no_match_instructions()

    def add_no_match_instructions(self) -> None:
        pdf_instructions = self.isa_pdf.get_instructions_dict()

        existing_instructions = {
            instruction.get_mnemonic()
            for instructions_by_format in self.instructions_dict.values()
            for instruction in instructions_by_format
        }

        for pdf_instruction_mnemonic, pdf_instruction_details in pdf_instructions.items():
            if pdf_instruction_mnemonic not in existing_instructions:
                print(f"No match found for {pdf_instruction_mnemonic} "
                    f"({pdf_instruction_details[ISA_Pdf.OPCODE.value]}/"
                    f"{pdf_instruction_details[ISA_Pdf.FORMAT.value]})")

                new_instruction = Instruction(mnemonic=pdf_instruction_details[ISA_Pdf.INSTRUCTIONS.value], 
                                              format=self.isa_pdf.get_format_dict()[pdf_instruction_details[ISA_Pdf.FORMAT.value]], 
                                              type=None, 
                                              opcode=pdf_instruction_details[ISA_Pdf.OPCODE.value],
                                              operand_list=[], 
                                              modifier_list=[],
                                              note=(f"Instruction exists in {self.isa_name} documentation but "
                                                    f"not in LLVM documentation ({self.isa_llvm_urls})"))   
                self.instructions_dict[pdf_instruction_details[ISA_Pdf.FORMAT.value]].append(new_instruction)

    def to_csv(self, csv_path: str) -> None:
        header = [["FORMAT","ENCODING","OPCODE","INSTRUCTIONS","OPERAND0","OPERAND1","OPERAND2","OPERAND3","OPERAND4","MODIFIER0","MODIFIER1","MODIFIER2","MODIFIER3","MODIFIER4","NOTE"]]
        with open(csv_path, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            csv_writer.writerows(header)
            for _, instructions in self.instructions_dict.items() :
                for instruction in instructions :
                    operands_name = [operand.get_name() for operand in instruction.get_operand_list()]
                    operands_name.extend([''] * (5 - len(operands_name)))
                    modifier_name = instruction.get_modifier_list()
                    modifier_name.extend([''] * (5 - len(modifier_name)))
                    row = [[
                        instruction.get_format().name,
                        instruction.get_encoding_string(),
                        instruction.get_opcode (),
                        instruction.get_mnemonic()
                        ] + operands_name + modifier_name + [
                        instruction.get_note()
                    ]]
                    csv_writer.writerows(row)


#     def get_encoding_of(self, type, encoding_list):
#         for row in encoding_list:
#             if row[0] == type:
#                 return row
#         return None 

#     def get_size_of(self, encoding, field) :
#         size_start = -1
#         size_end = -1
#         if field in encoding :
#             size_range = encoding[encoding.index(field)+1]
#             if re.search(r"^\[(\d+)\]$|^\[(\d+):(\d+)\]$", size_range) :
#                 match = re.search(r"^\[(\d+)", size_range)
#                 if match :
#                     size_end = int(match.group(1))
                    
#                 match = re.search(r"(\d+)\]$", size_range)
#                 if match :
#                     size_start = int(match.group(1))
#         return size_end - size_start + 1

#     def set_binary_string(self, isa_instructions_list_from_pdf) :
#         encoding_list = self.isa_pdf.get_type_encoding()
#         for instruction in isa_instructions_list_from_pdf[1:] :
#             type = instruction[0]
#             encoding_bis = ''
#             match = re.match(r"(.*):(.*)", type)
#             if match :
#                 type = match.group(1)
#                 if type == 'VOPC' :
#                     encoding_bis = self.get_encoding_of(match.group(2)+'B', encoding_list)[3][32:]
#                 else :
#                     encoding_bis = self.get_encoding_of(match.group(2), encoding_list)[3][32:]
#             encoding = self.get_encoding_of(type, encoding_list)
#             binary_string = encoding[3] + encoding_bis

#             try :
#                 binary_string = binary_string.replace('ENCODING.', encoding[2]+".")
#                 binary_string = binary_string.replace('OP.', bin(int(instruction[1]))[2:].zfill(self.get_size_of(encoding, 'OP'))+".")
#                 binary_string = binary_string.replace('reserved', "0".zfill(self.get_size_of(encoding, 'reserved')))
#                 instruction[2] = binary_string
#             except :
#                 pass

