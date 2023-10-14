//////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2023 gecko-robotics
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstdint>


enum Frame : uint8_t {
  FRAME_UNKNOWN,
  FRAME_NED,
  FRAME_NEU,
  FRAME_NWU,
  FRAME_ECEF,
  FRAME_IEC,
  FRAME_BODY_STD, // z-up
  FRAME_BODY_AERO // z-down
};

enum Working_Status: uint8_t {
  STATUS_OK,       // 0
  STATUS_DEGRADED, // 1
  STATUS_FAIL,     // 2
  STATUS_UNKNOWN   // 3
};


enum IMU_Status: uint8_t {
  GOOD    = 0,
  A_FAIL  = 1,
  G_FAIL  = 2,
  M_FAIL  = 4,
  PT_FAIL = 8
};


enum Distance_Sensor : uint8_t {
  LASER      = 1,
  ULTRASOUND = 2,
  INFRARED   = 4,
  RADAR      = 8,
  LIDAR      = 16
};