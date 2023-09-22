#include <gtest/gtest.h>
#include <messages.hpp>
#include <stdint.h>


TEST(messages, msg_sizes) {
  EXPECT_EQ(sizeof(date_t), 3*sizeof(uint8_t));
  EXPECT_EQ(sizeof(vec_t), 3*sizeof(float));
  EXPECT_EQ(sizeof(quat_t), 4*sizeof(float));
  EXPECT_EQ(sizeof(twist_t), 2*sizeof(vec_t));
  EXPECT_EQ(sizeof(wrench_t), 2*sizeof(vec_t));
  EXPECT_EQ(sizeof(pose_t), sizeof(vec_t) + sizeof(quat_t));
  EXPECT_EQ(sizeof(iclock_time_t), 3);
  EXPECT_EQ(sizeof(fclock_time_t), 2+4);
  EXPECT_EQ(sizeof(satnav_t), 27);
}