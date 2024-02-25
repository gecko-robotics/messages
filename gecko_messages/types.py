import sys
from collections import namedtuple
from .utils import var_types

drange = namedtuple("drange","min max")
dfprange = namedtuple("drange","fracbit min max res")

def irange(bits, signed):
    """Integer"""
    if signed:
        return drange(-2**(bits-1),2**(bits-1)-1)
    return drange(0,2**bits-1)

def frange(double=True):
    """Floating point"""
    if double:
        return drange(sys.float_info.min,sys.float_info.max)
    return drange(1.175494351e-38,3.402823466e+38)

def fprange(frac):
    """Fixed Point"""
    whole = 32 - frac
    scale = 1.0 / (2**frac)
    minfp = -2**(whole-1)
    maxfp = 2**(whole-1) - scale
    return dfprange(frac, minfp, maxfp, scale)

class TypeBase:
    def __str__(self):
        if self.len == 1:
            return f"{self.type} {self.variable}(size={self.size}, fmt={self.fmt}, default={self.default})"
        return f"{self.type} {self.variable}[{self.len}](size={self.size}, fmt={self.fmt}, default={self.default})"

    def __repr__(self):
        return str(self)

    def c_format(self):
        default = str(self.default).replace('[','{').replace(']','}')
        if self.len == 1 and self.complex:
            return f"{self.type} {self.variable}{default};"
        elif self.len > 1:
            return f"{self.type} {self.variable}[{self.len}]{default};"

        return f"{self.type} {self.variable} = {self.default};"

    def py_format(self):
        if self.len == 1 and not self.complex:
            return f"{self.variable}: {self.type} = {self.default}"
        # mags: list[vec_t] = field(default_factory=(lambda:[0, 0, 0]))
        return f"{self.variable}: list[{self.type}] = field(default_factory=(lambda: {self.default}))"

class Scalar(TypeBase):
    def __init__(self, var, type, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: variable: {var} and/or len: {len}")
        if not isinstance(type, str) or type not in var_types:
            raise Exception(f"Invalid: {type}")
        self.variable = var
        self.type = type
        self.len = len
        self.complex = False
        self.c = var_types[type].c
        self.py = var_types[type].py
        self.default = [0]*len if len > 1 else 0
        self.size = len*var_types[type].size
        self.fmt = f"{len}{var_types[type].fmt}" if len > 1 else var_types[type].fmt

class Quat(TypeBase):
    def __init__(self, var, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: {var} and/or {len}")
        self.variable = var
        self.type = "quat_t"
        self.len = len
        self.complex = True
        self.default = [[0,0,0] for _ in range(len)] if len > 1 else [0,0,0]
        self.size = 4*4*len
        self.fmt = f"{4*len}f"

class Vec(TypeBase):
    def __init__(self, var, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: {var} and/or {len}")
        self.variable = var
        self.type = "vec_t"
        self.len = len
        self.complex = True
        self.default = [[0,0,0] for _ in range(len)] if len > 1 else [0,0,0]
        self.size = 3*4*len
        self.fmt = f"{3*len}f"

class Twist(TypeBase):
    def __init__(self, var, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: {var} and/or {len}")
        self.variable = var
        self.type = "twist_t"
        self.len = len
        self.complex = True
        self.default = [[0,0,0,0,0,0] for _ in range(len)] if len > 1 else [0,0,0,0,0,0]
        self.size = 6*4*len
        self.fmt = f"{6*len}f"

class Wrench(TypeBase):
    def __init__(self, var, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: {var} and/or {len}")
        self.variable = var
        self.type = "wrench_t"
        self.len = len
        self.complex = True
        self.default = [[0,0,0,0,0,0] for _ in range(len)] if len > 1 else [0,0,0,0,0,0]
        self.size = 6*4*len
        self.fmt = f"{6*len}f"

class Pose(TypeBase):
    def __init__(self, var, len):
        if not isinstance(var, str) or not isinstance(len, int) or len < 1:
            raise Exception(f"Invalid: {var} and/or {len}")
        self.variable = var
        self.type = "pose_t"
        self.len = len
        self.complex = True
        self.default = [[0,0,0,1,0,0,0] for _ in range(len)] if len > 1 else [0,0,0,1,0,0,0]
        self.size = 7*4*len
        self.fmt = f"{7*len}f"

# print(Scalar("x","float",1))
# print(Scalar("y","uint32",3))
# print(Pose("bob",1))
# print("Python -------------------")
# print(Scalar("y","uint32",3).py_format())
# print(Vec("bob",2).py_format())
# print("C ------------------------")
# print(Scalar("x","float",1).c_format())
# print(Vec("bob",2).c_format())