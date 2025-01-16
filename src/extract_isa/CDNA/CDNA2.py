from .CDNA import CDNA
from ..utils.utils import rename_key_preserve_order
from ..InstructionData.Instruction import Instruction


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

    def _try_get_special_opcode(self, instruction_mnemonic: str):
        if instruction_mnemonic.upper() == "S_TTRACEDATA":
            return 22
        return None
    
    

    def set_corresponding_operand_to_field(self, instruction: Instruction) -> None:
        # Prepare encoding array
        encoding_string = instruction.get_encoding_string().replace(" ", ".").replace("-", "")
        encoding_arr = [e for e in encoding_string.split(".") if not all(c in '01' for c in e)]

        try :
            encoding_arr.remove("ACC")
            encoding_arr.remove("ACC0")
            encoding_arr.remove("ACC1")
            encoding_arr.remove("ACC2")
            encoding_arr.remove("SRC0_SEXT")
            encoding_arr.remove("SRC1_SEXT")
            encoding_arr.remove("SRC2_SEXT")
            encoding_arr.remove("SEXT")
            encoding_arr.remove("SRC0_NEG")
            encoding_arr.remove("SRC1_NEG")
            encoding_arr.remove("SRC2_NEG")
            encoding_arr.remove("NEG")
            encoding_arr.remove("SRC0_ABS")
            encoding_arr.remove("SRC1_ABS")
            encoding_arr.remove("SRC2_ABS")
            encoding_arr.remove("ABS")
            encoding_arr.remove("S0")
            encoding_arr.remove("S1")
        except: 
            pass
        
        # Get operands and modifiers
        operands = instruction.get_operand_list()
        modifiers = instruction.get_modifier_list()
        
        # Combine operands and modifiers into a single list with flags
        elements = [op for op in operands] + [mod for mod in modifiers]
        elements_len = len(elements)
        elements_found = [False] * elements_len
        
        max_iterations = elements_len * 3  # Prevent infinite loops
        iterations = 0
        # Main processing loop
        i = 0
        while elements_len > 0 and iterations < max_iterations:
            iterations += 1
            element = elements[i]
            if elements_found[i]:
                i = (i + 1) % len(elements)  # Wrap around
                continue
            
            element_name = element.get_name().upper()

            # Define a mapping for special cases
            special_cases = {
                'VDATA': 'VDATA0',
                'SDST': ['VDST', 'SDATA'],  # SDST maps to both 'VDST' and 'SDATA'
                'HWREG': 'SIMM16',
                'PROBE': 'SDATA',
                'OFFSET21S': 'OFFSET',
                'OFFSET20U': 'OFFSET',
                'OFFSET12': 'OFFSET',
                'OFFSET13S': 'OFFSET',
                'DPP64_CTRL': 'DPP_CTRL',
                'DPP32_CTRL': 'DPP_CTRL',
                'LABEL': 'SIMM16',
                'IMM16': 'SIMM16',
                'VDST': 'VDATA',
                'SRC': 'SRC0',
                'VSRC': 'SRC0',
                'VSRC0': 'SRC0',
                'VSRC1': 'SRC1',
                'VSRC2': 'SRC2',
                'SRC0': 'VSRC0',
                'SRC1': 'VSRC1',
                'SRC2': 'VSRC2',
                'SSRC0': 'SRC0',
                'SSRC1': 'SRC1',
                'SSRC2': 'SRC2',
                'SSRC': 'SSRC0',
                'M_OP_SEL': 'OP_SEL',
                'M_OP_SEL_HI': 'OP_SEL_HI'
            }

            # Check for matching conditions
            matched_field = None
            if element_name == "SIMM32" :
                element.set_corresponding_field("NEXT_DWORD")
                elements_found[i] = True
                elements_len -= 1
            elif element_name == "VCC":
                element.set_corresponding_field("NONE"+str(i))
                elements_found[i] = True
                elements_len -= 1
            elif element_name == "OP_SEL_HI" or element_name == "M_OP_SEL_HI":
                element.set_corresponding_field("OP_SEL_HI+OP_SEL_HI2")
                encoding_arr.remove("OP_SEL_HI")
                encoding_arr.remove("OP_SEL_HI2")
                elements_found[i] = True
                elements_len -= 1
            elif (element_name == "OFFSET" or element_name == "PATTERN") and "OFFSET0" in encoding_arr and "OFFSET1" in encoding_arr:
                element.set_corresponding_field("OFFSET0+OFFSET1")
                encoding_arr.remove("OFFSET0")
                encoding_arr.remove("OFFSET1")
                elements_found[i] = True
                elements_len -= 1
            elif element_name == "FMT" and "NFMT" in encoding_arr and "DFMT" in encoding_arr:
                element.set_corresponding_field("NFMT+DFMT")
                encoding_arr.remove("NFMT")
                encoding_arr.remove("DFMT")
                elements_found[i] = True
                elements_len -= 1
            elif len(encoding_arr) == 1:
                matched_field = encoding_arr[0]
            elif element_name in encoding_arr:
                matched_field = element_name
            elif element_name in special_cases:
                case_value = special_cases[element_name]
                if isinstance(case_value, list):  # Handle multiple mappings
                    for field in case_value:
                        if field in encoding_arr:
                            matched_field = field
                            break
                elif case_value in encoding_arr:
                    matched_field = case_value


            # Perform assignment if a match is found
            if matched_field:
                element.set_corresponding_field(matched_field)
                encoding_arr.remove(matched_field)
                elements_found[i] = True
                elements_len -= 1

            # Move to the next element
            i = (i + 1) % len(elements)


    def set_correct_instruction_mnemonic(self, instruction: Instruction) :
        instruction_mnemonic = instruction.get_mnemonic()
        format_name = instruction.get_format_name()
        if (format_name == "VOPC" 
            or ( format_name == "VOP2" and instruction_mnemonic not in ["V_MADAK_F16","V_MADAK_F32","V_MADMK_F16","V_MADMK_F32"] ) 
            or ( format_name == "VOP1"  and instruction_mnemonic not in ["V_ACCVGPR_MOV_B32","V_SWAP_B32","V_READFIRSTLANE_B32"] )):
            instruction_mnemonic = instruction_mnemonic + "_E32"
        elif instruction_mnemonic == "V_MAD_MIX_F32" :
            instruction_mnemonic = "V_FMA_MIX_F32"
        elif instruction_mnemonic == "V_MAD_MIXLO_F16" :
            instruction_mnemonic = "V_FMA_MIXLO_F16"
        elif instruction_mnemonic == "V_MAD_MIXHI_F16" :
            instruction_mnemonic = "V_FMA_MIXHI_F16"
        elif instruction_mnemonic == "V_ACCVGPR_READ" :
            instruction_mnemonic = "V_ACCVGPR_READ_B32"
        elif instruction_mnemonic == "V_ACCVGPR_WRITE" :
            instruction_mnemonic = "V_ACCVGPR_WRITE_B32"
        instruction.set_mnemonic(instruction_mnemonic)
        
    def _get_changed_instruction_mnemonic(self, instruction_mnemonic: str) -> str :
        if instruction_mnemonic == "V_FMA_MIX_F32" :
            return "V_MAD_MIX_F32"
        elif instruction_mnemonic == "V_FMA_MIXLO_F16" :
            return "V_MAD_MIXLO_F16"
        elif instruction_mnemonic == "V_FMA_MIXHI_F16" :
            return "V_MAD_MIXHI_F16"
        elif instruction_mnemonic == "V_ACCVGPR_READ_B32" :
            return "V_ACCVGPR_READ"
        elif instruction_mnemonic == "V_ACCVGPR_WRITE_B32" :
            return "V_ACCVGPR_WRITE"
        return instruction_mnemonic
        

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
 
  