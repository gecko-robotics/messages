
#pragma once

#include <stdint.h>
#include <string>

namespace yivo {

constexpr uint8_t VECD_MSG_SIZE = 24;



struct __attribute__((packed)) vecd_t {
  double x;
  double y;
  double z;
  inline
  double normalize() { return sqrt(x*x + y*y + z*z); }

};

static
vecd_t vecd_init(const double x, const double y, const double z) {
  vecd_t ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;

  return ret;
}

static
message_t vecd_pack(const double x, const double y, const double z) {
  vecd_t ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;

  message_t msg;

  return msg;
}



} // end namespace