# Mavlink Messages

| ID  | Message               | Description |
|-----|-----------------------|-------------|
| 0   | `heartbeat`           |
| 1   | `sys_status`          | sensors, battery, errors, dropped packets
| 2   | `system_time`         | replaced ping, time since epoch/boot
| 24  | `gps_raw`             |
| 27  | `raw_imu`             | `int16_t` for accel, gyro, mag, temp and `uint64_t` time
| 31  | `attitude_quaternion` | quaternion and time
| 32  | `local_position_ned`  | pos/vel in NED and time
| 33  | `global_position_int` | all int lat/lon/alt and vel
| 105 | `highres_imu`         |
| 132 | `distance_sensor`     |
| 242 | `home_position`       |
| 243 | `set_home_position`   |