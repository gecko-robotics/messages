from dataclasses import dataclass





@dataclass(frozen=True)
class vecf_t(Base):
    x: float # size: 4
    y: float # size: 4
    z: float # size: 4

    def __yivo__(self):
        return ("fff", 12, vecf_t, 1)