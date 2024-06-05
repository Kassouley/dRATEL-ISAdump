import fitz  # PyMuPDF
import re
from utils import *
from enumeration import *
import pandas as pd
from Instruction import *

class ISA_PDF :
    def __init__(self, isa_pdf_path, pdf_table_format, pages_range, is_double_optable):
        self.isa_pdf_path = isa_pdf_path
        self.pages_range = pages_range
        self.is_double_optable = is_double_optable
        self.pdf_table_format = pdf_table_format
        self.scrappe_tables_from_pdf()
        self.instructions_dic = self.create_instructions_dic()
        self.type_encoding_dic = self.create_type_encoding_dic()

    def get_type_encoding_of(self, type):
        if ":" in type :
            type_principal, type_suffix = type.split(":")
            return DoubleType(self.type_encoding_dic[type_principal],self.type_encoding_dic[type_suffix])
        return self.type_encoding_dic[type]

    def get_instructions_dic(self) :
        return self.instructions_dic

    def scrappe_tables_from_pdf(self) :
        
        print("Begin scrapping PDF . . . ")
        document = fitz.open(self.isa_pdf_path)
        tables = []
        for page_num in self.pages_range:
            page = document.load_page(page_num)
            table = page.find_tables()
            for t in table.tables:
                tables.append(t.extract()[1:])
        for name1, dic1 in self.pdf_table_format.items():
            for name2, dic2 in dic1.items() :
                for t in tables[:dic2['#']]:
                    if name2 == 'INST':
                        if self.is_double_optable :
                            table1 = []
                            table2 = []
                            for e in t :
                                e_tmp = [i for i in e if i != '']
                                if e_tmp[1] != "Reserved" :
                                    table1.append([e_tmp[1], e_tmp[0], name1])
                                if len(e_tmp) > 2 :
                                    if e_tmp[2] != "Reserved" :
                                        table2.append([e_tmp[3], e_tmp[2], name1])
                            dic2['tab'].extend(table1)
                            dic2['tab'].extend(table2)
                        else :
                            for e in t :
                                if e[1] != "Reserved" :
                                    dic2['tab'].append([e[1], e[0], name1])
                    else :
                        for e in frag_and_dupli(t) :
                            dic2['tab'].append(e)
                del tables[:dic2['#']]
        print("Finished.")

    def create_instructions_dic(self) :
        instructions_dic = {}
        for key, instructions in self.pdf_table_format.items() :
            if 'INST' in instructions :
                for instruction in instructions['INST']['tab'][1:] :
                    instructions_dic[instruction[ISA_Pdf.INSTRUCTIONS.value].upper()] = instruction
        return instructions_dic

    def create_type_encoding_dic(self) :
        type_encoding_dic = {}
        for type, sub_dict in self.pdf_table_format.items() :
            encoding = []
            field_dict = {}

            for element in sub_dict['FIELD']['tab'][1:] :
                if element[0] not in field_dict :
                    field_dict[element[0]] = {'bits': element[1], 'desc': element[2]}

            match = re.search(r'\[(\d+)', list(field_dict.values())[-1]['bits'])
            if match:
                encoding_size = int(match.group(1)) + 1
            try :
                encoding_bits = "".join(re.findall(r'[01]+', field_dict['ENCODING']['desc']))
            except :
                encoding_bits = ''

            type_encoding = Type(type_name=type, 
                        size=encoding_size, 
                        encoding=encoding_bits, 
                        field_dict=field_dict)

            # encoding.insert(3, self.create_encoding_string(encoding))

            type_encoding_dic[type] = type_encoding
        return type_encoding_dic



    def print_instructions(self, s=None, e=None) :
        pd.set_option('display.max_rows', None)
        pd.set_option('display.max_columns', None)
        df = pd.DataFrame(self.get_all_instructions_list())
        print(df.iloc[s:e])

    
    def clean_binary_string(self, s):
        s = re.sub(r'-(?=[a-zA-Z])', '-.', s)
        s = re.sub(r'\. ', ' ', s)
        s_tmp = s.split()
        if len(s_tmp) == 2 :
            s1, s2 = s_tmp
            return s2 + " " + s1
        else :
            return s

    def create_encoding_string(self, encoding) :
        encoding_array = ['-'] * 32
        if encoding[1] == 64 :
            encoding_string = encoding_string + ' ' + '-' * 32
        for i in range(len(encoding)-1,3,-2) :
            pos = [int(num) for num in re.findall(r'\d+', encoding[i])]
            if len(pos) == 1:
                pos.append(pos[0])
            encoding_string = self.replace_substring(encoding_string,encoding[i-1],pos[1],pos[0])
        return self.clean_binary_string(encoding_string)

