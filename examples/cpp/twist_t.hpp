//// Do not edit, this is autogenerated ////
//
// The MIT License (MIT)
// Copyright (c) 2023 Kevin Walchko
// see LICENSE for full details
///////////////////////////////////////////////////////////
#pragma once
#include <cstdint>
#include "vec_t.hpp"



namespace msgs {

constexpr uint8_t MSG_SIZE_TWIST_T = 24;
constexpr uint8_t MSG_ID_TWIST_T = 3;


struct __attribute__((packed)) twist_t {

  vec_t linear;
  vec_t angular;
};







} // end namespace msgs
