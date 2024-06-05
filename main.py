import sys
from CDNA import * 
from InstructionSet import * 
from enumeration import ISA
from ISA_Soup import *

#########################
#########################
#########################
# TODO
#   CDNA1&3
#   BINARY_STRING

def main() :
    # if len(sys.argv) != 2:
    #     print("Usage: python3 script.py <URL>")
    #     return
    # url = sys.argv[1]
    url = "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
    pdf = "C:\\Users\\lucas\\Downloads\\cdna2.pdf"

    instruction_set = CDNA2(pdf)
    instruction_set.create_instructions_dic()
    instruction_set.to_csv("test37.csv")
    # instruction_set.get_isa_pdf_object().print_instructions()
    # instruction_set.create_isa_instructions_dic()
    # instruction_set.print_isa_instructions(1,100)
    # instruction_set.get_isa_instructions_list().export_to_csv("test36.csv")


if __name__ == "__main__":
    main() 