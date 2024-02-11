

from colorama import Fore
from collections import namedtuple
import textwrap
# import tomllib
from pprint import pprint
# from pathlib import Path
from .license import *
import re

# Enum = namedtuple("Enum","var value")
Var = namedtuple("Var","type var value array_size")

# c - c type name
# py - python type name
# fmt - pack/unpack
# complex - non-standard data type
VarInfo = namedtuple("VarInfo","c py size fmt complex")

var_types = {
    # Standard scalar types --------------------------------------------------------
    "uint8":  VarInfo("uint8_t",  "int",   1, "B", False),
    "uint16": VarInfo("uint16_t", "int",   2, "H", False),
    "uint32": VarInfo("uint32_t", "int",   4, "I", False),
    "uint64": VarInfo("uint64_t", "int",   8, "Q", False),
    "int8":   VarInfo("int8_t",   "int",   1, "b", False),
    "int16":  VarInfo("int16_t",  "int",   2, "h", False),
    "int32":  VarInfo("int32_t",  "int",   4, "i", False),
    "int64":  VarInfo("int64_t",  "int",   8, "q", False),
    "float":  VarInfo("float",    "float", 4, "f", False),
    "double": VarInfo("double",   "float", 8, "d", False),
    # ROS inspired messages -------------------------------------------------------
    "vec_t":    VarInfo("vec_t",    "vec_t",    12, "3f", True), # [x y z]
    "quat_t":   VarInfo("quat_t",   "quat_t",   16, "4f", True), # [w x y z]
    "twist_t":  VarInfo("twist_t",  "twist_t",  24, "6f", True), # [linear, angular]
    "wrench_t": VarInfo("wrench_t", "wrench_t", 24, "6f", True), # [force, torque]
    "pose_t":   VarInfo("pose_t",   "pose_t",   28, "7f", True), # [position, attitude]
}

# def read_folder(dir):
#     path = Path(dir)
#     return {}

# def read_toml(file):
#     path = Path(file)
#     with path.open("rb") as f:
#         data = tomllib.load(f)

#     if "message" in data:
#         data = var_fix(data)

#     return data

# def read_tomls(txt):
#     data = tomllib.loads(txt)

#     if "message" in data:
#         data = var_fix(data)

#     return data

def print_summary(data):
    def sortFirst(val):
        return val[0]

    # print(f"Found global.toml {globalFile}")
    print(f"Found {len(data)} message files")
    sorted = []
    namespaces = set()
    for d in data:
        # print(d)
        if "namespace" in d["global"]:
            namespaces.add(d["global"]["namespace"])
        name = d["message"]["name"]
        if "id" in d["message"]:
            id = d["message"]["id"]
        else:
            id = d["global"]["ids"][name]
        sorted.append((id, name))

    sorted.sort(key=sortFirst)
    namespaces = list(namespaces)
    if len(namespaces) > 0:
        if len(namespaces) == 1:
            print(f"Namespace: {namespaces[0]}")
        else:
            print(f"Namespaces: {', '.join(namespaces)}")

    print(f" {Fore.GREEN}MsgID{Fore.RESET} NAME")
    print("------------------------")
    for s in sorted:
        if s[0] < 10:
            print(f" - {Fore.GREEN}{s[0]:3} {Fore.MAGENTA}{s[1]}{Fore.RESET}")
        else:
            print(f" - {s[0]:3} {s[1]}")

# def read_folder(dir):
#     data_files = []
#     p = Path(dir).glob('*.toml')
#     files = [x for x in p if x.is_file()]

#     # handle global file ------------------------------
#     globalFile = False
#     gf = Path(dir) / "global.toml"
#     gData = {}
#     if gf in files:
#         with gf.open("rb") as f:
#             gData = tomllib.load(f)
#         globalFile = True
#         files.remove(gf)

#     # handle builtins ----------------------------------
#     for f in complex_types:
#         data = tomllib.loads(f) | gData

#         if "message" in data:
#             data = var_fix(data)

#         data_files.append(data)

#     # print results ------------------------------------
#     # print(f"Found global.toml {globalFile}")
#     # print(f"Found {len(files)} message files in {dir}")

#     # process messages ---------------------------------
#     for f in files:
#         # print(f" - {f.name}")
#         with f.open("rb") as fd:
#             data = tomllib.load(fd) | gData

#             if "message" in data:
#                 data = var_fix(data)

#             # pprint(data)

#             data_files.append(data)
#     return data_files

def calc_msg_size(name, vars):
    """
    Adds user defined variables to the var_types dict so they can
    be used in other messages.
    """
    if name in var_types:
        return var_types[name]

    msg_size = 0
    format = ''
    for v in vars:
        if v.array_size > 0 and not var_types[v.type].complex:
            msg_size += var_types[v.type].size * v.array_size
            format += str(v.array_size) + var_types[v.type].fmt
        else:
            msg_size += var_types[v.type].size
            format += var_types[v.type].fmt

    new_var = VarInfo(name, name, msg_size, format, True)
    var_types[name] = new_var
    return new_var

def var_fix(data):
    """
    format variables in message properly from the TOML template
    float-x => float x
    float_3_x => float[3] x
    """
    vars = []
    key_remove = []
    m = re.compile(r'([a-zA-Z0-9_]+)')
    for k,val in data["message"].items():
        try:
            # there are some keys that are not variable types
            # and we are just protecting them here
            if k == "id":
                continue
            if k == "name":
                continue

            key_remove.append(k)

            mm = m.findall(k)
            if len(mm) == 2:
                type, var = mm
                array_size = 0
            elif len(mm) == 3:
                type, array_size, var = mm
            else:
                raise Exception(f"Error parsing message vars: {k}:{val}")
            v = Var(type,var,val,int(array_size))
            vars.append(v)
        except ValueError:
            continue

    # Add in new namedtuple Var array
    data["message"]["vars"] = vars

    # remove old keys that were replaced above with namedtuple code
    for k in key_remove:
        data["message"].pop(k)

    return data

# def write_file(filename, content):
#     """
#     Simple writes content to filename
#     """
#     filename = Path(filename)
#     try:
#         with filename.open("w", encoding="utf-8") as fd:
#             fd.write(content)
#         print(f"Wrote File: {filename}")
#     except:
#         print(f"Failed to write File: {filename}")

def format_str_width(s, sym, width=70):
    """
    Formates the string to a defined column width and adds the
    desired symbol for a comment to the beginning of each line.
    This doesn't break words up.
    """
    l = s.split('\n')
    sym += ' '
    ll = ["\n".join(textwrap.wrap(s, width-2,initial_indent=sym,subsequent_indent=sym)) for s in l]
    c = "\n".join(ll)
    return c

def parse_global(msg, sym, width):
    namespace = None
    license = None
    yivo, mavlink = False, False
    frozen = True
    msg_id = None
    comments = None
    if "global" in msg:
        if "namespace" in msg["global"]:
            namespace = msg["global"]["namespace"]
        if "license" in msg["global"]:
            license = format_str_width(msg["global"]["license"], sym, width)
        if "ids" in msg["global"]:
            mtype = msg["message"]["name"]
            try:
                msg_id = msg["global"]["ids"][mtype]
            except KeyError:
                pass
        if "serialize" in msg:
            if "yivo" in msg["global"]["serialize"]:
                yivo = msg["global"]["serialize"]["yivo"]
            if "mavlink" in msg["global"]["serialize"]:
                mavlink = msg["global"]["serialize"]["mavlink"]
        if "frozen" in msg["global"]:
            frozen = msg["global"]["frozen"]
        if "comments" in msg["global"]:
            comments = format_str_width(msg["global"]["comments"],sym,width)
    return namespace, license, yivo, mavlink, frozen, msg_id, comments

# def recurse(k,v, indent=0):
#     print(f"{Fore.CYAN}{k}{Fore.RESET}")
#     i_len = ' '*indent
#     if isinstance(v, dict):
#         for kk,vv in v.items():
#             if isinstance(vv, dict):
#                 recurse(kk,vv, indent+1)
#             else:
#                 # ks = kk.split('-')
#                 # if len(ks) > 1:
#                 #     print(f"{Fore.GREEN}{ks[0]}{Fore.RESET} {ks[1]}: {vv}")
#                 if isinstance(vv, list):
#                     for v in vv:
#                         if v.array_size == 0:
#                             print(f"{i_len}{Fore.YELLOW}{v.type} {Fore.BLUE}{v.var}{Fore.RESET}: {v.value}")
#                         else:
#                             print(f"{i_len}{Fore.YELLOW}{v.type}[{v.array_size}] {Fore.BLUE}{v.var}{Fore.RESET}: {v.value}")
#                 # elif isinstance(vv, str):
#                 elif kk.lower() == "comments":
#                     print(f"{i_len}{kk}: {Fore.GREEN}{vv}{Fore.RESET}")
#                 else:
#                     print(f"{i_len}{kk}: {vv}")
#     else:
#         print(f"{i_len}{v}")