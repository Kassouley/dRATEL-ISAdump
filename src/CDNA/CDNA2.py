from src.CDNA.CDNA import CDNA

class CDNA2(CDNA) :
    def __init__(self, isa_pdf_path):
        super().__init__(
            isa_name="CDNA2",
            isa_llvm_urls=[
                "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
            ],
            isa_pdf_path=isa_pdf_path,
            pdf_range_page=range(212,275),
            is_double_optable=False
        )

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
 
  