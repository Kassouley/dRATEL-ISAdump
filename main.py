# import sys
from src.ISA.ISA_PDF import ISA_PDF
from src.ISA.ISA_Soup import ISA_Soup
from src.CDNA.CDNA2 import CDNA2
import csv
#########################

def get_pdf_table_format() :
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
 
  

def main() :
    # if len(sys.argv) != 2:
    #     print("Usage: python3 script.py <URL>")
    #     return
    # url = sys.argv[1]
    url = "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
    pdf = "C:\\Users\\lucas\\Downloads\\cdna2.pdf"

    
    # isa = ISA_Soup(url)
    # isa.create_instruction_dict()
    # print(isa.get_instruction_dict())
    instruction_set = CDNA2(pdf)
    # instruction_set.isa_pdf.scrape_tables_from_pdf()
    # instruction_set.isa_pdf.create_instructions_dict()
    # print(instruction_set.isa_pdf.get_instructions_dict())
    instruction_set.create_instructions_dict()

    instruction_set.to_csv("test37.csv")
    # instruction_set.get_isa_pdf_object().print_instructions()
    # instruction_set.create_isa_instructions_dic()
    # instruction_set.print_isa_instructions(1,100)
    # instruction_set.get_isa_instructions_list().export_to_csv("test36.csv")


def microbench() :
    url = "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
    pdf = "C:\\Users\\lucas\\Downloads\\cdna2.pdf"

    instruction_set = CDNA2(pdf)
    # instruction_set.isa_llvm_soups.get_section_dic_by_type()
    instruction_set.create_instructions_dic()
    
    csv_file = "gfx90aMicrobench.csv"
    file_exists = False
    try:
        with open(csv_file, 'r') as f:
            reader = csv.reader(f)
            if any(row for row in reader):
                file_exists = True
    except FileNotFoundError:
        pass
    with open(csv_file, 'a', newline='') as f:
        writer = csv.writer(f)
        if not file_exists:
            writer.writerow(["instructionName","instructionType","nOperands","operandsTypes"]) 

        for type, instructions in instruction_set.instructions_dic.items() :
            for instruction in instructions :
                row = [instruction.get_instruction().lower(), instruction.get_operand_type() ,len(instruction.get_operand_list())]
                sub_row = []
                for operand in instruction.get_operand_list() :
                    sub_row.append(operand.get_type())
                row.append(";".join(sub_row))
                writer.writerow(row)

if __name__ == "__main__":
    main() 


