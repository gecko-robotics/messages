from gecko_messages import *
import time

def test_simple():
  now = time.time_ns()

  imu = Imu()
  imu.header.frame_id = "camera"
  imu.header.timestamp.FromNanoseconds(now)
  imu.linear_acceleration.x = 12.345
  imu.linear_acceleration.y = -12.345

  v = Vector3()
  v.x = 1
  v.y = 2
  v.z = 3.4567
  s = v.SerializeToString()
  assert isinstance(s, bytes)
  vv = Vector3()
  vv.ParseFromString(s)
  assert v.x == vv.x
  assert v.y == vv.y
  assert v.z == vv.z

  b = Battery()
  b.voltage = 11.1
  b.status = BatteryStatus.BATTERY_STATUS_FULL

  c = MagnetometerCalibration()
  q = Quaternion()
  t = Twist()
  w = Wrench()
  p = Pose()
  p = Pressure()
  assert True