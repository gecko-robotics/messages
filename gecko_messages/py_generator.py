# -*- coding: utf-8 -*-
from .utils import *
from .license import *
from pathlib import Path
from jinja2 import Environment
from jinja2.loaders import FileSystemLoader
from colorama import Fore # for errors
from pprint import pprint #

def create_python(msg, template="msg.py.jinja"):
    """
    Creates a python file for a message from templates found in
    the template_path
    """
    tmp_dir = Path(__file__).resolve().parent/"templates"
    # tmp_dir = Path(".").resolve()/"templates"
    env = Environment(loader=FileSystemLoader(tmp_dir))
    tmpl = env.get_template(template)
    # if msg is None:
    #     info = {}
    #     e:
    info = parse_python(msg)
    content = tmpl.render(info)
    return content

def includes_python(msg):
    """
    Formats library imports for a python message
    """
    includes = set()
    for var in msg["message"]["vars"]:
        c = var_types[var.type].complex
        if c is True:
            includes.add(f"from .{var.type} import {var.type}")
    return list(includes)

def parse_python(msg):
    """
    Parses a message and returns a dict containing the information needed
    to generate a python file for the message
    """
    # FIXME: limit to 80 cols
    width = 70

    comments = None
    if "comments" in msg:
        comments = format_str_width(msg["comments"],'#',width)

    enums = None
    if "enums" in msg:
        enums = msg["enums"]

    msg_comments = None
    if "comments" in msg["message"]:
        msg_comments = format_str_width(msg['message']['comments'],'    #',width)


    _,_,msg_size,format,_ = calc_msg_size(msg["message"]["name"], msg["message"]["vars"])

    vars = []
    for v in msg["message"]["vars"]:
        type = var_types[v.type].py
        if var_types[v.type].complex:
            # default = str(v.value)
            vars.append(f"{v.var}: list[{type}] = field(default_factory=(lambda:{v.value}))")
        else:
            vars.append(f"{v.var}: {type} = {v.value}")

    includes = []
    includes += includes_python(msg)

    funcs = None
    if "functions" in msg and "python" in msg["functions"]:
        funcs = msg["functions"]["python"]

    # namespace = None
    # license = None
    # yivo, mavlink = False, False
    # frozen = True
    # if "global" in msg:
    #     if "namespace" in msg["global"]:
    #         namespace = msg["global"]["namespace"]
    #     if "license" in msg["global"]:
    #         license = format_str_width(msg["global"]["license"], '#', width)
    #     if "ids" in msg["global"]:
    #         mtype = msg["message"]["name"]
    #         try:
    #             msg_id = msg["global"]["ids"][mtype]
    #         except KeyError:
    #             pass
    #     if "serialize" in msg:
    #         if "yivo" in msg["global"]["serialize"]:
    #             yivo = msg["global"]["serialize"]["yivo"]
    #         if "mavlink" in msg["global"]["serialize"]:
    #             mavlink = msg["global"]["serialize"]["mavlink"]
    #     if "frozen" in msg["global"]:
    #         frozen = msg["global"]["frozen"]
    namespace, license, yivo, mavlink, frozen, msg_id, comments = parse_global(msg, '#', width)

    if "id" in msg["message"]:
        msg_id = msg["message"]["id"]

    info = {
        "name": msg["message"]["name"],  # str
        "vars": vars,                    # list of str
        "includes": includes,            # list
        "comments": comments,            # str - global comments
        "msg_comments": msg_comments,    # str - comment in msg
        "functions": funcs,              # list of str
        "enums": enums,                  # dict: {name: {var:value, ...}, name:...}
        "msg_size": msg_size,            # int
        "namespace": namespace,          # str
        "mavlink": mavlink,              # bool
        "yivo": yivo,                    # bool
        "license": license,              # str
        "msg_id": msg_id,                # int
        "format": format,                # str
        "frozen": frozen,                # bool
    }

    return info
    # pprint(info)

    # tmpl = env.get_template("msg.py.jinja")
    # content = tmpl.render(info)
    # print(content)

    # filename = info["name"] + ".py"
    # filename = Path(out_path)/filename
    # write_file(filename, content)
