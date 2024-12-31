# import sys
from src.ISA.ISA_PDF import ISA_PDF
from src.ISA.ISA_Soup import ISA_Soup
from src.CDNA.CDNA2 import CDNA2
import csv
#########################

def main() :
    url = "https://llvm.org/docs/AMDGPU/AMDGPUAsmGFX90a.html"
    pdf = "C:\\Users\\lucas\\Downloads\\cdna2.pdf"

    instruction_set = CDNA2(pdf)
    instruction_set.create_instructions_dict()

    instruction_set.to_csv("test37.csv")


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


