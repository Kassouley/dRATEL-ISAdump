from src.extract_isa.CDNA import CDNA1, CDNA2, CDNA3

def main() :
    pdf = "C:\\Users\\lucas\\Downloads\\cdna2.pdf"

    instruction_set = CDNA2(pdf)
    instruction_set.create_instructions_dict()

    instruction_set.instructions_to_csv("test37.csv")
    instruction_set.formats_to_csv("test38.csv")


if __name__ == "__main__":
    main() 


