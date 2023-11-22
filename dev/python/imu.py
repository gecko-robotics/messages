from dataclasses import dataclass




from vecf import *


@dataclass(frozen=True)
class imu_t(Base):
    accel: vecf_t # size: 12
    gyro: vecf_t # size: 12
    mag: vecf_t # size: 12
    pressure: float # size: 4
    temperature: float # size: 4
    timestamp: int # size: 4

    def __yivo__(self):
        return ("fffffffffffI", 48, imu_t, 4)