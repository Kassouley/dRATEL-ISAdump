import re

class Format:
    def __init__(self, name: str, binary_encoding: str, field_dict: dict, size: int) -> None:
        self._name = name
        self._size = size
        self._binary_encoding = binary_encoding
        self._field_dict = field_dict
        self._encoding_string = None
        if field_dict != None :
            self._encoding_string = self._create_encoding_string()

    @property
    def name(self) -> str:
        return self._name

    @property
    def binary_encoding(self) -> str:
        return self._binary_encoding

    @property
    def size(self) -> int:
        return self._size

    @property
    def field_dict(self) -> dict:
        return self._field_dict

    @property
    def encoding_string(self) -> str:
        return self._encoding_string
    
    def to_list(self) -> list:
        list = [self._name, str(self._size), self._binary_encoding, self._encoding_string]
        for k, v in self._field_dict.items():
            list.append(k) 
            list.append(v['bits'])
        return list

    def get_attribute_list_format(self) -> list:
        field_list = [item for field_name, field_info in self._field_dict.items() for item in (field_name, field_info['bits'])]
        return [self._name, self._size, self._binary_encoding, self._encoding_string] + field_list

    def _create_encoding_string(self) -> str:
        def remove_duplicates_preserve_order(lst):
            seen = set()
            seen_add = seen.add
            result = []
            for x in lst:
                if x == "-" or x not in seen:
                    result.append(x)
                    seen_add(x)
            return result
        
        def concatenate_elements(lst):
            result = []
            i = 0
            while i < len(lst):
                if lst[i] == "-":
                    dashes = []
                    while i < len(lst) and lst[i] == "-":
                        dashes.append(lst[i])
                        i += 1
                    result.append("".join(dashes))
                else:
                    result.append(lst[i])
                    i += 1
            return ".".join(result)
    
        encoding_array = ['-'] * self.size
        for field, dic in self.field_dict.items() :
            pos = [int(num) for num in re.findall(r'\d+', dic['bits'])]
            if len(pos) == 1:
                pos.append(pos[0])
            for i in range(pos[1],pos[0]+1) :
                encoding_array[i] = field

        segmented_processed_lists = []
    
        for i in range(0, len(encoding_array), 32):
            segment = encoding_array[i:i + 32]
            reversed_segment = segment[::-1]
            unique_segment = remove_duplicates_preserve_order(reversed_segment)
            concatenated_segment = concatenate_elements(unique_segment)
            segmented_processed_lists.append(concatenated_segment)
        
        encoding_string = "  ".join(segmented_processed_lists)

        return encoding_string
