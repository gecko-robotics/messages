from dataclasses import dataclass





@dataclass(frozen=True)
class vecd_t(Base):
    x: float # size: 8
    y: float # size: 8
    z: float # size: 8

    def __yivo__(self):
        return ("ddd", 24, vecd_t, 2)