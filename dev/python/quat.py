# Do not edit, this is autogenerated
# MIT Kevin Walchko (c) 2023
from dataclasses import dataclass


@dataclass(frozen=True)
class quat_t(Base):
    w: float # size: 4
    x: float # size: 4
    y: float # size: 4
    z: float # size: 4

    def __yivo__(self):
        # (fmt, size, name, id)
        # name_t.__class__ already has name, do I need it again?
        return ("ffff", 16, quat_t, 2)