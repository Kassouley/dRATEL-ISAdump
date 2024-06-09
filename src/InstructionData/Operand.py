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

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_type(self) -> str:
        return self._type

    def set_type(self, type: str) -> None:
        self._type = type

    def get_role(self) -> str:
        return self._role

    def set_role(self, role: str) -> None:
        if role in {'SRC', 'DST'}:
            self._role = role
        else:
            raise ValueError("Le rôle doit être 'SRC' ou 'DST'.")

    def is_optional(self) -> bool:
        return self._is_optional

    def set_optional(self, is_optional: bool) -> None:
        self._is_optional = is_optional

    def is_modifiable(self) -> bool:
        return self._is_modifiable

    def set_modifiable(self, is_modifiable: bool) -> None:
        self._is_modifiable = is_modifiable

    def can_be_dst(self) -> bool:
        return self._can_be_dst

    def set_dst(self, can_be_dst: bool) -> None:
        self._can_be_dst = can_be_dst

    def get_id(self) -> str:
        return self._id

    def set_id(self, id: str) -> None:
        self._id = id

    def get_url(self) -> str:
        return self._url

    def set_url(self, url: str) -> None:
        self._url = url

    def get_size(self) -> int:
        return self._size

    def set_size(self, size: int) -> None:
        self._size = size

    def get_operands(self) -> str:
        return self._operands

    def set_operands(self, operands: str) -> None:
        self._operands = operands
