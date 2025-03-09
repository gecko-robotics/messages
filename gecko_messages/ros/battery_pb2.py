# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: battery.proto
# Protobuf Python Version: 5.29.3
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import runtime_version as _runtime_version
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
_runtime_version.ValidateProtobufRuntimeVersion(
    _runtime_version.Domain.PUBLIC,
    5,
    29,
    3,
    '',
    'battery.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import header_pb2 as header__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\rbattery.proto\x12\x05kevin\x1a\x0cheader.proto\"\x92\x03\n\x07\x42\x61ttery\x12\x1d\n\x06header\x18\x01 \x01(\x0b\x32\r.kevin.Header\x12\x0f\n\x07voltage\x18\x02 \x01(\x02\x12\x13\n\x0btemperature\x18\x03 \x01(\x02\x12\x0f\n\x07\x63urrent\x18\x04 \x01(\x02\x12\x0e\n\x06\x63harge\x18\x05 \x01(\x02\x12\x10\n\x08\x63\x61pacity\x18\x06 \x01(\x02\x12\x17\n\x0f\x64\x65sign_capacity\x18\x07 \x01(\x02\x12\x12\n\npercentage\x18\x08 \x01(\x02\x12$\n\x06status\x18\t \x01(\x0e\x32\x14.kevin.BatteryStatus\x12$\n\x06health\x18\n \x01(\x0e\x32\x14.kevin.BatteryHealth\x12,\n\ntechnology\x18\x0b \x01(\x0e\x32\x18.kevin.BatteryTechnology\x12\x0f\n\x07present\x18\x0c \x01(\x08\x12\x14\n\x0c\x63\x65ll_voltage\x18\r \x03(\x02\x12\x18\n\x10\x63\x65ll_temperature\x18\x0e \x03(\x02\x12\x10\n\x08location\x18\x0f \x01(\t\x12\x15\n\rserial_number\x18\x10 \x01(\t*\xa2\x01\n\rBatteryStatus\x12\x1a\n\x16\x42\x41TTERY_STATUS_UNKNOWN\x10\x00\x12\x1b\n\x17\x42\x41TTERY_STATUS_CHARGING\x10\x01\x12\x1e\n\x1a\x42\x41TTERY_STATUS_DISCHARGING\x10\x02\x12\x1f\n\x1b\x42\x41TTERY_STATUS_NOT_CHARGING\x10\x03\x12\x17\n\x13\x42\x41TTERY_STATUS_FULL\x10\x04*\xa8\x02\n\rBatteryHealth\x12\x1a\n\x16\x42\x41TTERY_HEALTH_UNKNOWN\x10\x00\x12\x17\n\x13\x42\x41TTERY_HEALTH_GOOD\x10\x01\x12\x1b\n\x17\x42\x41TTERY_HEALTH_OVERHEAT\x10\x02\x12\x17\n\x13\x42\x41TTERY_HEALTH_DEAD\x10\x03\x12\x1e\n\x1a\x42\x41TTERY_HEALTH_OVERVOLTAGE\x10\x04\x12!\n\x1d\x42\x41TTERY_HEALTH_UNSPEC_FAILURE\x10\x05\x12\x17\n\x13\x42\x41TTERY_HEALTH_COLD\x10\x06\x12(\n$BATTERY_HEALTH_WATCHDOG_TIMER_EXPIRE\x10\x07\x12&\n\"BATTERY_HEALTH_SAFETY_TIMER_EXPIRE\x10\x08*\x9e\x02\n\x11\x42\x61tteryTechnology\x12\x1e\n\x1a\x42\x41TTERY_TECHNOLOGY_UNKNOWN\x10\x00\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_NIMH\x10\x01\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_LION\x10\x02\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_LIPO\x10\x03\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_LIFE\x10\x04\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_NICD\x10\x05\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_LIMN\x10\x06\x12\x1e\n\x1a\x42\x41TTERY_TECHNOLOGY_TERNARY\x10\x07\x12\x1b\n\x17\x42\x41TTERY_TECHNOLOGY_VRLA\x10\x08\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'battery_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_BATTERYSTATUS']._serialized_start=444
  _globals['_BATTERYSTATUS']._serialized_end=606
  _globals['_BATTERYHEALTH']._serialized_start=609
  _globals['_BATTERYHEALTH']._serialized_end=905
  _globals['_BATTERYTECHNOLOGY']._serialized_start=908
  _globals['_BATTERYTECHNOLOGY']._serialized_end=1194
  _globals['_BATTERY']._serialized_start=39
  _globals['_BATTERY']._serialized_end=441
# @@protoc_insertion_point(module_scope)
