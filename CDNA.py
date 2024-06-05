import re
from InstructionSet import *


class CDNA1(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "CDNA1"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX9.html",
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX908.html"
            ]
        self.pdf_range_page = range(218,283)
        self.is_double_optable = False
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)

    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation Opcode', 'Unnamed: 0', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                'SOP2': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },     
                'SOPK':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },   
                'SOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                },   
                'SOPC':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                }, 
                'SOPP':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },   
                'SMEM':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 4 }  
                },  
                'VOP2':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                }, 
                'VOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                }, 
                'VOPC': {
                    'COMPAR' : { 'tab' : [COMPAR], '#' : 2 },
                    'FIELD' : { 'tab' : [FIELD], '#' : 1 } ,
                    'INST': { 'tab' : [INST], '#' : 7 },
                },
                'VOP3A': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 4 }  
                },  
                'VOP3B': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },  
                'VOP3P': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                },
                'VOP3P-MAI': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 3},
                },
                'SDWA': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                }, 
                'SDWAB': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                }, 
                'DPP': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 1},
                },
                'VINTRP': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST'  : { 'tab' : [INST,
                                            ["V_INTERP_P1_F32","0","VINTRP"],
                                            ["V_INTERP_P2_F32","1","VINTRP"],
                                            ["V_INTERP_MOV_F32","2","VINTRP"]
                                        ], '#' : 0}
                },
                'DS': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 5},
                },
                'MTBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 1},
                },
                'MUBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 3},
                },
                'MIMG': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 3},
                }, 
                'FLAT': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 6},
                }
            }

    def set_correct_type(self, instruction, pdf_instruction_type=None) :
        new_type = instruction.get_type_str()
        if instruction.get_type_str() == 'VOP3' and instruction.get_instruction() in ["V_ADD_CO_U32_E64", "V_SUB_CO_U32_E64", "V_SUBREV_CO_U32_E64", "V_ADDC_CO_U32_E64", "V_SUBB_CO_U32_E64", "V_SUBBREV_CO_U32_E64", "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"] :
            new_type = 'VOP3B'
        elif re.match(r"^(.*)_E64$", instruction.get_instruction()) or instruction.get_type_str() == 'VOP3':
            new_type = 'VOP3A'
        elif re.match(r"^(.*)_DPP$", instruction.get_instruction()) :
           new_type = instruction.get_type_str()+":DPP"
        elif re.match(r"^(.*)_SDWA$", instruction.get_instruction()) :
            new_type = instruction.get_type_str()+":SDWA"
        elif instruction.get_type_str() == 'VOP3P' and instruction.get_opcode() != "N/A" :
            if int(instruction.get_opcode()) >= 64 :
                new_type = 'VOP3P-MAI'
            else :
                new_type = 'VOP3P'
        instruction.set_type_str(new_type)

class CDNA2(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "CDNA2"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
            ]
        self.pdf_range_page =  range(212,275)
        self.is_double_optable = False
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)
    
    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation Opcode', 'Unnamed: 0', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                'SOP2': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },     
                'SOPK':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },   
                'SOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                },   
                'SOPC':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                }, 
                'SOPP':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 1 }  
                },   
                'SMEM':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 4 }  
                },  
                'VOP2':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                }, 
                'VOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 3 }  
                }, 
                'VOPC': {
                    'COMPAR' : { 'tab' : [COMPAR], '#' : 2 },
                    'FIELD' : { 'tab' : [FIELD], '#' : 1 } ,
                    'INST': { 'tab' : [INST], '#' : 7 },
                },
                'VOP3A': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 4 }  
                },  
                'VOP3B': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },  
                'VOP3P': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                },
                'VOP3P-MAI': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 3},
                },
                'SDWA': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                }, 
                'SDWAB': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                }, 
                'DPP': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 2},
                },
                'DS': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 5},
                },
                'MTBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 1},
                },
                'MUBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 3},
                },
                'MIMG': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 1},
                }, 
                'FLAT': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 7},
                }
            }
 
    def set_correct_type(self, instruction, pdf_instruction_type=None) :
        new_type = instruction.get_type_str()
        if instruction.get_type_str() == 'VOP3' and instruction.get_instruction() in ["V_ADD_CO_U32_E64", "V_SUB_CO_U32_E64", "V_SUBREV_CO_U32_E64", "V_ADDC_CO_U32_E64", "V_SUBB_CO_U32_E64", "V_SUBBREV_CO_U32_E64", "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"] :
            new_type = 'VOP3B'
        elif re.match(r"^(.*)_E64$", instruction.get_instruction()) or instruction.get_type_str() == 'VOP3':
            new_type = 'VOP3A'
        elif re.match(r"^(.*)_DPP$", instruction.get_instruction()) :
           new_type = instruction.get_type_str()+":DPP"
        elif re.match(r"^(.*)_SDWA$", instruction.get_instruction()) :
            new_type = instruction.get_type_str()+":SDWA"
        elif instruction.get_type_str() == 'VOP3P' and instruction.get_opcode() != "N/A" :
            if int(instruction.get_opcode()) >= 64 :
                new_type = 'VOP3P-MAI'
            else :
                new_type = 'VOP3P'
        instruction.set_type_str(new_type)
  
class CDNA3(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "CDNA3"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX940.html"
            ]
        self.pdf_range_page =  range(513,553)
        self.is_double_optable = True
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)
      
    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation Opcode', 'Unnamed: 0', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                'SOP2': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },     
                'SOPK':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 1 }  
                },   
                'SOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },   
                'SOPC':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                }, 
                'SOPP':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 1 }  
                },   
                'SMEM':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                },  
                'VOP2':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                }, 
                'VOP1':{
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 2 }  
                }, 
                'VOPC': {
                    'COMPAR' : { 'tab' : [COMPAR], '#' : 1 },
                    'FIELD' : { 'tab' : [FIELD], '#' : 1 } ,
                    'INST': { 'tab' : [INST], '#' : 3 },
                },
                'VOP3A': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                    'INST' : { 'tab': [INST], '#' : 6 }  
                },  
                'VOP3B': {
                    'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                    'INST' : { 'tab': [INST], '#' : 1 }  
                },  
                'VOP3P': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                },
                'VOP3P-MAI': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 2},
                },
                'SDWA': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                }, 
                'SDWAB': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                }, 
                'DPP': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 2},
                },
                'DS': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 2},
                },
                'MTBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 1},
                },
                'MUBUF': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 1},
                    'INST' : { 'tab': [INST],  '#' : 2},
                },
                'FLAT': {
                    'FIELD' : { 'tab' : [FIELD], '#' : 2},
                    'INST' : { 'tab': [INST],  '#' : 5},
                }
            }
      
    def set_correct_type(self, instruction, pdf_instruction_type=None) :
        new_type = instruction.get_type_str()
        if instruction.get_type_str() == 'VOP3' and instruction.get_instruction() in ["V_ADD_CO_U32_E64", "V_SUB_CO_U32_E64", "V_SUBREV_CO_U32_E64", "V_ADDC_CO_U32_E64", "V_SUBB_CO_U32_E64", "V_SUBBREV_CO_U32_E64", "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"] :
            new_type = 'VOP3B'
        elif re.match(r"^(.*)_E64$", instruction.get_instruction()) or instruction.get_type_str() == 'VOP3':
            new_type = 'VOP3A'
        elif re.match(r"^(.*)_DPP$", instruction.get_instruction()) :
           new_type = instruction.get_type_str()+":DPP"
        elif re.match(r"^(.*)_SDWA$", instruction.get_instruction()) :
            new_type = instruction.get_type_str()+":SDWA"
        elif instruction.get_type_str() == 'VOP3P' and instruction.get_opcode() != "N/A" :
            if int(instruction.get_opcode()) >= 64 :
                new_type = 'VOP3P-MAI'
            else :
                new_type = 'VOP3P'
        instruction.set_type_str(new_type)