# Do not edit, this is autogenerated
#
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
###############################################################################
from dataclasses import dataclass
from .base import Base
from enum import IntEnum, unique
@unique
class SENSOR(IntEnum):
    unknown = 0
    accels = 1
    gyros = 2
    mags = 3


@dataclass
class calibration_t(Base):
    cal: float = 0
    type: int = 0

    def __yivo__(self):
        # (fmt, size, id)
        return ("12fB", 49, 20)
