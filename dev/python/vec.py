# Do not edit, this is autogenerated
# MIT Kevin Walchko (c) 2023
from dataclasses import dataclass
from enum import IntEnum


@dataclass(frozen=True)
class vec_t(Base):
    x: float # size: 4
    y: float # size: 4
    z: float # size: 4

    def __yivo__(self):
        # (fmt, size, name, id)
        # name_t.__class__ already has name, do I need it again?
        return ("fff", 12, vec_t, 1)