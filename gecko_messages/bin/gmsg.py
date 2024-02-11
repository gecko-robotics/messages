#!/usr/bin/env python3
from colorama import Fore
from pathlib import Path
import gecko_messages as gmsgs
# from collections import namedtuple

# class Msg:
#     name = None
#     len = 0
#     cpp = False
#     python = False

def language(data, create, output_path, ext):
    # output_path = Path("./cpp")
    print(f"{Fore.GREEN}Saving to {output_path.resolve()}{Fore.RESET}")
    for msg in data:
        name = msg["message"]["name"]
        print(f"{Fore.CYAN} -> {name}{ext}{Fore.RESET}")
        content = create(msg)
        name += ext
        gmsgs.write_file(output_path / name, content)


def main():
    print("gecko message")
    data = gmsgs.read_folder(".")
    gmsgs.print_summary(data)
    # print(data)
    # Msg = namedtuple("Msg","name len cpp python")
    # msgs = {}

    if True:
        print("[ CPP ]==========================")
        language(data, gmsgs.create_cpp, Path("./cpp"), ".hpp")

    if True:
        print("[ Python ]=======================")
        language(data, gmsgs.create_python, Path("./python"), ".py")

if __name__ == "__main__":
    main()