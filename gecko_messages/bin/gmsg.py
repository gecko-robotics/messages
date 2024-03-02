#!/usr/bin/env python3
#-*-coding:utf-8-*-
from colorama import Fore
from pathlib import Path
import gecko_messages as gmsgs
from gecko_messages.types import process_messages
from gecko_messages.types import var_types
import argparse
from pprint import pprint

DESCRIPTION = f"""
Generate cpp and python messages from toml templates.

Author:  {gmsgs.__author__}
Version: {gmsgs.__version__}
License: {gmsgs.__license__}
"""

def handleArgs():
    parser = argparse.ArgumentParser(
        description=DESCRIPTION,
        formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument('-i','--in_path', help='path to message tomls', type=str, default=".")
    parser.add_argument('-o','--out_path', help='path to save to', type=str, default=".")
    parser.add_argument('-co','--cpp_only', help='C++ only', action='store_true')
    parser.add_argument('-po','--python_only', help='Python only', action='store_true')

    args = vars(parser.parse_args())
    return args

def language(data, create):
    ret = {}
    for name, msg in data.items():
        content = create(msg)
        ret[name] = content

    return ret


def main():
    args = handleArgs()
    # print(args)

    in_path = Path(args["in_path"])
    out_path = Path(args["out_path"])

    data = gmsgs.read_folder(in_path)
    # pprint(data)
    process_messages(data)
    # pprint(var_types)
    # return
    gmsgs.print_summary(list(data.values()))
    # return

    py, cpp = True, True
    if args["cpp_only"]:
        py = False
        cpp = True
    if args["python_only"]:
        cpp = False
        py = True

    if cpp:
        print(f"{Fore.GREEN}[ C++ ]{Fore.RESET}")
        path = out_path / "cpp"
        print(f"{Fore.GREEN} Saving to {path.resolve()}{Fore.RESET}")
        content = language(data, gmsgs.create_cpp)
        for name, code in content.items():
            c = var_types[name].c
            c += ".hpp"
            gmsgs.write_file(path / c, code)
            print(f"{Fore.CYAN} -> {c}{Fore.RESET}")

    if py:
        print(f"{Fore.GREEN}[ Python ]{Fore.RESET}")
        path = out_path / "python"
        print(f"{Fore.GREEN} Saving to {path.resolve()}{Fore.RESET}")
        content = language(data, gmsgs.create_python)
        for name, code in content.items():
            py = var_types[name].py
            py += ".py"
            gmsgs.write_file(path / py, code)
            print(f"{Fore.CYAN} -> {py}{Fore.RESET}")

if __name__ == "__main__":
    main()