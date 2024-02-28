###############################################
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
##############################################
# -*- coding: utf-8 -*-
from .utils import parse_global
from .types import var_types
from pathlib import Path
from jinja2 import Environment
from jinja2.loaders import FileSystemLoader

# type variable len default
def c_format(type, variable, len, d):
    c = var_types[type].c
    complex = var_types[type].complex
    default = ''
    # if d:
    #     default = str(d)
    #     if default.find('[') > -1:
    #         default = default.replace('[','{').replace(']','}')
    if len > 1:
        return f"{c} {variable}[{len}]{default};"

    if complex:
        return f"{c} {variable}{default};"

    # if default == '':
    return f"{c} {variable};"

    # return f"{self.c} {self.variable} = {default};"

def create_cpp(msg, template="msg.cpp.jinja"):
    tmp_dir = Path(__file__).resolve().parent/"templates"
    # tmp_dir = Path(".").resolve()/"templates"
    # print(tmp_dir)
    env = Environment(loader=FileSystemLoader(tmp_dir))
    tmpl = env.get_template(template)
    info = parse_c(msg)
    content = tmpl.render(info)
    return content

def includes_c(msg):
    """
    """
    includes = set()
    for var in msg["message"]["vars"]:
        complex = var_types[var.type].complex
        if complex is True:
            c = var_types[var.type].c
            includes.add(f"#include \"{c}.hpp\"")

    return list(includes)

def parse_c(msg):
    """

    """
    # print(msg)

    enums = None
    enums_type = None
    if "enums" in msg:
        enums = msg["enums"]

        enums_type = "uint8_t"
        if "type" in msg["enums"]:
            enums_type = msg["enums"]["type"]

    msg_comments = None
    # if "comments" in msg["message"]:
    #     msg_comments = format_str_width(msg['message']['comments'],'  //',width)

    msginfo = var_types[msg["message"]["name"]]
    msg_size = msginfo.size

    includes = ["#include <cstdint>"]
    includes += includes_c(msg)

    vars = []
    incs = set()
    for v in msg["message"]["vars"]:
        vars.append(c_format(*v))

    c_funcs = None
    if "functions" in msg:
        if "c" in msg["functions"]:
            c_funcs = msg["functions"]["c"]

    namespace, license, yivo, mavlink, frozen, msg_id, comments = parse_global(msg, '//')

    if "id" in msg["message"]:
        msg_id = msg["message"]["id"]

    info = {
        "name": msginfo.c,              # str
        "vars": vars,                   # list of str
        "includes": includes,           # list
        "comments": comments,           # str - global comments
        "msg_comments": msg_comments,   # str - comment in msg
        "type": "uint8_t",              # str - msg_size
        "functions": c_funcs,           # list of str
        "enums": enums,                 # dict: {name: {var:value, ...}, name:...}
        "enums_type": enums_type,       # str
        "size": msg_size,               # int
        "namespace": namespace,         # str
        "mavlink": mavlink,             # bool
        "yivo": yivo,                   # bool
        "license": license,             # str
        "msg_id": msg_id                # int
    }

    return info