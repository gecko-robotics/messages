
#pragma once

#include <stdint.h>
#include <string>
#include "vecf.h"
// this is a test
// a second line
// a third line

namespace yivo {

constexpr uint8_t IMU_MSG_SIZE = 48;

constexpr uint8_t IMU_MSG_ID = 4;

struct __attribute__((packed)) imu_t {
  enum IMU_STATUS: uint32_t {NO_ERROR = 0, ACCELS = 1, GYROS = 2, MAGS = 4, PRESSURE = 8, TEMPERATURE = 16};

  vecf_t accel; // size: 12
  vecf_t gyro; // size: 12
  vecf_t mag; // size: 12
  float pressure; // size: 4
  float temperature; // size: 4
  uint32_t timestamp; // size: 4

};



inline
message_t imu_yivo_pack(const imu_t& msg) {
  message_t msg = yivo.pack(4, (uint8_t*)&msg, 48);
  return msg;
}




} // end namespace