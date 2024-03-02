# pytest -s tests

import pytest
from gecko_messages import *
from gecko_messages.builtins import complex_types, complex_types_global
from gecko_messages.types import var_types, process_messages
from pprint import pprint
from pathlib import Path

def test_builtins():
    g = read_tomls(complex_types_global)
    for cp in complex_types:
        try:
            msg = read_tomls(cp) | g
            process_messages([msg])
            # pprint(msg)
            c=create_cpp(msg)
            p=create_python(msg)
            # print("-----------------------------------")
            # print(c,p)
            assert True
        except:
            pytest.fail("Error builtins")

def test_custom_msg():
    txt =  """
    [message]
    a = "vec"    # len = 1, default = None
    b = {type = "quat", len = 2}
    c = "wrench"
    d = "pose"
    e = "twist"
    f = {type = "uint32", len = 3, default = [1,2,3]}
    g = "float"
    id = 50
    name = "test_t"
    """

    try:
        msg = read_tomls(txt)
        process_messages([msg])
        c=create_cpp(msg)
        p=create_python(msg)
        assert True
    except:
        pytest.fail("Error custom message")

    assert "test_t" in var_types, pprint(var_types)


def test_unknown_msg():
    txt =  """
    [message]
    a = "zoo" # this type should fail
    id = 50
    name = "test_t"
    """

    try:
        msg = read_tomls(txt)
        process_messages([msg])
        c=create_cpp(msg)
        p=create_python(msg)
        assert False
    except KeyError as e:
        # print(e)
        assert True

def test_multi_msg():
    g = """
    [global]
    license = '''Test License'''
    namespace = "testing"
    [global.serialize]
    yivo = true
    """
    g = read_tomls(g)

    a =  """
    [message]
    a = "vec"
    name = "a"
    id = 50
    """

    b =  """
    [message]
    b = {type = "a", default = [1.1,2.2,3.3]}
    bb = "a"

    name = "b"
    id = 51
    """

    msgs = []
    for txt in [a,b]:
        msg = read_tomls(txt) | g
        msgs.append(msg)

    process_messages(msgs)

    for msg in msgs:
        try:
            c=create_cpp(msg)
            p=create_python(msg)
            # print(c,p)
            assert True
        except:
            pytest.fail("Error multi message")

    assert "a" in var_types, pprint(var_types)
    assert "b" in var_types, pprint(var_types)

def test_file():
    try:
        p = Path(__file__).resolve().parent/"alice.toml"
        msg = read_toml(p)
        # pprint(msg)
        process_messages([msg])
        # pprint(var_types)
        # pprint(msg)
        c=create_cpp(msg)
        p=create_python(msg)
        # print(c)
        assert True
    except:
        pytest.fail("Error file message")

    assert "alice" in var_types, pprint(var_types)
    # assert False, pprint(var_types)
