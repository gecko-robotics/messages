
from dataclasses import dataclass
from dataclasses import field
from struct import Struct


@dataclass
class Vecd_t:
    x: float
    y: float
    z: float
    packer: Struct = field(init=False, repr=False, default=Struct( "ddd" )))

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

    