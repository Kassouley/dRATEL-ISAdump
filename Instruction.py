from utils import *
import re

class Operand : 
    def __init__(self, name, type, role, is_optional, is_modifiable, can_be_dst, href_id, href_url, size, op) :
        self.name = name
        self.type = type
        self.role = role
        self.is_optional = is_optional
        self.is_modifiable = is_modifiable
        self.can_be_dst = can_be_dst
        self.id = href_id
        self.url = href_url
        self.size = size
        self.operands = op
    
    def get_name(self):
        return self.name

    def get_type(self):
        return self.type

    def get_role(self):
        return self.role

    def get_is_optional(self):
        return self.is_optional

    def get_is_modifiable(self):
        return self.is_modifiable

    def get_can_be_dst(self):
        return self.can_be_dst

    def get_id(self):
        return self.id

    def get_url(self):
        return self.url

    def get_size(self):
        return self.size

    def get_operands(self):
        return self.operands




class Type :
    def __init__(self, type_name, encoding, field_dict, size) :
        self.type_name = type_name
        self.encoding = encoding
        self.size = size
        self.field_dict = field_dict

    def get_encoding(self) :
        return self.encoding
    
    def get_field_dict(self) :
        return self.field_dict
    
    def get_type_name(self) :
        return self.type_name
    
    def get_size(self) :
        return self.size
    
    def get_encoding_string(self):
        def remove_duplicates_preserve_order(lst):
            seen = set()
            seen_add = seen.add
            result = []
            for x in lst:
                if x == "-" or x not in seen:
                    result.append(x)
                    seen_add(x)
            return result
        
        def concatenate_elements(lst):
            result = []
            i = 0
            while i < len(lst):
                if lst[i] == "-":
                    dashes = []
                    while i < len(lst) and lst[i] == "-":
                        dashes.append(lst[i])
                        i += 1
                    result.append("".join(dashes))
                else:
                    result.append(lst[i])
                    i += 1
            return ".".join(result)
    
        encoding_array = ['-'] * self.size
        for field, dic in self.field_dict.items() :
            pos = [int(num) for num in re.findall(r'\d+', dic['bits'])]
            if len(pos) == 1:
                pos.append(pos[0])
            for i in range(pos[1],pos[0]+1) :
                encoding_array[i] = field

        segmented_processed_lists = []
    
        for i in range(0, len(encoding_array), 32):
            segment = encoding_array[i:i + 32]
            reversed_segment = segment[::-1]
            unique_segment = remove_duplicates_preserve_order(reversed_segment)
            concatenated_segment = concatenate_elements(unique_segment)
            segmented_processed_lists.append(concatenated_segment)
        
        encoding_string = "  ".join(segmented_processed_lists)

        return encoding_string




class DoubleType :
    def __init__(self, type_principal, type_suffix) :
        self.type_principal = type_principal
        self.type_suffix = type_suffix
    
    def get_encoding(self) :
        return self.type_principal.get_encoding()
    
    def get_size(self) :
        return self.type_principal.get_size() + self.type_suffix.get_size()
    
    def get_type_name(self) :
        return self.type_principal.get_type_name()+":"+self.type_suffix.get_type_name()

    def get_field_dict(self) :
        return merge_dicts(self.type_principal.get_field_dict(),self.type_suffix.get_field_dict())
    
    def get_encoding_string(self):
        return self.type_principal.get_encoding_string() + "" + self.type_suffix.get_encoding_string()[32:]

class Instruction :
    def __init__(self, instruction, type, operand_type, operand_list, modifier_list, opcode='N/A', encoding_string='N/A', note='') :
        self.instruction = instruction
        self.type_str = type
        self.operand_type = operand_type
        self.opcode = opcode
        self.operand_list = operand_list
        self.modifier_list = modifier_list
        self.encoding_string = encoding_string
        self.note = note
        
    def set_type_str(self, type_str) :
        self.type_str = type_str
        
    def set_opcode(self, opcode) :
        self.opcode = opcode
        
    def set_note(self, note) :
        self.note = note

    def set_encoding_string(self, encoding_string) :
        self.encoding_string = encoding_string

    def get_instruction(self) :
        return self.instruction
    
    def get_type_str(self) :
        return self.type_str

    def get_operand_type(self) :
        return self.operand_type
    
    def get_opcode(self) :
        return self.opcode
    
    def get_encoding_string(self) :
        return self.encoding_string

    def get_operand_list(self) :
        return self.operand_list
    
    
    def get_operand_name_list(self) :
        operand_list = []
        for e in self.operand_list :
            operand_list.append(e.get_name())
        for i in range(5-len(self.operand_list)) :
            operand_list.append('')
        return operand_list
    
    def get_modifier_list(self) :
        modifier_list = []
        for e in self.modifier_list :
            modifier_list.append(e)
        for i in range(5-len(self.modifier_list)) :
            modifier_list.append('')
        return modifier_list

    def get_note(self) :
        return self.note
    
    def get_instruction_name_mangled(self) :
        match1 = re.search(r"^(.*)(?:_E32|_E64|_DPP|_SDWA)$", self.instruction)
        match2 = re.search(r"^(.*)(?:_E64_DPP)$", self.instruction)
        if match2 : 
            instruction_name = match2.group(1)
        elif match1 :
            instruction_name = match1.group(1)
        else :
            instruction_name = self.instruction
        return instruction_name
