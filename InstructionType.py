
class InstructionType :
    def __init__(self, type_name, encoding, field_list) :
        self.type_name = type_name
        self.encoding = encoding
        self.field_list_name = field_list[:][0]
        self.field_list_bits = field_list[:][1]
