from ..ISA.InstructionSet import InstructionSet
from ..InstructionData.Instruction import Instruction
from ..InstructionData.Format import Format

class CDNA(InstructionSet) :
    def __init__(self, isa_name: str, isa_llvm_urls: list[str] | str, 
                 isa_pdf_path: str, pdf_range_page: range, is_double_optable: bool):
            super().__init__(isa_name, isa_llvm_urls, isa_pdf_path, pdf_range_page, is_double_optable)

    def set_correct_opcode(self, instruction: Instruction, instruction_format_str: str, instruction_former_format_str: str) :
        if not instruction_format_str or not instruction_former_format_str:
            return
        if instruction_format_str == 'VOP3' and instruction_former_format_str == 'VOP1' :
            instruction.set_opcode(instruction.get_opcode() + 0x140)
        elif instruction_format_str == 'VOP3' and instruction_former_format_str == 'VOP2' :
            instruction.set_opcode(instruction.get_opcode() + 0x100)

    def set_correct_format(self, instruction: Instruction, instruction_format_str: str) :

        instruction_mnemonic = instruction.get_mnemonic()
        new_format = instruction_format_str
        new_suffix_format = ""

        vop3b_instructions = {
            "V_ADD_CO_U32_E64", "V_SUB_CO_U32_E64", "V_SUBREV_CO_U32_E64",
            "V_ADDC_CO_U32_E64", "V_SUBB_CO_U32_E64", "V_SUBBREV_CO_U32_E64",
            "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"
        }

        if instruction_format_str == 'VOP3' and instruction_mnemonic in vop3b_instructions:
            new_format ='VOP3B'
        elif instruction_mnemonic.endswith('_E64') or instruction_format_str == 'VOP3':
            new_format = 'VOP3A'
        elif instruction_mnemonic.endswith('_DPP'):
            new_suffix_format = 'DPP'
        elif instruction_mnemonic.endswith('_SDWA'):
            if instruction_format_str == 'VOPC' :
                new_suffix_format = 'SDWAB'
            else :
                new_suffix_format = 'SDWA'
        elif instruction_format_str == 'VOP3P' and instruction.get_opcode():
            new_format = 'VOP3P-MAI' if instruction.get_opcode() >= 64 else 'VOP3P'

        instruction.set_format(self.format_dict.get(new_format, Format(new_format, None, None, None)))
        instruction.set_format_suffix(self.format_dict.get(new_suffix_format, None))