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


class InstructionSet :
    def __init__(self, isa_name: str, isa_llvm_urls: list[str] | str, 
                 isa_pdf_path: str, pdf_pages_range: range, pdf_is_double_optable: bool) -> None:
        
        self.isa_name = isa_name
        self.isa_llvm_urls = isa_llvm_urls
        self.isa_llvm_soup = ISA_Soup(isa_llvm_urls)
        self.isa_pdf = ISA_PDF(isa_pdf_path, self.get_pdf_table_format(), pdf_pages_range, pdf_is_double_optable)
        
        self.instructions_dict_lock = threading.Lock()
        self.instructions_dict: dict[str,list[Instruction]] = {}

    def get_pdf_table_format(self) -> None:
        raise NotImplementedError("This method should be implemented in the subclass")
    
    def set_correct_format(self, instruction, instruction_format_str) -> None :
        raise NotImplementedError("This method should be implemented in the subclass")


    def create_instructions_dict_aux(self, instruction_mnemonic: str, instructions_info: list) :
        instruction_modifier_list = instructions_info.pop()
        instruction_operand_list = instructions_info.pop()
        instruction_type_src = instructions_info.pop()
        instruction_type_dst = instructions_info.pop()
        instruction_mnemonic_mangled = instructions_info.pop().upper()
        instruction_format_str = instructions_info.pop()
        instruction_type = instruction_type_src if instruction_operand_list else "-"
        instruction_note = ''

        pdf_instruction_dict = self.isa_pdf.get_instructions_dict()
        instruction_data = pdf_instruction_dict.get(instruction_mnemonic_mangled)
        if instruction_data:
            instruction_opcode = instruction_data[ISA_Pdf.OPCODE.value]
        else:
            print(f"No opcode found for: {instruction_mnemonic} ({instruction_format_str})")
            instruction_opcode = 'N/A'
            instruction_note = (f"No opcode found. Instruction exists in LLVM documentation "
                                f"({','.join(self.isa_llvm_urls)}) but not in {self.isa_name} documentation")

        # INSTRUCTION CREATION
        instruction = Instruction(mnemonic=instruction_mnemonic.upper(), 
                                  type=instruction_type, 
                                  operand_list=instruction_operand_list, 
                                  modifier_list=instruction_modifier_list,
                                  opcode=instruction_opcode,
                                  note=instruction_note)
                                  
        self.set_correct_format(instruction, instruction_format_str)
        
        # INSTRUCTION ATOMIC ADD TO DIC
        with self.instructions_dict_lock:
            instruction_format_name = instruction.get_format_name()
            if instruction_format_name not in self.instructions_dict:
                self.instructions_dict[instruction_format_name] = []
            self.instructions_dict[instruction_format_name].append(instruction)

    def create_instructions_dict(self) -> None :
        self.isa_llvm_soup.create_instruction_dict()
        self.isa_pdf.scrape_tables_from_pdf()
        self.isa_pdf.create_format_dict()
        self.isa_pdf.create_instructions_dict()
        isa_llvm_soup_instruction_dict = self.isa_llvm_soup.get_instruction_dict()

        threads = []
        for instruction_mnemonic, instructions_info in isa_llvm_soup_instruction_dict.items() :
            # self.create_instructions_dict_aux(instruction_mnemonic, instructions_info)
            t = threading.Thread(target=self.create_instructions_dict_aux, args=(instruction_mnemonic, instructions_info,))
            threads.append(t)
            t.start()

        for t in threads:
            t.join()

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
                        instruction.get_format_name(),
                        instruction.get_encoding_string(),
                        instruction.get_opcode (),
                        instruction.get_mnemonic()
                        ] + operands_name + modifier_name + [
                        instruction.get_note()
                    ]]
                    csv_writer.writerows(row)