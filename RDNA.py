from InstructionSet import *
import re

class RDNA1(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "RDNA1"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX10.html"
            ]
        self.pdf_range_page =  range(251,297)
        self.is_double_optable = True
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)

    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation', 'Opcode Offset', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                        'SOP2': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },     
                        'SOPK':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
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
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        },   
                        'SMEM':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP2':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        }, 
                        'VOP1':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 3 }  
                        }, 
                        'VOPC': {
                            'COMPAR' : { 'tab' : [COMPAR], '#' : 2 },
                            'FIELD' : { 'tab' : [FIELD], '#' : 1 } ,
                            'INST': { 'tab' : [INST], '#' : 4 },
                        },
                        'VOP3A': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        },  
                        'VOP3B': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP3P': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'SDWA': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                        }, 
                        'SDWAB': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                        }, 
                        'DPP16': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 1},
                        },
                        'DPP8': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
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
                            'INST' : { 'tab': [INST],  '#' : 3},
                        },
                        'MTBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 1},
                        },
                        'MUBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'MIMG': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        }, 
                        'FLAT': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 5},
                        },
                        'EXP': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                        }, 
                    }

def set_correct_type(self, instruction, pdf_instruction_type=None) :
        if instruction.get_type() == 'VOP3' and instruction.get_instruction() in  ["V_ADD_CO_U32", "V_SUB_CO_U32", "V_SUBREV_CO_U32", "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"] :
            instruction.set_type('VOP3B')
        
        elif re.match(r"^(.*)_E64$", instruction.get_instruction()) or instruction.get_type() == 'VOP3':
            instruction.set_type('VOP3A')
        
        elif instruction.get_type() == 'DPP8' or instruction.get_type() == 'DPP16' : 
            instruction.set_type(pdf_instruction_type+":"+instruction.get_type())
            
        elif instruction.get_type() == 'SDWA':
            if pdf_instruction_type == 'VOPC' :
                instruction.set_type(pdf_instruction_type+":SDWAB")
            else: 
                instruction.set_type(pdf_instruction_type+":SDWA")

class RDNA2(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "RDNA2"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX1030.html"
            ]
        self.pdf_range_page =  range(245,291)
        self.is_double_optable = True
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)

    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation', 'Opcode Offset', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                        'SOP2': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },     
                        'SOPK':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
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
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        },   
                        'SMEM':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP2':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        }, 
                        'VOP1':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 3 }  
                        }, 
                        'VOPC': {
                            'COMPAR' : { 'tab' : [COMPAR], '#' : 2 },
                            'FIELD' : { 'tab' : [FIELD], '#' : 1 } ,
                            'INST': { 'tab' : [INST], '#' : 4 },
                        },
                        'VOP3A': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        },  
                        'VOP3B': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP3P': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'SDWA': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                        }, 
                        'SDWAB': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                        }, 
                        'DPP16': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 1},
                        },
                        'DPP8': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
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
                            'INST' : { 'tab': [INST],  '#' : 3},
                        },
                        'MTBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 1},
                        },
                        'MUBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'MIMG': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 3},
                        }, 
                        'FLAT': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 5},
                        },
                        'EXP': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                        }, 
                    }

def set_correct_type(self, instruction, pdf_instruction_type=None) :
        if instruction.get_type() == 'VOP3' and instruction.get_instruction() in  ["V_ADD_CO_U32", "V_SUB_CO_U32", "V_SUBREV_CO_U32", "V_DIV_SCALE_F32", "V_DIV_SCALE_F64", "V_MAD_U64_U32", "V_MAD_I64_I32"] :
            instruction.set_type('VOP3B')
        
        elif re.match(r"^(.*)_E64$", instruction.get_instruction()) or instruction.get_type() == 'VOP3':
            instruction.set_type('VOP3A')
        
        elif instruction.get_type() == 'DPP8' or instruction.get_type() == 'DPP16' : 
            instruction.set_type(pdf_instruction_type+":"+instruction.get_type())
            
        elif instruction.get_type() == 'SDWA':
            if pdf_instruction_type == 'VOPC' :
                instruction.set_type(pdf_instruction_type+":SDWAB")
            else: 
                instruction.set_type(pdf_instruction_type+":SDWA")
                
class RDNA3(InstructionSet) :
    def __init__(self, isa_pdf_path):
        self.isa_name = "RDNA3"
        self.isa_llvm_urls = [
            "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX11.html"
            ]
        self.pdf_range_page =  range(152,195)
        self.is_double_optable = True
        super().__init__(self.isa_name, self.isa_llvm_urls, isa_pdf_path, self.pdf_range_page, self.is_double_optable)

    def get_pdf_table_format(self) :
        COMPAR = ['Compare Operation', 'Opcode Offset', 'Description']
        FIELD = ['Field Name', 'Bits', 'Format or Description']
        INST = ['INSTRUCTIONS', "OPCODE", "TYPE"]
        DPP_CNTL = ['DPP_Cntl', 'Hex', 'Function', 'Description']
        return {
                        'SOP2': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },     
                        'SOPK':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },   
                        'SOP1':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 2 }  
                        },   
                        'SOPC':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        }, 
                        'SOPP':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },   
                        'SMEM':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP2':{
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
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
                        'VOP3': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 1 },
                            'INST' : { 'tab': [INST], '#' : 6 }  
                        },  
                        'VOP3SD': {
                            'FIELD' : { 'tab' : [FIELD], '#'  : 2 },
                            'INST' : { 'tab': [INST], '#' : 1 }  
                        },  
                        'VOP3P': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 1},
                        },
                        'VOPDX': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 1},
                        },
                        'VOPDY': {
                            'INST' : { 'tab': [INST],  '#' : 1},
                        },
                        'DPP16': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'DPP_CNTL' : { 'tab': [DPP_CNTL],  '#' : 1},
                        },
                        'DPP8': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                        }, 
                        'VINTERP': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST'  : { 'tab' : [INST], '#' : 1}
                        },
                        'LDSDIR': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST,
                                               ["LDS_DIRECT_LOAD", "0", "LDSDIR"],
                                               ["LDS_PARAM_LOAD", "1", "LDSDIR"]
                                            ],  '#' : 0},
                        },
                        'DS': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST'  : { 'tab' : [INST], '#' : 2}
                        },
                        'MTBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'MUBUF': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        },
                        'MIMG': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 2},
                        }, 
                        'FLAT': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 2},
                            'INST' : { 'tab': [INST],  '#' : 4},
                        },
                        'EXP': {
                            'FIELD' : { 'tab' : [FIELD], '#' : 1},
                        }, 
                    }

    def set_correct_type(self, instruction, pdf_instruction_type=None) :
        if instruction.get_instruction() in  ["V_ADD_CO_CI_U32", "V_MAD_U64_U32", "V_SUB_CO_CI_U32" "V_MAD_I64_I32", "V_SUBREV_CO_CI_U32" "V_ADD_CO_U32", "V_DIV_SCALE_F32" "V_SUB_CO_U32", "V_DIV_SCALE_F64" "V_SUBREV_CO_U32"] :
            instruction.set_type('VOP3SD')

        elif instruction.get_type() == "FLAT GLOBAL" or instruction.get_type() == "FLAT SCRATCH" :
            instruction.set_type('FLAT')

        elif re.match(r"^.* .*$", instruction.get_type()):
            instruction.set_type(instruction.get_type().replace(" ",":"))