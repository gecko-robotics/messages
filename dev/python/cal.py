from dataclasses import dataclass





@dataclass(frozen=True)
class cal_t(Base):
    cals: float # size: 4 * 12

    def __yivo__(self):
        return ("12f", 48, cal_t, 5)