import fitz  # PyMuPDF
import re
from src.utils.utils import *
from src.utils.enumeration import *
from src.InstructionData.Format import Format

class ISA_PDF :
    def __init__(self, isa_pdf_path: str, pdf_table_format: dict, 
                 pages_range: range, is_double_optable: bool) -> None:
        self._isa_pdf_path = isa_pdf_path
        self._pages_range = pages_range
        self._is_double_optable = is_double_optable
        self._scraped_data = pdf_table_format
        self.instructions_dict = None
        self.format_dict = None
        self._data_scraped = False

    @property
    def isa_pdf_path(self) -> str:
        return self._isa_pdf_path

    @property
    def pages_range(self) -> range:
        return self._pages_range

    @property
    def is_double_optable(self) -> bool:
        return self._is_double_optable

    @property
    def scraped_data(self) -> dict:
        if not self._data_scraped:
            raise AttributeError("Scrape data before accessing scraped_data")
        return self._scraped_data   

    def get_instructions_dict(self) -> dict :
        if self.instructions_dict == None:
            raise AttributeError("Create instruction dic before getting it")
        return self.instructions_dict
    
    def get_format_dict(self) -> dict :
        if self.format_dict == None:
            raise AttributeError("Create format dic before getting it")
        return self.format_dict
   
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
        self._data_scraped = True
        print("Done.")

    def create_instructions_dict(self) -> None:
        self.instructions_dict = {instruction[ISA_Pdf.INSTRUCTIONS.value].upper(): instruction 
            for instructions in self._scraped_data.values()
            if 'INST' in instructions
            for instruction in instructions['INST']['tab'][1:]}

    def create_format_dict(self) -> None:
        self.format_dict = {}
        
        for format_key, sub_dict in self._scraped_data.items():
            field_dict = {}
            for element in sub_dict['FIELD']['tab'][1:] :
                if element[0] not in field_dict :
                    numbers = list(map(int, re.findall(r'\d+', element[1])))
                    if len(numbers) == 1:
                        bits_size = 1
                    else :
                        bits_size = numbers[-2] - numbers[-1] + 1
                    field_dict[element[0]] = {'bits': element[1], 'size': bits_size, 'desc': element[2]}

            last_field_bits = list(field_dict.values())[-1]['bits']
            encoding_size = int(re.search(r'\[(\d+)', last_field_bits).group(1)) + 1 if last_field_bits else 0
            
            encoding_bits = "".join(re.findall(r'[01]+', field_dict.get('ENCODING', {}).get('desc', '')))
            
            format_obj = Format(
                name=format_key,
                binary_encoding=encoding_bits,
                field_dict=field_dict,
                size=encoding_size
            )
            
            self.format_dict[format_key] = format_obj
        
