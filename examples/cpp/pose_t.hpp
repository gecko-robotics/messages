//// Do not edit, this is autogenerated ////
//
// The MIT License (MIT)
// Copyright (c) 2023 Kevin Walchko
// see LICENSE for full details
///////////////////////////////////////////////////////////
#pragma once
#include <cstdint>
#include "quat_t.hpp"
#include "vec_t.hpp"



namespace msgs {

constexpr uint8_t MSG_SIZE_POSE_T = 28;
constexpr uint8_t MSG_ID_POSE_T = 5;


struct __attribute__((packed)) pose_t {

  vec_t position;
  quat_t orientation;
};







} // end namespace msgs
