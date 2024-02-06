
from .utils import *
from .license import *
from pathlib import Path
from jinja2 import Environment
from jinja2.loaders import FileSystemLoader


def create_c_header(msg, template_path, template="msg.cpp.jinja"):
    # tmp_dir = Path(__file__).resolve().parent/"templates"
    tmp_dir = Path(template_path)
    env = Environment(loader=FileSystemLoader(tmp_dir))
    tmpl = env.get_template(template)
    info = parse_c(msg)
    content = tmpl.render(info)
    return content

def includes_c(msg):
    """
     'message': {'name': 'quat_t',
             'vars': [Var(type='float', var='w', value=1, array_size=0),
                      Var(type='float', var='x', value=0, array_size=0),
                      Var(type='float', var='y', value=0, array_size=0),
                      Var(type='float', var='z', value=0, array_size=0)]},
                      
    REMOVE: local, global
    REPLACE: c = ['"vec_t"', "<cstdint>"]
    Libraries aren't working right ... not in header
    """
    includes = set()
    for var in msg["message"]["vars"]:
        c = var_types[var.type].complex
        if c is True:
            includes.add(f"#include \"{var.type}.hpp\"")
    return list(includes)
    # if local:
    #     if "local" not in msg:
    #         return []
    #     inc = msg["local"]
    #     op = '"'
    #     cl = '"'
    # else:
    #     if "global" not in msg:
    #         return []
    #     inc = msg["global"]
    #     op = "<"
    #     cl = ">"

    # includes = set()
    # if isinstance(inc, str):
    #     includes.add(f"#include {op}{inc}{cl}")
    # else:
    #     for i in inc:
    #         includes.add(f"#include {op}{i}{cl}")
    # return list(includes)
        
def parse_c(msg):
    """
    
    """
    # FIXME: limit to 80 cols
    width = 80

    comments = None
    if "comments" in msg:
        comments = format_str_width(msg["comments"],'//',width)

    enums = None
    enums_type = None
    if "enums" in msg:
        enums = msg["enums"]

        enums_type = "uint8_t"
        if "type" in msg["enums"]:
            enums_type = msg["enums"]["type"]

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
        license = format_str_width(msg["license"], '//', width)

    msg_comments = None
    if "comments" in msg["message"]:
        msg_comments = format_str_width(msg['message']['comments'],'  //',width)

    _,_,msg_size,_,_ = calc_msg_size(msg["message"]["name"], msg["message"]["vars"])
    
    includes = ["#include <cstdint>"]
    includes += includes_c(msg)
    # if "libraries" in msg:
    #     if "c" in msg["libraries"]:
    #         includes = includes_c(msg["libraries"]["c"], local=True)
    #         includes += includes_c(msg["libraries"]["c"], local=False)
    
    vars = []
    incs = set()
    for v in msg["message"]["vars"]:
        complex = var_types[v.type].complex
        # if complex:
        #     incs.add(f"#include \"{v.type}.hpp\"")
        if v.array_size > 0 and not complex:
            # default = str(v.value).replace('[','{').replace(']','}')
            default = str([0]*v.array_size).replace('[','{').replace(']','}')
            vars.append(f"{v.type}[{v.array_size}] {v.var}{default};")
        else:
            # so complex user types (e.g., vec_t) default to an array, but
            # you want vec_t{0,0,0} and not vec_t[3]{0,0,0}
            if complex:
                default = str(v.value).replace('[','{').replace(']','}')
                vars.append(f"{v.type} {v.var}{default};")
            else:
                vars.append(f"{v.type} {v.var} = {v.value};")
    # print(incs)
    # if len(incs) > 0:
    #     if includes is None:
    #         includes = []
    #     includes += list(incs)
    # print(includes)

    c_funcs = None
    if "functions" in msg:
        if "c" in msg["functions"]:
            c_funcs = msg["functions"]["c"]

    yivo, mavlink = False, False
    if "serialize" in msg:
        if "yivo" in msg["serialize"]:
            yivo = msg["serialize"]["yivo"]
        if "mavlink" in msg["serialize"]:
            mavlink = msg["serialize"]["mavlink"]

    namespace = None
    if "global" in msg:
        if "namespace" in msg["global"]:
            namespace = msg["global"]["namespace"]

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
        "type": "uint8_t",               # str - msg_size
        "functions": c_funcs,            # list of str
        "enums": enums,                  # dict: {name: {var:value, ...}, name:...}
        "enums_type": enums_type,        # str
        "size": msg_size,                # int
        "namespace": namespace,          # str
        "mavlink": mavlink,              # bool
        "yivo": yivo,                    # bool
        "license": license,              # str
        "msg_id": msg_id   # int
    }
    
    # pprint(info)
    
    # tmpl = env.get_template("msg.cpp.jinja")
    # content = tmpl.render(info)
    # print(content)
    return info

    # filename = info["name"] + ".hpp"
    # filename = Path(out_path)/filename
    # write_file(filename, content)