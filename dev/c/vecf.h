
#pragma once

#include <stdint.h>
#include <string>

namespace yivo {

constexpr uint8_t VECF_MSG_SIZE = 12;

constexpr uint8_t VECF_MSG_ID = 1;

struct __attribute__((packed)) vecf_t {
  enum VECF_STATUS: uint32_t {NULL = 0, BIG = 1, SMALL = 2, HUGE = 4};

  enum VECF_BIG_NAME: uint8_t {A, B, C};

  float x; // size: 4
  float y; // size: 4
  float z; // size: 4
  float magnitude() {
  // something
  return sqrtf(x*x + y*y + z*z);
  }
  vecf_t normalize() {
  float mag = magnitude();
  return vecf_t{x/mag,y/mag,z/mag};
  }

};



inline
message_t vecf_yivo_pack(const vecf_t& msg) {
  message_t msg = yivo.pack(1, (uint8_t*)&msg, 12);
  return msg;
}




} // end namespace