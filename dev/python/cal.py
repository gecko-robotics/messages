# Do not edit, this is autogenerated
# MIT Kevin Walchko (c) 2023
from dataclasses import dataclass


@dataclass(frozen=True)
class cal_t(Base):
    cals: float # size: 4 * 12
    sensor: int # size: 1

    def __yivo__(self):
        # (fmt, size, name, id)
        # name_t.__class__ already has name, do I need it again?
        return ("12fB", 49, cal_t, 5)