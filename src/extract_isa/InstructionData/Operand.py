import re

class Operand:
    def __init__(self, name: str, type: str, role: str,
                 is_optional: bool, is_modifiable: bool, can_be_dst: bool,
                 href_id: str, href_url: str, size: int, op: str):
        self._name = name
        self._type = type
        self._role = role
        self._is_optional = is_optional
        self._is_modifiable = is_modifiable
        self._can_be_dst = can_be_dst
        self._id = href_id
        self._url = href_url
        self._size = size
        self._operands = op
        self._corresponding_field = "N/F"

    def get_name(self) -> str:
        return self._name

    def get_type(self) -> str:
        return self._type

    def get_role(self) -> str:
        return self._role

    def is_optional(self) -> bool:
        return self._is_optional

    def is_modifiable(self) -> bool:
        return self._is_modifiable

    def can_be_dst(self) -> bool:
        return self._can_be_dst

    def get_id(self) -> str:
        return self._id

    def get_url(self) -> str:
        return self._url

    def get_size(self) -> str:
        return self._size

    def get_operands(self) -> str:
        return self._operands
    
    def is_vector_or_scalar(self) -> bool:
        str = re.sub(r'\s+', '', self._operands)
        arr = str.split(",")
        if "v" in arr and "s" in arr:
            return "SV"
        elif "v" in arr:
            return "V"
        elif "s" in arr:
            return "S"
        elif "a" in arr:
            return "A"
        elif "vcc" in arr:
            return "VCC"
        return "I"
    
    def set_corresponding_field(self, corresponding_field: str) -> None:
        self._corresponding_field = corresponding_field

    def get_corresponding_field(self) -> str:
        return self._corresponding_field