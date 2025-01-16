from ..InstructionData.Modifier import Modifier
from ..InstructionData.Operand import Operand
from ..InstructionData.Format import Format
import re

class Instruction:
    def __init__(self, mnemonic: str, type: str, 
                 operand_list: list[Operand], modifier_list: list[Modifier], 
                 format: Format = None, format_suffix: Format = None, 
                 opcode: str = 'N/O', note: str = '') -> None:
        
        self.mnemonic: str = mnemonic
        self.format: Format = format
        self.format_suffix: Format = format_suffix
        self.type: str = type
        self.opcode: str = opcode
        self.operand_list: list[Operand] = operand_list
        self.modifier_list: list[Modifier] = modifier_list
        self.note: str = note
        self.encoding_string: str = "N/A"

    def get_mnemonic(self) -> str:
        return self.mnemonic.upper()

    def get_format(self) -> Format:
        return self.format
    
    def get_format_name(self) -> str:
        format_name = self.format.get_name()
        if self.format_suffix != None :
            format_name = f"{format_name}:{self.format_suffix.get_name()}"
        return format_name
    
    def get_format_suffix(self) -> Format:
        return self.format_suffix

    def get_type(self) -> str:
        return self.type

    def get_opcode(self) -> int | None:
        if self.opcode != 'N/O': 
            return int(self.opcode)
        return None

    def get_operand_list(self) -> list[Operand]:
        return self.operand_list

    def get_modifier_list(self) -> list[Modifier]:
        return self.modifier_list

    def get_encoding_string(self) -> str:
        binary_string = self.encoding_string
        if hasattr(self.format, 'binary_encoding'):
            binary_string = binary_string.replace('ENCODING', self.format.binary_encoding)
        if 'OP' in self.format.field_dict and self.opcode != 'N/O':
            binary_string = re.sub(r'\bOP\b', bin(int(self.opcode))[2:].zfill(self.format.field_dict['OP']['size']), binary_string)
        if 'reserved' in self.format.field_dict:
            binary_string = binary_string.replace('reserved', "0".zfill(self.format.field_dict['reserved']['size']))
        if 'SRC0' in self.format.field_dict and self.format_suffix:
            if self.format_suffix.get_name() == 'SDWA' or self.format_suffix.get_name() == 'SDWAB' :
                binary_string = binary_string.replace('SRC0', bin(249)[2:].zfill(self.format.field_dict['SRC0']['size']),1)
            
            if self.format_suffix.get_name() == 'DPP' :
                binary_string = binary_string.replace('SRC0', bin(250)[2:].zfill(self.format.field_dict['SRC0']['size']),1)
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

    def set_modifier_list(self, modifier_list: list[Modifier]) -> None:
        self.modifier_list = modifier_list

    def set_encoding_string(self) -> None:
        if self.format != None : 
            self.encoding_string = self.format.encoding_string
        if self.format_suffix != None :
            self.encoding_string = self.encoding_string + self.format_suffix.encoding_string[32:]

    def set_note(self, note: str) -> None:
        self.note = note