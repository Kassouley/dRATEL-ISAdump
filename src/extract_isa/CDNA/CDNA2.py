from .CDNA import CDNA
from ..utils.utils import rename_key_preserve_order

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

    def _get_field_name(self, field_dict, format_name, field_data) :
        field_name = field_data[0]
        if "OPSEL" in field_name:
                field_name = field_name.replace("OPSEL", "OP_SEL")
        elif field_name == "CLMP":
            field_name = "CLAMP"
        elif field_name == "DST_U":
            field_name = "DST_UNUSED"
        elif field_name == "UNRM":
            field_name = "UNORM"
        elif field_name == "BC":
            field_name = "BOUND_CTRL"


        elif field_name == "ABS":
            field_dict["SRC0_ABS"] = {'bits': '[8]', 'size': 1, 'desc': field_data[2]}
            field_dict["SRC1_ABS"] = {'bits': '[9]', 'size': 1, 'desc': field_data[2]}
            field_dict["SRC2_ABS"] = {'bits': '[10]', 'size': 1, 'desc': field_data[2]}
            field_name = None

        elif field_name == "NEG" and format_name != "VOP3P":
            field_dict["SRC0_NEG"] = {'bits': '[61]', 'size': 1, 'desc': field_data[2]}
            field_dict["SRC1_NEG"] = {'bits': '[62]', 'size': 1, 'desc': field_data[2]}
            field_dict["SRC2_NEG"] = {'bits': '[63]', 'size': 1, 'desc': field_data[2]}
            field_name = None

        elif format_name == "FLAT": 
            if field_name == "DATA":
                field_name = "VDATA"
            elif field_name == "ADDR":
                field_name = "VADDR"
        elif format_name == "DS" :
            if field_name == "DATA0":
                field_name = "VDATA0"
            elif field_name == "DATA1":
                field_name = "VDATA1"
            elif field_name == "ADDR":
                field_name = "VADDR"
        elif format_name == "SOP1" and field_name == "SSRC0":
            field_name = "SSRC"
        elif format_name == "VOP3P" :
            if field_name == "NEG":
                field_name = "NEG_LO"
            elif field_name == "ACC" :
                field_dict["ACC0"] = {'bits': '[59]', 'size': 1, 'desc': field_data[2]}
                field_dict["ACC1"] = {'bits': '[60]', 'size': 1, 'desc': field_data[2]}
                field_name = None
            elif field_name == "ACC_CD":
                field_name = "ACC2"
            
        return field_name

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
 
  