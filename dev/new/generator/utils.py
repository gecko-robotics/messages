

# from colorama import Fore
from collections import namedtuple
import textwrap
import tomllib
from pprint import pprint
from pathlib import Path
from .license import *

# Enum = namedtuple("Enum","var value")
Var = namedtuple("Var","type var value array_size")

# c - c type name
# py - python type name
# fmt - pack/unpack
# complex - for user defined types, more involved, try to avoid
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

def read_toml(file):
    path = Path(file)
    with path.open("rb") as f:
        data = tomllib.load(f)
    data["file"] = path
    if "message" in data:
        data = var_fix(data)

    license = None
    if "license" in data:
        # license = format_str_width(msg["license"],'#',width)
        if "type" in data["license"]:
            lic = data["license"]["type"]
            yr = data["license"]["year"]
            name = data["license"]["name"]
            if lic.upper() == "MIT":
                license = MIT_LICENSE(name, yr)
            else:
                print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
                print(data["license"])
                raise Exception("Bad license")
        elif "custom" in data["license"]:
            license = data["license"]["custom"]
        else:
            print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
            print(data["license"])
            raise Exception("Bad license")
    
    if license is not None:
        data["license"] = license
        
    return data

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
    """
    vars = []
    for k,val in data["message"].items():
        # print(k)
        try:
            type, var = k.split('-')
            array_size = 0
            if isinstance(val, list):
                array_size = len(val)
            v = Var(type,var,val, array_size)
            vars.append(v)
        except ValueError:
            continue
    
    msg = {
        "vars": vars,
        "name": data["file"].stem
    }
    if "id" in data["message"]:
        msg["id"] = data["message"]["id"],
    
    if "comments" in data["message"]:
        msg["comments"]: data["message"]["comments"]
    
    # pprint(msg)
    # license = None
    # if "license" in data:
    #     # license = format_str_width(msg["license"],'#',width)
    #     if "type" in data["license"]:
    #         lic = data["license"]["type"]
    #         yr = data["license"]["year"]
    #         name = data["license"]["name"]
    #         if lic.upper() == "MIT":
    #             license = MIT_LICENSE(name, yr)
    #         else:
    #             print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
    #             print(data["license"])
    #             raise Exception("Bad license")
    #     elif "custom" in data["license"]:
    #         license = data["license"]["custom"]
    #     else:
    #         print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
    #         print(data["license"])
    #         raise Exception("Bad license")
    
    data["message"] = msg
    # if license is not None:
    #     data["license"] = license
    return data

def write_file(filename, content):
    """
    Simple writes content to filename
    """
    filename = Path(filename)
    try:
        with filename.open("w", encoding="utf-8") as fd:
            fd.write(content)
        print(f"Wrote File: {filename}")
    except:
        print(f"Failed to write File: {filename}")

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