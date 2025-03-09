#!/usr/bin/env python3
from gecko_messages import *
import time
import threading
import socket
import os

run = True

def server(addr):
  global run
  msgs = 0
  try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.settimeout(0.01)
    sock.bind(addr)
  except Exception as ex:
    print(ex)
    assert False
    return
  
  while run:
    try:
      data, address = sock.recvfrom(32)
    except socket.timeout:
      continue

    if len(data) > 0:
      msgs += 1
      msg = Vector3()
      msg.ParseFromString(data)
      print(f"Messages recieved[{msgs}] from {address}: {msg}")

  sock.close()
  run = False

def client(addr):
  global run

  try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # sock.settimeout(0.01)
  except Exception as ex:
    print(ex)
    assert False
    return

  
  for i in range(5):
    v = Vector3()
    v.x = i
    v.y = i
    v.z = i
    s = v.SerializeToString()
    sock.sendto(s, addr)

    time.sleep(0.1)

  sock.close()
  run = False

def test_udp():
  addr = ("0.0.0.0", 9999,)

  s = threading.Thread(target=server, args=(addr,), name="server")
  s.start()
  print('Started {}'.format(s.name))

  time.sleep(0.5)

  c = threading.Thread(target=client, args=(addr,), name="client")
  c.start()
  print('Started {}'.format(c.name))

  s.join()
  c.join()

  # for p in [s, c]:
  #   print('{} is alive: {}'.format(p.name, p.is_alive()))

  assert True