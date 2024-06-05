import re
from ISA_Soup import *
from ISA_PDF import *
from utils import *
from Instruction import Instruction
from enumeration import *
import threading

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
        instruction_soup =  BeautifulSoup(instruction_line, 'html.parser')
        instruction_string = instruction_soup.get_text()
        instruction_split = instruction_string.split()
        instruction_name = instruction_split.pop(0)
        
        # OPERANDS & MODFIERS CREATION
        instruction_modifier_list = []
        instruction_operand_list = []
        arguments_list = []
        if len(instruction_split) !=0 :
            arguments_list = " ".join(instruction_split)
            arguments_list = arguments_list.replace(',','')
            arguments_list = arguments_list.split()

        for argument in arguments_list :
            argument_only = argument.split(':')[0].strip()
            tag = instruction_soup.find('a', class_='reference internal', text=argument_only)
            if tag:
                href = tag.get('href')

                if re.search('AMDGPUModifierSyntax', href) :
                    instruction_modifier_list.append(argument)
                else :
                    if href not in self.href_save_dic :
                        tmp = self.get_operand_info(href)
                    with self.href_save_dic_lock :
                        if href not in self.href_save_dic :
                            self.href_save_dic[href] = tmp
                    # with self.href_save_dic_lock :
                    #     if href not in self.href_save_dic :
                    #         self.href_save_dic[href] = self.get_operand_info(href)

                    href_id = href   
                    match = re.search(r'^(.*?)\.html', href)
                    if match:
                        href_id = match.group(1)

                    instruction_operand_list.append(Operand(argument, href_id, self.href_save_dic[href]['url'], self.href_save_dic[href]['size'], self.href_save_dic[href]['op']))
        
        # INSTRUCTION CREATION
        instruction = Instruction(instruction=instruction_name.upper(), 
                                  type=instruction_type.upper(), 
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
        with self.instructions_dic_lock :
            if instruction.get_type_str() not in self.instructions_dic :
                self.instructions_dic[instruction.get_type_str()] = []
            self.instructions_dic[instruction.get_type_str()].append(instruction)
            

    def create_instructions_dic(self) :
        section_dic = self.isa_llvm_soups.get_section_dic_by_type()
        threads = []
        for instruction_type, section_list in section_dic.items() :
            for instruction_line in section_list :
                if not instruction_line.strip():
                    continue 
                t = threading.Thread(target=self.create_instructions_dic_aux, args=(instruction_line, instruction_type,))
                threads.append(t)
                t.start()

        for t in threads:
            t.join()

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

