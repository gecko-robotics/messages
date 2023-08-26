//////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2023 gecko-robotics
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <stdint.h>

// constexpr uint8_t MSG_NO_ERROR    = 0; // when use this, echo?
// constexpr uint8_t MSG_ERROR       = 1; // ??
// constexpr uint8_t MSG_CMD_ERROR   = 2; // invalid cmd
// constexpr uint8_t MSG_YIVO_ERROR  = 3; // failed checksumm

constexpr uint8_t MSG_PING        = 10;
constexpr uint8_t MSG_HEARTBEAT   = 11;
constexpr uint8_t MSG_BATTERY     = 12;
//-------------------------------------
constexpr uint8_t MSG_DISTANCE    = 20;
//-------------------------------------
constexpr uint8_t MSG_MOTORS_1    = 30;
constexpr uint8_t MSG_MOTORS_2    = 31;
constexpr uint8_t MSG_MOTORS_4    = 32;
constexpr uint8_t MSG_MOTORS_6    = 33;
constexpr uint8_t MSG_MOTORS_8    = 34;
//-------------------------------------
constexpr uint8_t MSG_IMU_A       = 40;
constexpr uint8_t MSG_IMU_AG      = 41;
constexpr uint8_t MSG_IMU_AM      = 42;
constexpr uint8_t MSG_IMU_AGM     = 43;
constexpr uint8_t MSG_IMU_AGMT    = 44;
constexpr uint8_t MSG_IMU_AGMPT   = 45;
//-------------------------------------
constexpr uint8_t MSG_IMU_A       = 50;
constexpr uint8_t MSG_IMU_AG      = 51;
constexpr uint8_t MSG_IMU_AM      = 52;
constexpr uint8_t MSG_IMU_AGM     = 53;
constexpr uint8_t MSG_IMU_AGMT    = 54;
constexpr uint8_t MSG_IMU_AGMPT   = 55;
//-------------------------------------
constexpr uint8_t MSG_ATMOSPHERIC = 60;
constexpr uint8_t MSG_SATNAV      = 65;
constexpr uint8_t MSG_PPS         = 66;
//-------------------------------------
constexpr uint8_t MSG_CMD_TWIST   = 70; // vel lin/ang
constexpr uint8_t MSG_CMD_POSE    = 71; // pos-orientation
constexpr uint8_t MSG_CMD_FULL    = 72; // sum of above 2 msgs
constexpr uint8_t MSG_CMD_EFFORT  = 73; // force-torque



constexpr uint8_t NODE_SUBSCRIBE = 0xAA;
constexpr uint8_t NODE_UNSUBSCRIBE = 0x55;
constexpr uint8_t NODE_ERROR = 0x00;
constexpr uint8_t NODE_OK = 0XFF;

/*
11111111111111111111111111111111,1111111111111111111111111111111 <- 64 char
udp://123.123.123.123:65535
tcp://myreallylongservername.local:65535
unix:///here/there/mycool.sock
*/
// broadcast mDNS
struct __attribute__((packed)) advertizement_t {
  char url[64];      // udp://1.2.3.4:56789
  char topic[32];    // alice
  uint16_t msg_id;   // 23
  uint16_t msg_size; // 34
};

// request - reply
struct __attribute__((packed)) subscription_t {
  char topic[32]; // alice
  uint8_t status; // SUBSCRIBE, UNSUBSCRIBE, ERROR, OK
};

//---------------------------------------------------------------------------
// low level messages

struct __attribute__((packed)) header_t {
  // uint8_t type;   // 1
  uint8_t id;         // 1
  uint64_t timestamp; // 8 - FIXME: u32 or u64 ????
};

struct __attribute__((packed)) date_t {
  uint8_t year, month, day;
}; // 3*1 = 3

// clock_time_t t;
struct __attribute__((packed)) clock_time_t {
  uint8_t hour, minute, seconds;
}; // 3*1 = 3

struct __attribute__((packed)) vec_t {
  float x,y,z;
}; // 3*4 = 12

struct __attribute__((packed)) quat_t {
  float w,x,y,z;
}; // 4*4 = 16

struct __attribute__((packed)) twist_t {
  vec_t linear;  // 4*3 = 12
  vec_t angular; // 12
};

struct __attribute__((packed)) wrench_t {
  vec_t force;  // 4*3 = 12
  vec_t torque; // 12
};

struct __attribute__((packed)) pose_t {
  vec_t position;     // 4*3 = 12
  quat_t orientation; // 4*4 = 16
};

struct __attribute__((packed)) frame_t {
  enum Frame : uint8_t { UNKNOWN, BODY, BODY_NED, GLOBAL, GLOBAL_NED };
  uint8_t frame; // 1
};

struct __attribute__((packed)) atmospheric_t {
  float pressure;    // 4
  float temperature; // 4
};

//------------------------------------------
// high level combined messages

struct __attribute__((packed)) gps_t {
  float lat, lon; // decimal degrees
  float altitude; // meters above MSL
  // float speed; // meters/sec
  float hdop; // horizontal dilution of precision
  uint8_t satellites;
  uint8_t fix;
  date_t date;
  clock_time_t time;
}; // 4*4+2+3+3 = 24

struct __attribute__((packed)) imu_agmpt_t : header_t {
  vec_t a;  // 12 [0:11]
  vec_t g;  // 12 [12:23]
  vec_t m;  // 12 [24:35]
  quat_t q; // 16 [36:51]
  float temperature; // 4 [76:79]
  float pressure; // 4 [80:83]
}; // 36+16+18+12+3+3 = 88


struct __attribute__((packed)) distance_t : header_t {
  enum Distance_Sensor : uint8_t {
    LASER      = 1,
    ULTRASOUND = 2,
    INFRARED   = 4,
    RADAR      = 8,
    LIDAR      = 16,
    UNKNOWN    = 32
  };
  uint16_t min_distance; // cm
  uint16_t max_distance; // cm
  uint16_t distance;     // cm
  Distance_Sensor type;
};


struct __attribute__((packed)) status_motors4_t {
  enum Status: uint8_t {
    OK,       // 0
    DEGRADED, // 1
    FAIL,     // 2
    UNKNOWN   // 3
  };
  uint16_t m0, m1, m2, m3; // pwm
  // uint16_t c0, c1, c2, c3; // current
  uint8_t armed;
  // Status status; // bits: m3[6:7], m2[4:5], m1[2:3], m0[0:1]
};

struct __attribute__((packed)) ping_t : header_t {};

struct __attribute__((packed)) calibrate_t {
  float params[9];
};

struct __attribute__((packed)) satnav_t {
  enum NavSatStatus : uint8_t {
    STATUS_NO_FIX   = 0, // unable to fix position
    STATUS_FIX      = 1, // unaugmented fix
    STATUS_SBAS_FIX = 2, // with satellite-based augmentation
    STATUS_GBAS_FIX = 4, // with ground-based augmentation
  };

  enum NavSatService : uint8_t {
    SERVICE_GPS     = 1,
    SERVICE_GLONASS = 2,
    SERVICE_COMPASS = 4,
    SERVICE_GALILEO = 8
  };

  // satellite information
  NavSatStatus status;
  NavSatService service;

  float latitude;  // degrees, North(+), South(-)
  float longitude; // dgrees, East(+), West(-)
  float altitude;  // meters, distance above WGS84 ellipoid
};

struct __attribute__((packed)) battery_t {
  enum Type : uint8_t { NONE = 0, MAIN = 1, ALT = 2 };
  uint8_t battery_type;
  uint16_t voltage;  // mV
  uint16_t current;  // mA
  uint16_t capacity; // mWhr
  uint8_t charge;    // 0-100 percent remaining
};

// struct __attribute__((packed)) uav_state_t : header_t {
//   pose_t position;
//   twist_t velocity;
//   satnav_t gps;
//   battery_t battery;
//   status_motors4_t motors;
// };

// struct __attribute__((packed)) cmd_direct_quad_t {
//   enum Error: uint8_t {
//     ERROR_INVALID_MOTOR,
//     ERROR_PWM_OUT_OF_RANGE
//   };
//   uint16_t motors[4];
// };

struct __attribute__((packed)) cmd_pose_quad_t {
  enum Error: uint8_t {
    ERROR_INVALID_POSITION,
    ERROR_INVALID_VELOCITY,
    ERROR_INVALID_ORIENTATION
  };
  // vec_t position; // 12
  // vec_t velocity; // 12
  // quaternion_t orientation; // 16
  post_t pose;
  twist_t vel;
};






#if 0
#include <cstdint>

// errors:
// cmd not executable
//
// error msg:
// msgid: error
// reason: checksum fail, invalid motor, not armed, etc - commmand specific

// constexpr uint8_t MSG_NO_ERROR    = 0; // when use this, echo?
// constexpr uint8_t MSG_ERROR       = 1; // ??
// constexpr uint8_t MSG_CMD_ERROR   = 2; // invalid cmd
// constexpr uint8_t MSG_YIVO_ERROR  = 3; // failed checksumm

// constexpr uint8_t MSG_PING        = 10;
// constexpr uint8_t MSG_HEARTBEAT   = 11;
// constexpr uint8_t MSG_BATTERY     = 12;

// constexpr uint8_t MSG_DISTANCE    = 20;

// constexpr uint8_t MSG_MOTORS_4    = 30;
// constexpr uint8_t MSG_MOTORS_6    = 31;
// constexpr uint8_t MSG_MOTORS_8    = 32;

// constexpr uint8_t MSG_RAW_IMU     = 41;
// constexpr uint8_t MSG_IMU_FULL    = 42;
// constexpr uint8_t MSG_ATMOSPHERIC = 43;
// constexpr uint8_t MSG_SATNAV      = 44;

// constexpr uint8_t MSG_TWIST       = 50;
// constexpr uint8_t MSG_WRENCH      = 51;
// constexpr uint8_t MSG_POSE        = 52;

// constexpr uint8_t MSG_CMD_DIR_4   = 60;
// constexpr uint8_t MSG_CMD_POSE_4  = 61;

/*
struct initialization:
https://en.cppreference.com/w/c/language/struct_initialization

c
----------------------
long   8B x86
----------------------
struct timeval {time_t tv_sec, suseconds_t tv_usec}
gettimeofday(timeval&, timezone& or NULL);

struct timespec {time_t tv_sec, long tv_nsec}
clock_gettime(CLOCK_MONOTONIC, timespec&)

time_t not defined by C

- `CLOCK_REALTIME` reports the actual wall clock time.
- `CLOCK_MONOTONIC` is for measuring relative real time. It advances at the same
rate as the actual flow of time but it's not subject to discontinuities from
manual or automatic (NTP) adjustments to the system clock.
- `CLOCK_PROCESS_CPUTIME_ID` is for measuring the amount of CPU time consumed by
the process.
- `CLOCK_THREAD_CPUTIME_ID` is for measuring the amount of CPU time consumed by
the thread. It's supported by modern kernels and glibc since 2.6.12, but on
older linux kernels glibc emulates it badly by simply returning the amount of
CPU time consumed by the process since the moment the thread was created.

arduino
----------------------
int    4B (SAMD) https://www.arduino.cc/reference/en/language/variables/data-types/int/
long   4B https://www.arduino.cc/reference/en/language/variables/data-types/long/
float  4B https://www.arduino.cc/reference/en/language/variables/data-types/float/
double 8B https://www.arduino.cc/reference/en/language/variables/data-types/double/
----------------------
unsigned long (uint32_t) = millis()
unsigned long (uint32_t) = micros()
----------------------
*/



// struct __attribute__((packed)) header_t {
//   // uint8_t type;   // 1
//   uint8_t id;         // 1
//   uint64_t timestamp; // 8 - FIXME: u32 or u64 ????
// };                    // 9 bytes

// struct __attribute__((packed)) error_t: header_t {
//   // uint8_t type;   // 1
//   uint8_t id;         // 1
//   uint8_t reason;
// };                    // 11 bytes

// struct __attribute__((packed)) frame_t {
//   enum Frame : uint8_t { UNKNOWN, BODY, BODY_NED, GLOBAL, GLOBAL_NED };
//   uint8_t frame; // 1
// };

// struct __attribute__((packed)) sensor_t : header_t, frame_t {
//   // uint8_t sensorid; // 1
// };

// struct __attribute__((packed)) vec_t {
//   float x, y, z; // 4*3 = 12
// };

// struct __attribute__((packed)) quaternion_t {
//   float w, x, y, z; // 4*4 = 16
// };

// struct __attribute__((packed)) imu_raw_t : header_t {
//   vec_t linear_acceration; // 12
//   vec_t angular_velocity;  // 12
//   vec_t magnetic_field;    // 12
//   float temperature;       // 4
// };                         // 36 + 4 + 10 = 50

// struct __attribute__((packed)) imu_ros_t : header_t {
//   vec_t linear_acceration;  // 12
//   vec_t angular_velocity;   // 12
//   vec_t magnetic_field;     // 12
//   quaternion_t orientation; // 16
//   float temperature;        // 4
// };

// struct __attribute__((packed)) twist_t {
//   vec_t linear;  // 12
//   vec_t angular; // 12
// };

// struct __attribute__((packed)) wrench_t {
//   vec_t force;  // 12
//   vec_t torque; // 12
// };

// struct __attribute__((packed)) pose_t {
//   vec_t position;           // 12
//   quaternion_t orientation; // 16
// };

// struct __attribute__((packed)) atmospheric_t : header_t {
//   float pressure;    // 4
//   float temperature; // 4
// };

// struct __attribute__((packed)) imu_full_t : header_t {
//   vec_t accelleration;      // 12
//   vec_t gyroscope;          // 12
//   vec_t magnetometer;       // 12
//   quaternion_t orientation; // 16 - madwich filter
//   // float pressure;           // 4
//   // float temperature;        // 4
//   // atmospheric_t atmosphere  // 8
//   float altitude;           // 4
//   float lidar;              // 4
// };                          // 36 + 16 + 8 + 9 = 69

// struct __attribute__((packed)) heartbeat_t : header_t {
//   enum Sensors : uint16_t {
//     ACCEL        = 2,
//     GYRO         = 4,
//     BAROMETER    = 8,
//     TEMPERATURE  = 16,
//     RANGE        = 32,
//     GPS          = 64,
//     BATTERY      = 128, // value?
//     CAMERA       = 256,
//     VIDEODOMETRY = 1024,
//     COMPASS      = 2048
//   };
//   uint8_t has_autopilot;
//   uint16_t sensors;
// };

// struct __attribute__((packed)) distance_t : header_t {
//   enum Distance_Sensor : uint8_t {
//     LASER      = 1,
//     ULTRASOUND = 2,
//     INFRARED   = 4,
//     RADAR      = 8,
//     LIDAR      = 16,
//     UNKNOWN    = 32
//   };
//   uint16_t min_distance; // cm
//   uint16_t max_distance; // cm
//   uint16_t distance;     // cm
//   Distance_Sensor type;
// };

// struct __attribute__((packed)) status_motors4_t {
//   enum Status: uint8_t {
//     OK,       // 0
//     DEGRADED, // 1
//     FAIL,     // 2
//     UNKNOWN   // 3
//   };
//   uint16_t m0, m1, m2, m3; // pwm
//   // uint16_t c0, c1, c2, c3; // current
//   uint8_t armed;
//   // Status status; // bits: m3[6:7], m2[4:5], m1[2:3], m0[0:1]
// };

// struct __attribute__((packed)) ping_t : header_t {};

// struct __attribute__((packed)) calibrate_t {
//   float params[9];
// };

// struct __attribute__((packed)) satnav_t {
//   enum NavSatStatus : uint8_t {
//     STATUS_NO_FIX   = 0, // unable to fix position
//     STATUS_FIX      = 1, // unaugmented fix
//     STATUS_SBAS_FIX = 2, // with satellite-based augmentation
//     STATUS_GBAS_FIX = 4, // with ground-based augmentation
//   };

//   enum NavSatService : uint8_t {
//     SERVICE_GPS     = 1,
//     SERVICE_GLONASS = 2,
//     SERVICE_COMPASS = 4,
//     SERVICE_GALILEO = 8
//   };

//   // satellite information
//   NavSatStatus status;
//   NavSatService service;

//   float latitude;  // degrees, North(+), South(-)
//   float longitude; // dgrees, East(+), West(-)
//   float altitude;  // meters, distance above WGS84 ellipoid
// };

// struct __attribute__((packed)) battery_t {
//   enum Type : uint8_t { NONE = 0, MAIN = 1, ALT = 2 };
//   uint8_t battery_type;
//   uint16_t voltage;  // mV
//   uint16_t current;  // mA
//   uint16_t capacity; // mWhr
//   uint8_t charge;    // 0-100 percent remaining
// };

// struct __attribute__((packed)) uav_state_t : header_t {
//   pose_t position;
//   twist_t velocity;
//   satnav_t gps;
//   battery_t battery;
//   status_motors4_t motors;
// };

// struct __attribute__((packed)) cmd_direct_quad_t {
//   enum Error: uint8_t {
//     ERROR_INVALID_MOTOR,
//     ERROR_PWM_OUT_OF_RANGE
//   };
//   uint16_t motors[4];
// };

// struct __attribute__((packed)) cmd_pose_quad_t {
//   enum Error: uint8_t {
//     ERROR_INVALID_POSITION,
//     ERROR_INVALID_VELOCITY,
//     ERROR_INVALID_ORIENTATION
//   };
//   vec_t position; // 12
//   vec_t velocity; // 12
//   quaternion_t orientation; // 16
// };

// struct illuminance_t: header_t {}
// struct image_t: header_t {}
// struct joy_t: header_t {}
// struct range_t: header_t {}
// struct range_array_t: header_t {} // array of range sensors
// struct laser_scan_t: header_t {}
#endif
