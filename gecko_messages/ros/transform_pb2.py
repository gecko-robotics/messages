# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: transform.proto
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
    'transform.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import vector3_pb2 as vector3__pb2
import quaternion_pb2 as quaternion__pb2
import header_pb2 as header__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0ftransform.proto\x12\x05kevin\x1a\rvector3.proto\x1a\x10quaternion.proto\x1a\x0cheader.proto\"R\n\tTransform\x12 \n\x08position\x18\x01 \x01(\x0b\x32\x0e.kevin.Vector3\x12#\n\x08rotation\x18\x02 \x01(\x0b\x32\x11.kevin.Quaternion\"\x90\x01\n\x10TransformStamped\x12\x1d\n\x06header\x18\x01 \x01(\x0b\x32\r.kevin.Header\x12\x16\n\x0e\x63hild_frame_id\x18\x02 \x01(\t\x12 \n\x08position\x18\x03 \x01(\x0b\x32\x0e.kevin.Vector3\x12#\n\x08rotation\x18\x04 \x01(\x0b\x32\x11.kevin.Quaternion\"9\n\nTransforms\x12+\n\ntransforms\x18\x01 \x03(\x0b\x32\x17.kevin.TransformStampedb\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'transform_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_TRANSFORM']._serialized_start=73
  _globals['_TRANSFORM']._serialized_end=155
  _globals['_TRANSFORMSTAMPED']._serialized_start=158
  _globals['_TRANSFORMSTAMPED']._serialized_end=302
  _globals['_TRANSFORMS']._serialized_start=304
  _globals['_TRANSFORMS']._serialized_end=361
# @@protoc_insertion_point(module_scope)
