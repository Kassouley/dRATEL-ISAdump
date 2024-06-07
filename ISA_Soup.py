from utils import *
import sys
from enumeration import *
from Instruction import *

class ISA_SOUP :
    def __init__(self, isa_llvm_url) :
        self.isa_llvm_url = isa_llvm_url
        self.llvm_soup = get_soup_from_request_http(isa_llvm_url)
        self.section_dic_by_type = self.create_sections_by_type()

    def get_section_dic_by_type(self) :
        return self.section_dic_by_type

    def get_instruction_types(self) :
        nav_contents = self.llvm_soup.find('nav', id='contents')
        if nav_contents:
            instructions_list = nav_contents.find('a', string='Instructions')
            if instructions_list:
                sub_list = instructions_list.find_next('ul')
                if sub_list:
                    instructions_type = sub_list.find_all('li')
                    instructions_type_list = [element.get_text(strip=True) for element in instructions_type]
                    return instructions_type_list
                else:
                    print("Aucune sous-liste trouvée pour la liste 'Instructions'.")
            else:
                print("La liste avec le titre 'Instructions' n'a pas été trouvée dans la nav 'contents'.")
        else:
            print("La nav avec l'ID 'contents' n'a pas été trouvée sur la page.")
        sys.exit()    

    def create_sections_by_type(self) :
        section_dic = {}
        section_instructions = self.llvm_soup.find('section', id='instructions')
        if section_instructions:
            for instruction_type in self.get_instruction_types() :
                section = section_instructions.find('section', id=instruction_type.lower().replace(" ","-")).find('pre', class_='literal-block')
                if section:
                    table = section.get_text().split('\n')
                    table_soup = section.prettify().split('\n')[2:]
                    header_line = table.pop(0)
                    column_starts = [header_line.find(col) for col in header_line.split()]
                    section_table = []
                    for line, line_soup in zip(table[1:], table_soup) :
                        if not line.strip():
                            continue
                        elements = [line[start:end].strip() for start, end in zip(column_starts, column_starts[1:]+[None])]
                        instruction = [elements.pop(0)]
                        modifiers = [modifier+":MOD" for modifier in elements.pop().split()]
                        operands = []
                        for index, e in enumerate(elements) :
                            if e.strip() :
                                operand = e.replace(',','')
                                operand_only = operand.split(':')[0].strip()
                                tag = BeautifulSoup(line_soup, 'html.parser').find('a', class_='reference internal', text=operand_only)
                                if tag:
                                    href = tag.get('href')
                                operand = operand + ":" + href + ":" + ''.join([c for c in header_line.split()[index+1] if not c.isdigit()])
                                operands.append(operand)
                        instruction.extend(operands)
                        instruction.extend(modifiers)
                        section_table.append(instruction)
                    section_dic[instruction_type] = section_table
                else:
                    print(f"La section avec l'ID {instruction_type.lower()} n'a pas été trouvée dans la section 'instructions'.")
                    sys.exit()
        else:
            print("La section avec l'ID 'instructions' n'a pas été trouvée sur la page.")
            sys.exit()
        return section_dic


class ISA_SOUPS :
    def __init__(self, isa_llvm_urls) :
        self.isa_llvm_urls = isa_llvm_urls
        self.isa_llvm_soups_list = self.get_llvm_soup_from_urls()
    
    def get_llvm_soup_from_urls(self) :
        if isinstance(self.isa_llvm_urls, str) :
            return [ISA_SOUP(self.isa_llvm_urls)]
        else :
            soups = []
            for url in self.isa_llvm_urls :
                soups.append(ISA_SOUP(url))
            return soups

    def get_section_dic_by_type(self) :
        section_dic = {}
        for llvm_soup in self.isa_llvm_soups_list :
            section_dic_tmp = llvm_soup.get_section_dic_by_type() 
            section_dic = merge_dicts(section_dic_tmp, section_dic)
        return section_dic

    def get_instruction_types(self) :
        instruction_type_list = []
        for llvm_soup in self.isa_llvm_soups_list :
            instruction_type_list_tmp = llvm_soup.get_instruction_types() 
            instruction_type_list = fuse_without_occ(instruction_type_list_tmp, instruction_type_list)
        return instruction_type_list