from gecko_messages import *
from math import sqrt

def test_tuples():
  d = distortion_t(1,2,3,4,5)
  assert d.to_list() == (1,2,3,4,5)

  c = camera_params_t(1,2,3,4)
  m = c.to_list()
  assert m[0] == (1,0,3)
  assert m[1] == (0,2,4)
  assert m[2] == (0,0,1)

  q = quaternion_t(1,2,3,4)
  m = q.mag()
  u = q.unit()
  assert (m - sqrt(1**2 + 2**2 + 3**2 + 4**2)) < 1E-9
  assert (u.mag() - 1.0) < 1E-9

  v = vector_t(1,2,3)
  m = v.mag()
  u = v.unit()
  assert (m - sqrt(1**2 + 2**2 + 3**2)) < 1E-9
  assert (u.mag() - 1.0) < 1E-9

  r = resolution_t(200,100)
  assert r.width == 200
  assert r.height == 100