
#pragma once

#include <stdint.h>
#include <string>

namespace yivo {

constexpr uint8_t VECD_MSG_SIZE = 24;

constexpr uint8_t VECD_MSG_ID = 2;

struct __attribute__((packed)) vecd_t {
  double x; // size: 8
  double y; // size: 8
  double z; // size: 8
  inline
  double normalize() { return sqrt(x*x + y*y + z*z); }

};



inline
message_t vecd_yivo_pack(const vecd_t& msg) {
  message_t msg = yivo.pack(2, (uint8_t*)&msg, 24);
  return msg;
}




} // end namespace