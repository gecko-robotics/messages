
#pragma once

#include <stdint.h>
#include <string>

namespace yivo {

constexpr uint8_t CAL_MSG_SIZE = 48;

constexpr uint8_t CAL_MSG_ID = 5;

struct __attribute__((packed)) cal_t {
  enum CAL_STATUS: uint8_t {ACCELS = 1, GYROS = 2, MAGS = 4};

  float cals[12]; // size: 4 * 12

};



inline
message_t cal_yivo_pack(const cal_t& msg) {
  message_t msg = yivo.pack(5, (uint8_t*)&msg, 48);
  return msg;
}




} // end namespace