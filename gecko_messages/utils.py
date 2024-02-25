###############################################
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
##############################################
# -*- coding: utf-8 -*-

from colorama import Fore
from collections import namedtuple
import textwrap
from .types import *

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
        if v.len > 1 and not v.complex:
            # msg_size += var_types[v.type].size * v.len
            msg_size += v.size * v.len
            format += str(v.len) + v.fmt
        else:
            msg_size += v.size
            format += v.fmt

    new_var = VarInfo(name, name, msg_size, format, True,0)
    var_types[name] = new_var
    return new_var

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

