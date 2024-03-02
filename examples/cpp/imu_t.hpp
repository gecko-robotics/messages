//// Do not edit, this is autogenerated ////
//
// The MIT License (MIT)
// Copyright (c) 2023 Kevin Walchko
// see LICENSE for full details
///////////////////////////////////////////////////////////
#pragma once
#include <cstdint>
#include "z.hpp"
#include "vec_t.hpp"



namespace msgs {

constexpr uint8_t MSG_SIZE_IMU_T = 60;
constexpr uint8_t MSG_ID_IMU_T = 10;


struct __attribute__((packed)) imu_t {

  enum Health: uint8_t {
    OK=0,
  };


  vec_t accels;
  vec_t gyros;
  vec_t mags;
  float pressure;
  float temperature;
  uint32_t time;
  z dummy;
};







} // end namespace msgs
