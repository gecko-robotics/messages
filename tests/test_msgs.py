from gecko_messages import *
import time

def test_dummy():
  now = time.time_ns()

  imu = Imu()
  imu.header.frame_id = "camera"
  imu.header.timestamp.FromNanoseconds(now)
  imu.linear_acceleration.x = 12.345
  imu.linear_acceleration.y = -12.345
  # print(imu)

  v = Vector3()
  v.x = 1
  v.y = 2
  v.z = 3.4567
  # print(v)

  b = Battery()
  b.voltage = 11.1
  b.status = BatteryStatus.BATTERY_STATUS_FULL
  # print(b)
  assert True