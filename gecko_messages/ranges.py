###############################################
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
##############################################
# -*- coding: utf-8 -*-
from collections import namedtuple

drange = namedtuple("drange","min max")
dfprange = namedtuple("drange","fracbit min max res")

def irange(bits, signed):
    """Integer"""
    if signed:
        return drange(-2**(bits-1),2**(bits-1)-1)
    return drange(0,2**bits-1)

def fltrange(double=True):
    """Floating point"""
    return drange(1.175494351e-38,3.402823466e+38)

def dblrange():
    """Floating point"""
    return drange(sys.float_info.min,sys.float_info.max)

def fprange(frac):
    """Fixed Point"""
    whole = 32 - frac
    scale = 1.0 / (2**frac)
    minfp = -2**(whole-1)
    maxfp = 2**(whole-1) - scale
    return dfprange(frac, minfp, maxfp, scale)