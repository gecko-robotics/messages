# -*- coding: utf-8 -*-
from .utils import *
from .license import *
from pathlib import Path
from jinja2 import Environment
from jinja2.loaders import FileSystemLoader
from colorama import Fore # for errors
from pprint import pprint #

def create_python(msg, template_path, template="msg.py.jinja"):
    """
    Creates a python file for a message from templates found in
    the template_path
    """
    # tmp_dir = Path(__file__).resolve().parent/"templates"
    tmp_dir = Path(template_path)
    env = Environment(loader=FileSystemLoader(tmp_dir))
    tmpl = env.get_template(template)
    info = parse_python(msg)
    content = tmpl.render(info)
    return content

def includes_python(inc):
    """
    Formats library imports for a python message
    """
    includes = set()
    if isinstance(inc, str):
        includes.add(f"{inc}")
    else:
        for i in inc:
            includes.add(f"{i}")
    return list(includes)
    
def parse_python(msg):
    """
    Parses a message and returns a dict containing the information needed
    to generate a python file for the message
    """
    # FIXME: limit to 80 cols
    width = 80

    comments = None
    if "comments" in msg:
        comments = format_str_width(msg["comments"],'#',width)

    enums = None
    if "enums" in msg:
        enums = msg["enums"]

    license = None
    if "license" in msg:
        # # license = format_str_width(msg["license"],'#',width)
        # if "type" in msg["license"]:
        #     lic = msg["license"]["type"]
        #     yr = msg["license"]["year"]
        #     name = msg["license"]["name"]
        #     if lic.upper() == "MIT":
        #         license = MIT_LICENSE(name, yr)
        #     else:
        #         print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
        #         print(msg["license"])
        #         raise Exception("Bad license")
        # elif "custom" in msg["license"]:
        #     license = msg["license"]["custom"]
        # else:
        #     print(f"{Fore.RED}ERROR: Unknown license{Fore.RESET}")
        #     print(msg["license"])
        #     raise Exception("Bad license")
        license = format_str_width(msg["license"], '#', width)

    msg_comments = None
    if "comments" in msg["message"]:
        msg_comments = format_str_width(msg['message']['comments'],'    #',width)

    
    _,_,msg_size,format,_ = calc_msg_size(msg["message"]["name"], msg["message"]["vars"])
    
    vars = []
    for v in msg["message"]["vars"]:
        type = var_types[v.type].py
        if v.array_size > 0:
            # default = str(v.value)
            vars.append(f"{v.var}: list[{type}] = {v.value}")
        else:
            vars.append(f"{v.var}: {type} = {v.value}")

    includes = None
    if "libraries" in msg and "python" in msg["libraries"]:
        includes = includes_python(msg["libraries"]["python"])

    funcs = None
    if "functions" in msg and "python" in msg["functions"]:
        funcs = msg["functions"]["python"]

    yivo, mavlink = False, False
    if "serialize" in msg:
        if "yivo" in msg["serialize"]:
            yivo = msg["serialize"]["yivo"]
        if "mavlink" in msg["serialize"]:
            mavlink = msg["serialize"]["mavlink"]
    
    if "id" in msg["message"]:
        msg_id = msg["message"]["id"]
    elif "ids" in msg:
        mtype = msg["message"]["name"]
        msg_id = msg["ids"][mtype]
    else:
        print(f"ERROR: can't find id in toml")
        raise Exception()
        
    info = {
        "name": msg["message"]["name"],  # str
        "vars": vars,                    # list of str
        "includes": includes,            # list
        "comments": comments,            # str - global comments
        "msg_comments": msg_comments,    # str - comment in msg
        "functions": funcs,              # list of str
        "enums": enums,                  # dict: {name: {var:value, ...}, name:...}
        "msg_size": msg_size,            # int
        "namespace": msg["namespace"],   # str
        "mavlink": mavlink,              # bool
        "yivo": yivo,                    # bool
        "license": license,              # str
        "msg_id": msg_id,  # int
        "format": format                 # str
    }

    return info
    # pprint(info)
    
    # tmpl = env.get_template("msg.py.jinja")
    # content = tmpl.render(info)
    # print(content)

    # filename = info["name"] + ".py"
    # filename = Path(out_path)/filename
    # write_file(filename, content)
    