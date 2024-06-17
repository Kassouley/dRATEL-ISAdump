from src.InstructionData.Operand import Operand
from src.InstructionData.Format import Format

class Instruction:
    def __init__(self, mnemonic: str, type: str, 
                 operand_list: list[Operand], modifier_list: list[str], 
                 format: Format = None, format_suffix: Format = None, 
                 opcode: str = 'N/A', note: str = '') -> None:
        
        self.mnemonic: str = mnemonic
        self.format: Format = format
        self.format_suffix: Format = format_suffix
        self.type: str = type
        self.opcode: str = opcode
        self.operand_list: list[Operand] = operand_list
        self.modifier_list: list[str] = modifier_list
        self.note: str = note
        self.encoding_string: str = "N/A"

    def get_mnemonic(self) -> str:
        return self.mnemonic.upper()

    def get_format(self) -> Format:
        return self.format
    
    def get_format_name(self) -> str:
        format_name = self.format.name
        if self.format_suffix != None :
            format_name = f"{format_name}:{self.format_suffix.name}"
        return format_name
    
    def get_format_suffix(self) -> Format:
        return self.format_suffix

    def get_type(self) -> str:
        return self.type

    def get_opcode(self) -> str:
        return self.opcode

    def get_operand_list(self) -> list[Operand]:
        return self.operand_list

    def get_modifier_list(self) -> list[str]:
        return self.modifier_list

    def get_encoding_string(self) -> str:
        binary_string = self.encoding_string
        try :
            binary_string = binary_string.replace('ENCODING', self.format.binary_encoding)
        except :
            pass
        try :
            binary_string = binary_string.replace('OP', bin(int(self.opcode))[2:].zfill(self.format.field_dict['OP']['size']))
        except :
            pass
        try :
            binary_string = binary_string.replace('reserved', "0".zfill(self.format.field_dict['reserved']['size']))
        except :
            pass
        try :
            if self.format_suffix.name == 'SDWA' or self.format_suffix.name == 'SDWAB' :
                binary_string = binary_string.replace('SRC0', bin(249)[2:].zfill(self.format.field_dict['SRC0']['size']),1)
            
            if self.format_suffix.name == 'DPP' :
                binary_string = binary_string.replace('SRC0', bin(250)[2:].zfill(self.format.field_dict['SRC0']['size']),1)
        except :
            pass
        return binary_string

    def get_note(self) -> str:
        return self.note

    def set_mnemonic(self, mnemonic: str) -> None:
        self.mnemonic = mnemonic

    def set_format(self, format: Format) -> None:
        self.format = format
        self.set_encoding_string()

    def set_format_suffix(self, format_suffix: Format) -> None:
        self.format_suffix = format_suffix
        self.set_encoding_string()

    def set_type(self, type: str) -> None:
        self.type_ = type

    def set_opcode(self, opcode: str) -> None:
        self.opcode = opcode

    def set_operand_list(self, operand_list: list[Operand]) -> None:
        self.operand_list = operand_list

    def set_modifier_list(self, modifier_list: list[str]) -> None:
        self.modifier_list = modifier_list

    def set_encoding_string(self) -> None:
        if self.format != None : 
            self.encoding_string = self.format.encoding_string
        if self.format_suffix != None :
            self.encoding_string = self.encoding_string + self.format_suffix.encoding_string[32:]

    def set_note(self, note: str) -> None:
        self.note = note