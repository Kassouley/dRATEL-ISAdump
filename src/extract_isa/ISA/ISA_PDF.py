import fitz  # PyMuPDF
from ..utils.utils import *
from ..utils.enumeration import *

ENCODING_SUFFIX = ['e32', 'e64', 'dpp', 'sdwa', 'e64_dpp']

class ISA_PDF :
    def __init__(self, isa_pdf_path: str, pdf_table_format: dict, 
                 pages_range: range, is_double_optable: bool) -> None:
        self._isa_pdf_path = isa_pdf_path
        self._pages_range = pages_range
        self._is_double_optable = is_double_optable
        self._scraped_data = pdf_table_format
        self.instructions_dict = None
        self.matched_instructions_dict = {}
        self.format_dict = None
        self.scrape_tables_from_pdf()
        self.create_instructions_dict()

    @property
    def isa_pdf_path(self) -> str:
        return self._isa_pdf_path

    @property
    def pages_range(self) -> range:
        return self._pages_range

    @property
    def is_double_optable(self) -> bool:
        return self._is_double_optable
    
    def get_scraped_data(self) -> dict :
        return self._scraped_data

    def get_instructions_dict(self) -> dict :
        if self.instructions_dict == None:
            raise AttributeError("Create instruction dic before getting it")
        return self.instructions_dict
    
    def get_data_for(self, instruction_name: str):
        instruction_name_upper = instruction_name.upper()
        data = self.instructions_dict.get(instruction_name_upper)
        self.matched_instructions_dict[instruction_name_upper] = data
        return data
   
    def get_unmatched_instructions_dict(self):
        unmatched = {
            key: value
            for key, value in self.instructions_dict.items()
            if key not in self.matched_instructions_dict
        }
        return unmatched

    def scrape_tables_from_pdf(self) -> None :
        print("Scraping PDF . . . ")
        document = fitz.open(self.isa_pdf_path)
        tables = [t.extract()[1:] for page_num in self.pages_range for t in document.load_page(page_num).find_tables()]

        for format, dic1 in self._scraped_data.items():
            for table_name, dic2 in dic1.items():
                num_tables = dic2['#']
                for t in tables[:num_tables]:
                    if table_name == 'INST':
                        if self.is_double_optable:
                            table1 = [(e_tmp[1], e_tmp[0], format) for e in t if (e_tmp := [i for i in e if i != '']) and e_tmp[1] != "Reserved"]
                            table2 = [(e_tmp[3], e_tmp[2], format) for e in t if (e_tmp := [i for i in e if i != '']) and len(e_tmp) > 2 and e_tmp[2] != "Reserved"]
                            dic2['tab'].extend(table1 + table2)
                        else:
                            dic2['tab'].extend([(e[1], e[0], format) for e in t if e[1] != "Reserved"])
                    else:
                        dic2['tab'].extend(frag_and_dupli(t))
                del tables[:num_tables]
        print("Done.")


    #   Create a dict where :
    #       key = instruction_mnemonic
    #       value = list("instruction_mnemonic", "opcode", "format")
    def create_instructions_dict(self) -> None:
        self.instructions_dict = {instruction[ISA_Pdf.INSTRUCTIONS.value].upper(): instruction 
            for instructions in self._scraped_data.values()
            if 'INST' in instructions
            for instruction in instructions['INST']['tab'][1:]}
