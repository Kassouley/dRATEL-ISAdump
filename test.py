def get_instruction_formats(self):
    nav_contents = self.llvm_soup.find('nav', id='contents')
    if not nav_contents:
        print("The nav with ID 'contents' was not found on the page.")
        sys.exit()

    instructions_list = nav_contents.find('a', string='Instructions')
    if not instructions_list:
        print("The list with the title 'Instructions' was not found in the nav 'contents'.")
        sys.exit()

    sub_list = instructions_list.find_next('ul')
    if not sub_list:
        print("No sub-list found for the list 'Instructions'.")
        sys.exit()

    instructions_type = sub_list.find_all('li')
    return [element.get_text(strip=True) for element in instructions_type]
