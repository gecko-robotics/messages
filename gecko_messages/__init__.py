# -*- coding: utf-8 -*-
##############################################
# The MIT License (MIT)
# Copyright (c) 2023 Gecko Robotics
# see LICENSE for full details
##############################################

import sys
from pathlib import Path

# Get the absolute path of the current script
path = Path(__file__).resolve().parent / "ros"
# print(path)
sys.path.insert(0, str(path))

from importlib.metadata import version
__author__ = 'Kevin Walchko'
__license__ = "MIT"
__version__ = version("gecko_messages")

from .ros.covariance_pb2 import *
from .ros.header_pb2 import *
from .ros.vector3_pb2 import Vector3
from .ros.quaternion_pb2 import Quaternion

from .ros.battery_pb2 import *
from .ros.imu_pb2 import *
from .ros.jointstate_pb2 import *
from .ros.magneticfield_pb2 import *
from .ros.odometry_pb2 import *
from .ros.pose_pb2 import *
from .ros.pressure_pb2 import *
from .ros.range_pb2 import *
from .ros.transform_pb2 import *
from .ros.twist_pb2 import *
from .ros.wrench_pb2 import *