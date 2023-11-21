
#pragma once

#include <stdint.h>
#include <string>

namespace yivo {

constexpr uint8_t VECF_MSG_SIZE = 12;




enum VECF_STATUS{NULL = 0, BIG = 1, SMALL = 2, HUGE = 4};

enum VECF_BIG_NAME: uint8_t {A, B, C};


struct __attribute__((packed)) vecf_t {
  float x;
  float y;
  float z;
  float magnitude() {
  // something
  return sqrtf(x*x + y*y + z*z);
  }
  vecf_t normalize() {
  float mag = magnitude();
  return vecf_t{x/mag,y/mag,z/mag};
  }

};

static
vecf_t vecf_init(const float x, const float y, const float z) {
  vecf_t ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;

  return ret;
}

static
message_t vecf_pack(const float x, const float y, const float z) {
  vecf_t ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;

  message_t msg;

  return msg;
}



} // end namespace