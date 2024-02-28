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

constexpr uint8_t MSG_SIZE_Z = 12;
constexpr uint8_t MSG_ID_Z = 21;


struct __attribute__((packed)) z {

  vec_t accels;
};







} // end namespace msgs
