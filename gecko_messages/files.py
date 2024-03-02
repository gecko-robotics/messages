###############################################
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
##############################################
# -*- coding: utf-8 -*-
try:
    import tomllib
except ImportError:
    import tomlkit as tomllib

from pathlib import Path
from .builtins import *
import sys
from pprint import pprint
from colorama import Fore

def read_toml(path):
    """
    Read toml file and return a dict
    """
    if not isinstance(path, Path):
        path = Path(file)

    with path.open("rb") as fd:
        data = tomllib.load(fd)

    return data

def read_tomls(txt):
    """
    Read toml string and return dict
    """
    return tomllib.loads(txt)

def read_folder(dir):
    """
    Read a message folder and return a dict. It is expected each
    message is in an individual toml file. Optionally there can
    be a global.toml file (all lower case) that contains info
    across each message.

    looks for:
    - global.toml # optional
    - a.toml      # message
    - b.toml      # message
    - ...

    Returns a list of dicts"""
    data_files = []
    p = Path(dir).glob('*.toml')
    files = [x for x in p if x.is_file()]

    # handle global file ------------------------------
    globalFile = False
    gf = Path(dir) / "global.toml"
    gData = {"global": None}
    if gf in files:
        gData = read_toml(gf)
        globalFile = True
        files.remove(gf)

    if "wrap_width" not in gData["global"]:
        gData["global"]["wrap_width"] = 70

    # handle builtins ----------------------------------
    for f in complex_types:
        gc = read_tomls(complex_types_global)
        for key in ["namespace","wrap_width","comments","serialization"]:
            if key in gData["global"]:
                gc["global"][key] = gData["global"][key]
        data = read_tomls(f) | gc
        # data_files[data["message"]["name"]] = data
        data_files.append(data)

    # process messages ---------------------------------
    for f in files:
        try:
            f = f.resolve()
            data = read_toml(f) | gData
            # data_files[data["message"]["name"]] = data
            data_files.append(data)
        except KeyError as e:
            print(f"{Fore.RED}KeyError:{e} in File:{f}{Fore.RESET}")
            print(f"{Fore.CYAN}{data}{Fore.RESET}")
            continue

    return data_files


def write_file(filename, content):
    """
    Simple writes content to filename
    """
    if not isinstance(filename, Path):
        filename = Path(filename)

    path = filename.parent
    path.mkdir(parents=True, exist_ok=True)

    try:
        with filename.open("w", encoding="utf-8") as fd:
            fd.write(content)
    except Exception as e:
        print(f"{filename} failed with: {e}")
        sys.exit(1)


##############################################
# def var_fix(data):
#     """
#     format variables in message properly from the TOML template
#     float-x=1 => float x
#     float-x=3 => float[3] x
#     """
#     # print(data)

#     vars = []
#     key_remove = []

#     defaults = None
#     if "defaults" in data["message"]:
#         defaults = data["message"]["defaults"]
#         data["message"].pop("defaults")

#     for k,val in data["message"].items():
#         try:
#             # there are some keys that are not variable types
#             # and we are just protecting them here
#             if k == "id":
#                 continue
#             if k == "name":
#                 continue

#             key_remove.append(k)

#             type, var = k.split('-')
#             array_size = int(val)

#             if type == "vec":
#                 v = Vec(var, array_size)
#             elif type == "quat":
#                 v = Quat(var, array_size)
#             elif type == "twist":
#                 v = Twist(var, array_size)
#             elif type == "wrench":
#                 v = Wrench(var, array_size)
#             elif type == "pose":
#                 v = Pose(var, array_size)
#             elif type.find("int") > -1 or type == "float" or type == "double":
#                 v = Scalar(var, type, array_size)
#             else:
#                 # raise Exception(f"'{type}' is unknown")
#                 v = Complex(var, type, array_size)

#             if defaults:
#                 if v.variable in defaults:
#                     v.default = defaults[v.variable]

#             # print(v)

#             vars.append(v)
#         except ValueError:
#             continue

#     # Add in new namedtuple Var array
#     data["message"]["vars"] = vars

#     # remove old keys that were replaced above with namedtuple code
#     for k in key_remove:
#         data["message"].pop(k)

#     return data
