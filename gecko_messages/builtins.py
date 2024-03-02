###############################################
# The MIT License (MIT)
# Copyright (c) 2023 Kevin Walchko
# see LICENSE for full details
##############################################
# -*- coding: utf-8 -*-

complex_types_global = """
[global]
license = '''The MIT License (MIT)
Copyright (c) 2023 Kevin Walchko
see LICENSE for full details
'''
frozen = false
"""

complex_types = [
    """
    [message]
    x = "float"
    y = "float"
    z = "float"
    id = 1
    name = "vec"
    """,
    """
    [message]
    w = "float"
    x = "float"
    y = "float"
    z = "float"
    id = 2
    name = "quat"
    """,
    """
    [message]
    linear = "vec"
    angular = "vec"
    id = 3
    name = "twist"
    """,
    """
    [message]
    force = "vec"
    torque = "vec"
    id = 4
    name = "wrench"
    """,
    """
    [message]
    position = "vec"
    orientation = "quat"
    id = 5
    name = "pose"
    """]



# complex_types = [
#     """
#     [message]
#     float-x = 1
#     float-y = 1
#     float-z = 1
#     id = 1
#     name = "vec"
#     """,
#     """
#     [message]
#     float-w = 1
#     float-x = 1
#     float-y = 1
#     float-z = 1
#     id = 2
#     name = "quat"
#     """,
#     """
#     [message]
#     vec-linear = 1
#     vec-angular = 1
#     id = 3
#     name = "twist"
#     """,
#     """
#     [message]
#     vec-force = 1
#     vec-torque = 1
#     id = 4
#     name = "wrench"
#     """,
#     """
#     [message]
#     vec-position = 1
#     quat-orientation = 1
#     id = 5
#     name = "pose"
#     """]