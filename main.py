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

    # instruction_set.to_csv("test37.csv")
    # instruction_set.get_isa_pdf_object().print_instructions()
    # instruction_set.create_isa_instructions_dic()
    # instruction_set.print_isa_instructions(1,100)
    # instruction_set.get_isa_instructions_list().export_to_csv("test36.csv")


if __name__ == "__main__":
    main() 