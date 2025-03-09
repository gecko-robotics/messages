#!/bin/bash

# get all of the protobuf messages
MSGS=$(ls proto/*.proto)

# DEST=$HOME/.local/protobuf/python
DEST=./gecko_messages/ros
mkdir -p $DEST
rm -f $DEST/*_pb2.py
protoc --python_out=$DEST --proto_path=./proto $MSGS

# DEST=$HOME/.local/protobuf/cpp
DEST=./cpp
mkdir -p $DEST
rm -fr $DEST/*_pb2.py
protoc --cpp_out=$DEST --proto_path=./proto $MSGS
