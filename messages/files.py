import tomllib
from pathlib import Path
from .utils import var_fix
from .builtins import *

def read_toml(file):
    """
    Read toml file and return a dict
    """
    path = Path(file)
    with path.open("rb") as f:
        data = tomllib.load(f)
        
    if "message" in data:
        data = var_fix(data)
        
    return data
    
def read_tomls(txt):
    """
    Read toml string and return dict
    """
    data = tomllib.loads(txt)
        
    if "message" in data:
        data = var_fix(data)
        
    return data

def read_folder(dir):
    """
    Read a message folder and return a dict. It is expected each
    message is in an individual toml file. Optionally there can
    be a global.toml file (all lower case) that contains info
    across each message."""
    data_files = []
    p = Path(dir).glob('*.toml')
    files = [x for x in p if x.is_file()]

    # handle global file ------------------------------
    globalFile = False
    gf = Path(dir) / "global.toml"
    gData = {"global": None}
    if gf in files:
        # with gf.open("rb") as f:
        #     gData = tomllib.load(f)
        gData = read_toml(gf)
        globalFile = True
        files.remove(gf)

    # handle builtins ----------------------------------
    for f in complex_types:
        # data = tomllib.loads(f) | gData
        
        # if "message" in data:
        #     data = var_fix(data)
        data = read_tomls(f) | gData
            
        data_files.append(data)
    
    # process messages ---------------------------------
    for f in files:
        # with f.open("rb") as fd:
            # data = tomllib.load(fd) | gData
        
            # if "message" in data:
            #     data = var_fix(data)

            # pprint(data)
            
        data = read_toml(f) | gData
        data_files.append(data)
    return data_files

def write_file(filename, content):
    """
    Simple writes content to filename
    """
    if not isinstance(filename, Path)
        filename = Path(filename)
    try:
        with filename.open("w", encoding="utf-8") as fd:
            fd.write(content)
        # print(f"Wrote File: {filename}")
        return True
    except:
        # print(f"Failed to write File: {filename}")
        return False