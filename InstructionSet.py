import re
from ISA_Soup import *
from ISA_PDF import *
from utils import *
from Instruction import Instruction
from enumeration import *
import threading

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
SIZE_SUFFIX_CORRESPONDING= [
    "b64", "b96", "b128", "b256", "b512",
    "b32", "b64", "b96", "b128",
    "b16", "b16x2", "b16x3", "b16x4",
    "b16", "b16x2", "b16x3", "b16x4"
]
ENCODING_SUFFIX = ['e32', 'e64', 'dpp', 'sdwa', 'e64_dpp']

class InstructionSet :
    def __init__(self, isa_name, isa_llvm_urls, isa_pdf_path, pdf_pages_range, pdf_is_double_optable):
        self.isa_name = isa_name
        self.isa_llvm_urls = isa_llvm_urls
        self.isa_llvm_soups = ISA_SOUPS(isa_llvm_urls)
        self.isa_pdf = ISA_PDF(isa_pdf_path, self.get_pdf_table_format(), pdf_pages_range, pdf_is_double_optable)
        
        self.instructions_dic_lock = threading.Lock()
        self.href_save_dic_lock = threading.Lock()
        self.instructions_dic = {}
        self.href_save_dic = {}

    def get_pdf_table_format(self) :
        raise NotImplementedError("This method should be implemented in the subclass")
    
    def set_correct_type(self, instruction, pdf_instruction_type=None) :
        raise NotImplementedError("This method should be implemented in the subclass")

    def get_operand_info(self, url) :
        new_url = "https://llvm.org/docs/AMDGPU/"+url
        op_soup = get_soup_from_request_http(new_url)
        op_section = op_soup.find('section')
        informations = {'url': new_url, 'size': 'No size found', 'op': 'No operand found'}
        lines = op_section.get_text().split('\n')[1:]
        for line in lines:
                if 'Size:' in line:
                    informations['size'] = line.split(':', 1)[1].strip()
                elif 'Operands:' in line:
                    informations['op'] = line.split(':', 1)[1].strip()
        return informations

    def create_instructions_dic_aux(self, instruction_line, instruction_type) :
        def parse_instruction_suffix(input_str):
            base_str = input_str
            type_suffix_src = 'b32'
            type_suffix_dst = None
            encoding_suffix = None
            for enc_suffix in ENCODING_SUFFIX:
                if input_str.endswith(enc_suffix):
                    encoding_suffix = enc_suffix
                    base_str = input_str[:-len(enc_suffix)-1]
                    break
            if base_str.endswith('_'):
                base_str = base_str[:-1]
                
            for type_suf in SIZE_SUFFIX :
                if base_str.endswith(type_suf):
                    type_suffix_src = SIZE_SUFFIX_CORRESPONDING[SIZE_SUFFIX.index(type_suf)]
                    base_str = base_str[:-len(type_suf)]
                    break
            if base_str.endswith('_'):
                base_str = base_str[:-1]

            for type_suf in TYPE_SUFFIX:
                if base_str.endswith(type_suf):
                    type_suffix_src = type_suf
                    base_str = base_str[:-len(type_suf)]
                    break
            if base_str.endswith('_'):
                base_str = base_str[:-1]

            for type_suf in TYPE_SUFFIX :
                if base_str.endswith(type_suf):
                    type_suffix_dst = type_suf
                    base_str = base_str[:-len(type_suf)]
                    break
            if base_str.endswith('_'):
                base_str = base_str[:-1]

            return base_str, type_suffix_dst, type_suffix_src, encoding_suffix
        
        instruction_name = instruction_line.pop(0)
        instruction_name_wo_suffix, type_suffix_dst, type_suffix_src, instruction_encoding_suffix = parse_instruction_suffix(instruction_name)
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
                operand_type = type_suffix_src
                if operand_role == 'SRC' :
                    operand_type = type_suffix_src
                elif operand_role == 'DST' :
                    operand_type = type_suffix_dst    
                operand_href = argument_split.pop()
                operand_is_optional = False
                operand_is_modifiable = False
                operand_can_be_dst = False
                while argument_split :
                    e = argument_split.pop()
                    if e == 'opt' :
                        operand_is_optional = True
                    elif e == 'm' :
                        operand_is_modifiable = True
                    elif e == 'dst' :
                        operand_can_be_dst = True
                    elif e in TYPE_SUFFIX :
                        operand_type=e
                    else :
                        print(f"Operand information '{e}' not known for '{operand_name}'")


                if operand_href not in self.href_save_dic :
                    tmp = self.get_operand_info(operand_href)
                # with self.href_save_dic_lock :
                if operand_href not in self.href_save_dic :
                    self.href_save_dic[operand_href] = tmp
                # with self.href_save_dic_lock :
                #     if href not in self.href_save_dic :
                #         self.href_save_dic[href] = self.get_operand_info(href)

                href_id = operand_href   
                match = re.search(r'^(.*?)\.html', operand_href)
                if match:
                    href_id = match.group(1)

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

        if not instruction_operand_list :
            instruction_operand_type = "-"
        else :
            instruction_operand_type = type_suffix_src

        # INSTRUCTION CREATION
        instruction = Instruction(instruction=instruction_name.upper(), 
                                  type=instruction_type.upper(), 
                                  operand_type=instruction_operand_type,
                                  operand_list=instruction_operand_list, 
                                  modifier_list=instruction_modifier_list) 
        
        # OPCODE AND TYPE SET
        pdf_instruction_dic = self.isa_pdf.get_instructions_dic()
        instruction_name_mangled = instruction.get_instruction_name_mangled()
        if instruction_name_mangled in pdf_instruction_dic :
            instruction.set_opcode(pdf_instruction_dic[instruction_name_mangled][ISA_Pdf.OPCODE.value])

            self.set_correct_type(instruction, pdf_instruction_dic[instruction_name_mangled][ISA_Pdf.TYPE.value])

            type_obj = self.isa_pdf.get_type_encoding_of(instruction.get_type_str())
            instruction.set_encoding_string(type_obj.get_encoding_string())
        else :
            print(f"No opcode found for : {instruction.get_instruction()} ({instruction.get_type_str()})")
            instruction.set_encoding_string("N/A")
            instruction.set_note(f"No opcode found. Instruction exists in LLVM documentation ({self.isa_llvm_urls}) but not in {self.isa_name} documentation")

        # INSTRUCTION ATOMIC ADD TO DIC
        # with self.instructions_dic_lock :
        if instruction.get_type_str() not in self.instructions_dic :
            self.instructions_dic[instruction.get_type_str()] = []
        self.instructions_dic[instruction.get_type_str()].append(instruction)
            

    def create_instructions_dic(self) :
        section_dic = self.isa_llvm_soups.get_section_dic_by_type()
        threads = []
        for instruction_type, section_list in section_dic.items() :
            for instruction_line in section_list :
                self.create_instructions_dic_aux(instruction_line, instruction_type)
        #         t = threading.Thread(target=self.create_instructions_dic_aux, args=(instruction_line, instruction_type,))
        #         threads.append(t)
        #         t.start()

        # for t in threads:
        #     t.join()

        self.add_no_match_instructions()

    def add_no_match_instructions(self)  :
        pdf_instruction_dic = self.isa_pdf.get_instructions_dic()

        for pdf_instruction_name, pdf_instruction in pdf_instruction_dic.items() :
            match = 0
            for type, instructions_by_type in self.instructions_dic.items() :
                for instruction in instructions_by_type :
                    if instruction.get_instruction() == pdf_instruction_name :
                        match = 1
                        break
                else :
                    continue
                break

            if not match :
                print(f"No match found for {pdf_instruction_name} ({pdf_instruction[ISA_Pdf.OPCODE.value]}/{pdf_instruction[ISA_Pdf.TYPE.value]})")
                new_inst = Instruction(
                    instruction=pdf_instruction[ISA_Pdf.INSTRUCTIONS.value],
                    operand_type=None,
                    opcode=pdf_instruction[ISA_Pdf.OPCODE.value],
                    type=pdf_instruction[ISA_Pdf.TYPE.value],
                    operand_list=[],
                    modifier_list=[],
                    encoding_string=self.isa_pdf.get_type_encoding_of(pdf_instruction[ISA_Pdf.TYPE.value]).get_encoding_string(),
                    note=f"Instruction exists in {self.isa_name} documentation but not in LLVM documentation ({self.isa_llvm_urls})"
                )
                self.instructions_dic[pdf_instruction[ISA_Pdf.TYPE.value]].append(new_inst)

    def to_csv(self, csv_path) :
        header = [["TYPE","ENCODING","OPCODE","INSTRUCTIONS","OPERAND0","OPERAND1","OPERAND2","OPERAND3","OPERAND4","MODIFIER0","MODIFIER1","MODIFIER2","MODIFIER3","MODIFIER4","NOTE"]]
        with open(csv_path, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            csv_writer.writerows(header)
            for type, instructions in self.instructions_dic.items() :
                for instruction in instructions :
                    row = [[
                        instruction.get_type_str(),
                        instruction.get_encoding_string(),
                        instruction.get_opcode (),
                        instruction.get_instruction()] + instruction.get_operand_name_list() + instruction.get_modifier_list() + [
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

