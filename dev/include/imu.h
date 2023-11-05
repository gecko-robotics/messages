
#pragma once

#include <stdint.h>
#include <string>
#include "vecf.h"
// this is a test
// a second line
// a third line
//float[20] array

namespace yivo {

constexpr uint8_t IMU_MSG_SIZE = 49;



struct __attribute__((packed)) imu_t {
  uint8_t id; // something
  vecf_t accel;
  vecf_t gyro;
  vecf_t mag;
  float pressure;
  float temperature;
  uint32_t timestamp;

};

static
imu_t imu_init(const uint8 id, const vecf accel, const vecf gyro, const vecf mag, const float pressure, const float temperature, const uint32 timestamp) {
  imu_t ret;
  ret.id = id;
  ret.accel = accel;
  ret.gyro = gyro;
  ret.mag = mag;
  ret.pressure = pressure;
  ret.temperature = temperature;
  ret.timestamp = timestamp;

  return ret;
}

static
message_t imu_pack(const uint8 id, const vecf accel, const vecf gyro, const vecf mag, const float pressure, const float temperature, const uint32 timestamp) {
  imu_t ret;
  ret.id = id;
  ret.accel = accel;
  ret.gyro = gyro;
  ret.mag = mag;
  ret.pressure = pressure;
  ret.temperature = temperature;
  ret.timestamp = timestamp;

  message_t msg;

  return msg;
}

static
void print(const imu_t &val) {
    printf(
        
    );
}

} // end namespace