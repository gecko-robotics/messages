from gecko_messages import *
import time

def test_simple():
  now = time.time_ns()

  imu = Imu()
  imu.header.frame_id = "camera"
  imu.header.timestamp.FromNanoseconds(now)
  imu.linear_acceleration.x = 12.345
  imu.linear_acceleration.y = -12.345
  assert imu

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
  assert b

  assert MagnetometerCalibration()

  q = Quaternion()
  qq = Quaternion()
  qq.w = 1
  qq.x = 2
  qq.y = 3
  qq.z = 4
  q.from_hamilton(qq)
  assert q.w == qq.w
  assert -q.x == qq.x
  assert -q.y == qq.y
  assert -q.z == qq.z

  ts = Timestamp()
  ts.FromNanoseconds(now)
  assert ts.seconds == now // 1_000_000_000
  assert ts.nanos == now % 1_000_000_000

  assert Twist()
  assert Wrench()
  assert Pose()
  assert Pressure()