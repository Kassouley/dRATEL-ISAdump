from enum import Enum

class ISA(Enum):
    TYPE = 0
    OPCODE = 1
    ENCODING = 2
    INSTRUCTIONS = 3
    OPERAND0 = 4
    OPERAND1 = 5
    OPERAND2 = 6
    OPERAND3 = 7
    OPERAND4 = 8
    MODIFIER0 = 9
    MODIFIER1 = 10
    MODIFIER2 = 11
    MODIFIER3 = 12
    MODIFIER4 = 13
    NOTE = 14

class ISA_Soup(Enum):
    TYPE = 0
    INSTRUCTIONS = 1
    OPERAND0 = 2
    OPERAND1 = 3
    OPERAND2 = 4
    OPERAND3 = 5
    OPERAND4 = 6
    MODIFIER0 = 7
    MODIFIER1 = 8
    MODIFIER2 = 9
    MODIFIER3 = 10
    MODIFIER4 = 11

    
class ISA_Pdf(Enum):
    INSTRUCTIONS = 0
    OPCODE = 1
    TYPE = 2
