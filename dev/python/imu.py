
from dataclasses import dataclass
from dataclasses import field
from struct import Struct

from vecf import *


@dataclass
class imu:
    id: int # something
    accel: vecf_t
    gyro: vecf_t
    mag: vecf_t
    pressure: float
    temperature: float
    timestamp: int
    packer: Struct = field(init=False, repr=False, default=Struct( "BfffffffffffI" )))

    def pack(self):
        return self.packer.pack(*self.to_list())

    def unpack(self, pkt):
        return self.packer.unpack(pkt)

    def to_list(self):
        ret = []
        for a in self.__dict__.values():
            if isinstance(a,float) or isinstance(a,int):
                ret.append(a)
            else:
                for i in a.to_list():
                    ret.append(i)
        return ret

    