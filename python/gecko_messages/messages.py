
from collections import namedtuple
from enum import IntEnum
from dataclasses import dataclass
import dataclasses

class Msg(IntEnum):
    PING        = 10
    HEARTBEAT   = 11
    BATTERY     = 12
    DISTANCE    = 20
    MOTORS_1    = 30
    MOTORS_2    = 31
    MOTORS_4    = 32
    MOTORS_6    = 33
    MOTORS_8    = 34
    IMU_A       = 40
    IMU_AG      = 41
    IMU_AM      = 42
    IMU_AGM     = 43
    IMU_AGMT    = 44
    IMU_AGMPT   = 45
    ATMOSPHERIC = 60
    SATNAV      = 65
    PPS         = 66

# date_t = namedtuple("date_t","year month day")
# clock_time_t = namedtuple("clock_time_t","hour minute seconds")
# vec_t = namedtuple("vec_t", "x y z")
# quat_t = namedtuple("quat_t", "w x y z")
# twist_t = namedtuple("twist_t", "linear angular")
# gps_t = namedtuple("gps_t", "lat lon altitude hdop satellites fix year month day hour min sec") # 4f2B3B3B
# msg_t = namedtuple("msg_t", "a g m q gps temperature pressure timestamp")
# imu_agmtp_t = namedtuple("imu_agmtp_t", "id timestamp ax ay az gx gy gz mx my mz temperature pressure")

class Base:
    def flatten(self, data):
        if isinstance(data, tuple):
            for x in data:
                yield from self.flatten(x)
        else:
            yield data
    def serialize(self):
        return tuple(self.flatten(dataclasses.astuple(self)))

@dataclass(frozen=True)
class date_t(Base):
    year: int
    mon: int
    day: int

@dataclass(frozen=True)
class clock_time_t(Base):
    hr: int
    min: int
    sec: int

@dataclass(frozen=True)
class vec_t(Base):
    x: float
    y: float
    z: float

@dataclass(frozen=True)
class quat_t(Base):
    w: float
    x: float
    y: float
    z: float

@dataclass(frozen=True)
class twist_t(Base):
    linear: vec_t
    angular: vec_t

    def __init__(self,lx,ly,lz,ax,ay,az):
        object.__setattr__(self, "linear", vec_t(lx,ly,lz))
        object.__setattr__(self, "angular", vec_t(ax,ay,az))

@dataclass(frozen=True)
class wrench_t(Base):
    force: vec_t
    torque: vec_t

    def __init__(self,fx,fy,fz,tx,ty,tz):
        object.__setattr__(self, "force", vec_t(fx,fy,fz))
        object.__setattr__(self, "torque", vec_t(tx,ty,tz))


@dataclass(frozen=True)
class pose_t(Base):
    position: vec_t
    orientation: quat_t

    def __init__(self,px,py,pz,w,x,y,z):
        object.__setattr__(self, "position", vec_t(px,py,pz))
        object.__setattr__(self, "orientation", quat_t(w,x,y,z))

@dataclass(frozen=True)
class gps_t(Base):
    lat: float
    lon: float
    altitude: float
    hdop: float
    satellites: int
    fix: int
    year: int
    month: int
    day: int
    hour: int
    min: int
    sec: int

@dataclass(frozen=True)
class imu_agmtp_t(Base):
    a: vec_t
    g: vec_t
    m: vec_t
    pressure: float
    temperature: float
    timestamp: int

    def __init__(self,ax,ay,az,gx,gy,gz,mx,my,mz,t,p,ts):
        object.__setattr__(self, "a", vec_t(ax,ay,az))
        object.__setattr__(self, "g", vec_t(gx,gy,gz))
        object.__setattr__(self, "m", vec_t(mx,my,mz))
        object.__setattr__(self, "temperature", t)
        object.__setattr__(self, "pressure", p)
        object.__setattr__(self, "timestamp", ts)



# @dataclass(frozen=True)
# class vec_t:
#     x: float
#     y: float
#     z: float

# @dataclass(frozen=True)
# class imu_agmtp_t:
#     a: vec_t
#     g: vec_t
#     m: vec_t
#     pressure: float
#     temperature: float
#     timestamp: int

#     def __init__(self,id,ts,ax,ay,az,gx,gy,gz,mx,my,mz,t,p):
#         object.__setattr__(self, "a", vec_t(ax,ay,az))
#         object.__setattr__(self, "g", vec_t(gx,gy,gz))
#         object.__setattr__(self, "m", vec_t(mx,my,mz))
#         object.__setattr__(self, "pressure", p)
#         object.__setattr__(self, "temperature", t)
#         object.__setattr__(self, "timestamp", ts)