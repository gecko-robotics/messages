#!/usr/bin/env python3
from jinja2 import Environment
from jinja2.loaders import FileSystemLoader
import re
# import os
# import argparse
# import sys
import pathlib
from collections import namedtuple
import logging
from colorama import Fore
# from struct import Struct


# logging: DEBUG ERROR INFO
logging.basicConfig(format='>> %(message)s', level=logging.ERROR)
logger = logging.getLogger(__name__)

env = Environment(loader=FileSystemLoader("templates"))

# Add:
# py - python name
# fmt - pack/unpack
# complex - for user defined types, more involved
VarInfo = namedtuple("VarInfo","c py size fmt complex")
Field = namedtuple("Field", "type array_size var comment")

class Enums:
    def __init__(self, name, size=None):
        self.name = name
        self.size = size
        self.values = []

var_types = {
    "uint8": VarInfo("uint8_t", "int",1, "B", False),
    "uint16": VarInfo("uint16_t", "int",2, "H", False),
    "uint32": VarInfo("uint32_t", "int", 4, "I", False),
    "uint64": VarInfo("uint64_t", "int",8, "Q", False),
    "int8": VarInfo("int8_t", "int",1, "b", False),
    "int16": VarInfo("int16_t", "int", 2, "h", False),
    "int32": VarInfo("int32_t", "int", 4, "i", False),
    "int64": VarInfo("int64_t", "int", 8, "q", False),
    "float": VarInfo("float", "float", 4, "f", False),
    "double": VarInfo("double", "float", 8, "d", False),
    # "T": VarInfo("T",0),
}

class MsgParts:
    """
    Breaks a message format appart and stores the results so it can be
    converted into other languages. Supported languages:
    - python
    - C/C++
    """
    def __init__(self):
        self.comments = [] # comments in body of message prototype
        self.fields = []   # variables in message
        self.includes = [] # included message headers/modules
        self.c_funcs = []  # custom C functions
        self.py_funcs = [] # custom Python functions
        self.enums = []    # enums
        self.msg_size = 0  # size of message in bytes
        self.file = None   # filename for naming the message
        self.id = 0        # message id number

    def __repr__(self):
        return str(self)

    def __str__(self):
        ret = f"{Fore.YELLOW}------------------------------\n"
        ret += f"File: {self.file}\n"
        ret += f"------------------------------\n{Fore.RESET}"
        ret += f"{Fore.CYAN}Comments:\n{Fore.RESET}"
        ret += f"{Fore.GREEN}"
        for c in self.comments:
            ret += f" {c}\n"
        ret += f"{Fore.RESET}"

        ret += f"\n{Fore.CYAN}Fields:\n{Fore.RESET}"
        for f in self.fields:
            ret += f" {f}\n"

        ret += f"\n{Fore.CYAN}Python Functions:\n{Fore.RESET}"
        for f in self.py_funcs:
            ret += f" {f}\n"

        ret += f"\n{Fore.CYAN}C Functions:\n{Fore.RESET}"
        for f in self.c_funcs:
            ret += f" {f}\n"

        ret += f"\n{Fore.CYAN}Includes:\n{Fore.RESET}"
        ret += f"{Fore.BLUE}"
        for i in self.includes:
            ret += f" {i}\n"
        ret += f"{Fore.RESET}\n"

        ret += f"\n{Fore.CYAN}Enums:\n{Fore.RESET}"
        for f in self.enums:
            ret += f" {f}\n"

        ret += f"{Fore.CYAN}\nMessage Size:{Fore.RESET} {self.msg_size}\n"
        return ret

def write_file(filename, content):
    # filename = "python/" + msg_parts.file.stem + ".py"
    with open(filename, mode="w", encoding="utf-8") as fd:
        fd.write(content)
        print(f"Wrote File: {filename}")

def tokenize(file):
    # regex
    # ([\w]+) *([\w]+) *([#\w_ ]*)
    # Everything is either:
    # - comment: starts with #
    # - include
    # - enum: start "<enum" and end "enum>"
    # - c function: start "<c" and end "c>"
    # - python function: start "<p" and end "p>"
    # - variable: <type> <name> <comment>
    # - array: <type[N]> <name> <comment>

    with file.open() as fd:
        lines = fd.read()

    mp = MsgParts()
    mp.file = file
    c_func_open = False
    py_func_open = False
    enum_open = False
    enums = None
    reg = re.compile(r'([\w\[\]]+) *([\w]+) *([#\w_ ]*)')

    for line in lines.split('\n'):
        line = line.rstrip().lstrip()
        if len(line) == 0: continue

        if line.find("<c") == 0:
            c_func_open = True
            continue
        if line.find("c>") == 0:
            c_func_open = False
            continue

        if c_func_open:
            mp.c_funcs.append(line)
            continue

        if line.find("<p") == 0:
            py_func_open = True
            continue
        if line.find("p>") == 0:
            py_func_open = False
            continue

        if py_func_open:
            mp.py_funcs.append(line)
            continue

        if line.find("<enum") == 0:
            # <enum name size
            toks = line.split(" ")
            enums = Enums(toks[1].upper())
            if len(toks) == 3: enums.size = toks[2]
            enum_open = True
            continue
        if line.find("enum>") == 0:
            enum_open = False
            mp.enums.append(enums)
            enums = None
            continue
        if enum_open:
            enums.values.append(line.upper())
            continue

        if line[0] == "#":
            mp.comments.append(line)
            continue

        toks = reg.findall(line)[0]
        logger.info(f"{toks}")

        if toks[0] == "include":
            mp.includes.append(toks[1])
            continue

        typ, var, comment = toks
        if len(comment) == 0: comment = "# "

        # find array brackets in typ
        array_size = 0
        left = typ.find('[')
        right = typ.find(']')
        if left > 0 and right > 0: # array found
            array_size = int(typ[left+1:right])
            typ = typ[:left]
            mp.msg_size += var_types[typ].size*array_size
            comment += f"size: {var_types[typ].size} * {array_size}"
        else: # scalar
            mp.msg_size += var_types[typ].size
            comment += f"size: {var_types[typ].size}"

        args = Field(typ, array_size, var, comment)
        mp.fields.append(args)
        # else:
        #     logger.error(f"invalid line: {subline} -> {toks}")

    return mp

def create_python(msg_parts):
    comments = []
    for c in msg_parts.comments:
        comments.append(c)

    func_args = []
    for t, ars, v, c in msg_parts.fields:
        func_args.append(v)

    includes = []
    for i in msg_parts.includes:
        ii = f'from {i} import *'
        includes.append(ii)

    vars = []
    for t, ars, v, c in msg_parts.fields:
        line = f"{v}: {var_types[t].py}"
        if c: line += f" {c}"
        vars.append(line)

    # env = Environment(loader=FileSystemLoader("templates"))
    tmpl = env.get_template("msg2.py.jinja")
    info = {
        "name": msg_parts.file.stem,
        "vars": vars,
        "includes": includes,
        "msg_size": msg_parts.msg_size,
        # "msg_size_type": "uint8_t",
        "comments": comments,
        "args": func_args,
        "functions": msg_parts.py_funcs,
        "enums": msg_parts.enums,
        "format": var_types[ msg_parts.file.stem ].fmt,
        "msgid": msg_parts.id,
        "license_notice": msg_parts.license_notice
    }
    content = tmpl.render(info)

    filename = "python/" + msg_parts.file.stem + ".py"
    write_file(filename, content)


def create_c_header(msg_parts):
    """
    struct
        - vars: string, "int bob[2];"

    functions
        - func_args: tuple(type, var_name), ("int","bob[2]")
    """
    comments = []
    for c in msg_parts.comments:
        c = c.replace("#", "//")
        comments.append(c)

    func_args = []
    for t, ars, v, c in msg_parts.fields:
        if var_types[t].complex: t = var_types[t].c + "&"
        else: t = var_types[t].c
        if ars > 0:
            vv = f"{v}[{ars}]"
        else:
            vv = f"{v}"

        func_args.append((t,vv,v))

    includes = []
    for i in msg_parts.includes:
        ii = f'#include "{i}.h"'
        includes.append(ii)

    vars = []
    for t, ars, v, c in msg_parts.fields:
        if ars == 0: line = f"{var_types[t].c} {v};"
        else: line = f"{var_types[t].c} {v}[{ars}];"
        if c: line += f" {c.replace('#','//')}"
        vars.append(line)

    # env = Environment(loader=FileSystemLoader("templates"))
    tmpl = env.get_template("msg.cpp.jinja")
    info = {
        "name": msg_parts.file.stem,
        "vars": vars,
        "includes": includes,
        "msg_size": msg_parts.msg_size,
        "msg_size_type": "uint8_t",
        "comments": comments,
        "args": func_args,
        "functions": msg_parts.c_funcs,
        "enums": msg_parts.enums,
        "msgid": msg_parts.id,
        "license_notice": msg_parts.license_notice
    }
    content = tmpl.render(info)

    filename = "c/" + msg_parts.file.stem + ".h"
    # with open(filename, mode="w", encoding="utf-8") as fd:
    #     fd.write(content)
    #     print(f"Wrote C Header: {filename}")
    write_file(filename, content)


def main(path):
    path = pathlib.Path(path).absolute()


    tmpl = env.get_template("base.py.jinja")
    info = {
        "license_notice": "MIT Kevin Walchko (c) 2023"
    }
    content = tmpl.render(info)
    filename = "python/base.py"
    write_file(filename, content)

    files = {
        1: path/"vec.yivo",
        2: path/"quat.yivo",
        # path/"vec.yivo", not doing templates
        4: path/"imu.yivo",
        5: path/"cal.yivo"
    }
    for msgid, file in files.items():
        msg_parts = tokenize(file)
        msg_parts.id = msgid
        msg_parts.license_notice = "MIT Kevin Walchko (c) 2023"
        print(msg_parts)

        fmt = ""
        for v in msg_parts.fields:
            if v.array_size > 0:
                fmt += str(v.array_size) + var_types[v.type].fmt
            else:
                fmt += var_types[v.type].fmt

        var_types[file.stem] = VarInfo(file.stem+"_t", file.stem+"_t", msg_parts.msg_size,fmt,True)

        create_c_header(msg_parts)
        create_python(msg_parts)

    # for k, v in var_types.items():
    #     print(f"{k}: {v}")

main("./messages")







# def tokenize(file):
#     # regex
#     # ([\w]+) *([\w]+) *([#\w_ ]*)

#     with file.open() as fd:
#         lines = fd.read()

#     mp = MsgParts()
#     mp.file = file
#     func_open = False

#     for line in lines.split('\n'):
#         line = line.rstrip().lstrip()
#         if len(line) == 0: continue

#         if line.find("<c") ==0:
#             func_open = True
#             continue
#         if line.find("c>") == 0:
#             func_open = False
#             continue

#         if func_open:
#             mp.c_funcs.append(line)
#             continue

#         i = line.find("#")
#         logger.info(f"comment: {i} {line}")

#         if (i == 0):
#             mp.comments.append(line)
#             continue
#         elif i > 0:
#             subline = line[:i].rstrip().lstrip()
#             comment = line[i:].rstrip().lstrip()
#         else:
#             subline = line.rstrip().lstrip()
#             comment = None

#         logger.info(f"subline: {subline}  comment: {comment}")

#         toks = subline.split(" ")
#         toks = [x for x in toks if x] # remove "" in array
#         logger.info(f"toks: {toks}")

#         if len(toks) == 2:
#             a, b = toks
#             if a == "include":
#                 mp.includes.append(b)
#             else:
#                 typ, var = a, b
#                 mp.msg_size += var_types[typ].size
#                 name = var_types[typ].c
#                 args = Field(name, var, comment)
#                 mp.fields.append(args)
#         else:
#             logger.error(f"invalid line: {subline} -> {toks}")

#     return mp