import threading
import csv
import re
from ..ISA.ISA_Soup import ISA_Soup
from ..ISA.ISA_PDF import ISA_PDF
from ..InstructionData.Format import Format
from ..InstructionData.Instruction import Instruction
from ..utils.utils import *
from ..utils.enumeration import *

class InstructionSet :
    def __init__(self, isa_name: str, isa_llvm_urls: list[str] | str, 
                 isa_pdf_path: str, pdf_pages_range: range, pdf_is_double_optable: bool) -> None:
        
        self.isa_name = isa_name
        self.isa_llvm_urls = isa_llvm_urls
        self.isa_llvm_soup = ISA_Soup(isa_llvm_urls)
        self.isa_pdf = ISA_PDF(isa_pdf_path, self.get_pdf_table_format(), pdf_pages_range, pdf_is_double_optable)
        
        self.instructions_dict_lock = threading.Lock()

        self.instructions_dict: dict[str,list[Instruction]] = {}
        self.format_dict: dict[str,list[Format]] = {}

    def get_pdf_table_format(self) -> None:
        raise NotImplementedError("This method should be implemented in the subclass")
    
    def set_correct_format(self, instruction, instruction_format_str) -> None :
        raise NotImplementedError("This method should be implemented in the subclass")

    def set_correct_opcode(self, instruction: Instruction, instruction_format_str: str, instruction_former_format_str: str) -> None :
        raise NotImplementedError("This method should be implemented in the subclass")

    def set_correct_instruction_mnemonic(self, instruction: Instruction) :
        raise NotImplementedError("This method should be implemented in the subclass")

    def set_corresponding_operand_to_field(self, instruction: Instruction) -> None:
        raise NotImplementedError("This method should be implemented in the subclass")


    def _try_get_special_opcode(self, instruction_mnemonic: str):
        raise NotImplementedError("This method should be implemented in the subclass")

    def create_instructions_dict_aux(self, instruction_mnemonic: str, instructions_info: list) :
        instruction_modifier_list = instructions_info.pop()
        instruction_operand_list = instructions_info.pop()
        instruction_type_src = instructions_info.pop()
        instruction_type_dst = instructions_info.pop()
        instruction_mnemonic_without_suffix = instructions_info.pop().upper()
        instruction_mnemonic_without_suffix = self._get_changed_instruction_mnemonic(instruction_mnemonic_without_suffix)
        instruction_format_str = instructions_info.pop()
        instruction_type = instruction_type_src if instruction_operand_list else "-"
        instruction_note = ''
        instruction_former_format_str = None


        instruction_data = self.isa_pdf.get_data_for(instruction_mnemonic_without_suffix)
        if instruction_data:
            instruction_opcode = instruction_data[ISA_Pdf.OPCODE.value]
            instruction_former_format_str = instruction_data[ISA_Pdf.FORMAT.value]
        else:
            instruction_opcode = self._try_get_special_opcode(instruction_mnemonic)
            if not instruction_opcode :
                print(f"No opcode found for: {instruction_mnemonic} ({instruction_format_str})")
                instruction_opcode = 'N/O'
                instruction_note = (f"No opcode found. Instruction exists in LLVM documentation "
                                    f"({','.join(self.isa_llvm_urls)}) but not in {self.isa_name} documentation")


        # INSTRUCTION CREATION
        instruction = Instruction(mnemonic=instruction_mnemonic.upper(), 
                                #   format=self.format_dict.get(instruction_format_str, None),
                                  type=instruction_type, 
                                  operand_list=instruction_operand_list, 
                                  modifier_list=instruction_modifier_list,
                                  opcode=instruction_opcode,
                                  note=instruction_note)
        
        self.set_correct_opcode(instruction, instruction_format_str, instruction_former_format_str)
        self.set_correct_format(instruction, instruction_format_str)
        self.set_corresponding_operand_to_field(instruction)
        self.set_correct_instruction_mnemonic(instruction)

        
        # INSTRUCTION ATOMIC ADD TO DIC
        with self.instructions_dict_lock:
            instruction_format_name = instruction.get_format_name()
            if instruction_format_name not in self.instructions_dict:
                self.instructions_dict[instruction_format_name] = []
            self.instructions_dict[instruction_format_name].append(instruction)


    def create_instructions_dict(self) -> None :
        self.create_format_dict()
        isa_llvm_soup_instruction_dict = self.isa_llvm_soup.get_instruction_dict()

        threads = []
        for instruction_mnemonic, instructions_info in isa_llvm_soup_instruction_dict.items() :
            t = threading.Thread(target=self.create_instructions_dict_aux, args=(instruction_mnemonic, instructions_info,))
            threads.append(t)
            t.start()

        for t in threads:
            t.join()

        self.add_no_match_instructions()


    def _get_field_name(self, field_dict, format_name, field_data) :
        return field_data[0]

    def create_format_dict(self) -> None:
        self.format_dict = {}
        
        for format_name, sub_dict in self.isa_pdf.get_scraped_data().items():
            field_dict = {}
            for field_data in sub_dict['FIELD']['tab'][1:] :
                field_name = self._get_field_name(field_dict, format_name, field_data)
                if field_name and field_name not in field_dict :
                    numbers = list(map(int, re.findall(r'\d+', field_data[1])))
                    if len(numbers) == 1:
                        bits_size = 1
                    else :
                        bits_size = numbers[-2] - numbers[-1] + 1
                    field_dict[field_name] = {'bits': field_data[1], 'size': bits_size, 'desc': field_data[2]}

            last_field_bits = list(field_dict.values())[-1]['bits']
            encoding_size = int(re.search(r'\[(\d+)', last_field_bits).group(1)) + 1 if last_field_bits else 0
            
            encoding_bits = "".join(re.findall(r'[01]+', field_dict.get('ENCODING', {}).get('desc', '')))
            
            self.format_dict[format_name] = Format(
                name=format_name,
                binary_encoding=encoding_bits,
                field_dict=field_dict,
                size=encoding_size
            )


    def add_no_match_instructions(self) -> None:
        pdf_instructions = self.isa_pdf.get_unmatched_instructions_dict()

        for pdf_instruction_mnemonic, pdf_instruction_details in pdf_instructions.items():
            print(f"No match found for {pdf_instruction_mnemonic} "
                f"({pdf_instruction_details[ISA_Pdf.OPCODE.value]}/"
                f"{pdf_instruction_details[ISA_Pdf.FORMAT.value]})")

            new_instruction = Instruction(mnemonic=pdf_instruction_details[ISA_Pdf.INSTRUCTIONS.value], 
                                            format=self.format_dict[pdf_instruction_details[ISA_Pdf.FORMAT.value]], 
                                            type=None, 
                                            opcode=pdf_instruction_details[ISA_Pdf.OPCODE.value],
                                            operand_list=[], 
                                            modifier_list=[],
                                            note=(f"Instruction exists in {self.isa_name} documentation but "
                                                f"not in LLVM documentation ({self.isa_llvm_urls})"))   
            self.instructions_dict[pdf_instruction_details[ISA_Pdf.FORMAT.value]].append(new_instruction)





    def formats_to_csv(self, csv_path: str) -> None:
        header = [["INSTRUCTION","SIZE","ENCODING","ENCODING_STRING",
                   "FIELD 0","BITS","FIELD 1","BITS","FIELD 2","BITS",
                   "FIELD 3","BITS","FIELD 4","BITS","FIELD 5","BITS",
                   "FIELD 6","BITS","FIELD 7","BITS","FIELD 8","BITS",
                   "FIELD 9","BITS","FIELD 10","BITS","FIELD 11","BITS",
                   "FIELD 12","BITS","FIELD 13","BITS","FIELD 14","BITS",
                   "FIELD 15","BITS","FIELD 16","BITS"]]
        with open(csv_path, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            csv_writer.writerows(header)
            for format in self.format_dict.values():
                csv_writer.writerow(format.to_list())


    def instructions_to_csv(self, csv_path: str) -> None:
        header = [["FORMAT","ENCODING","OPCODE","INSTRUCTIONS","TYPE",
                   "OPERAND0","OPERAND1","OPERAND2","OPERAND3","OPERAND4",
                   "MODIFIER0","MODIFIER1","MODIFIER2","MODIFIER3","MODIFIER4",
                   "MODIFIER5","MODIFIER6","MODIFIER7","NOTE"]]
        with open(csv_path, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            csv_writer.writerows(header)
            for _, instructions in self.instructions_dict.items() :
                for instruction in instructions :
                    operands_field = [
                        f"{op.get_corresponding_field()}:"
                        f"{op.get_name()}:"
                        f"{op.get_role()}:"
                        f"{op.get_type()}:"
                        f"{op.get_size()}:"
                        f"{op.is_vector_or_scalar()}:"
                        f"{'OPT' if op.is_optional() else 'REQ'}"
                        for op in instruction.get_operand_list()
                    ]
                    operands_field.extend([''] * (5 - len(operands_field)))

                    modifier_field = [
                        f"{mod.get_corresponding_field()}:"
                        f"{mod.get_name()}"
                        for mod in instruction.get_modifier_list()
                    ]
                    modifier_field.extend([''] * (8 - len(modifier_field)))
                    row = [[
                        instruction.get_format_name(),
                        instruction.get_encoding_string(),
                        instruction.get_opcode(),
                        instruction.get_mnemonic(),
                        instruction.get_type()
                        ] + operands_field + modifier_field + [
                        instruction.get_note()
                    ]]
                    csv_writer.writerows(row)