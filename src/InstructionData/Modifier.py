import re

class Modifier:
    def __init__(self, name: str):
        self._name = name
        self._corresponding_field = "N/F"

    def get_name(self) -> str:
        return self._name

    def set_corresponding_field(self, corresponding_field: str) -> None:
        self._corresponding_field = corresponding_field

    def get_corresponding_field(self) -> str:
        return self._corresponding_field