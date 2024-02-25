import pytest
from gecko_messages import *
from gecko_messages.builtins import complex_types, complex_types_global

def test_builtins():

    g = read_tomls(complex_types_global)
    for cp in complex_types:
        try:
            msg = read_tomls(cp) | g
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
    vec_t-a = 1
    quat_t-b = 2
    wrench_t-c = 1
    pose_t-d = 1
    twist_t-e = 1
    uint32-f = 3
    float-g = 1
    id = 50
    name = "test_t"

    [message.defaults]
    g = 110
    a = [1,2,3]
    b = [[1,2,3,4],[5,6,7,8]]
    """

    try:
        msg = read_tomls(txt)
        c=create_cpp(msg)
        p=create_python(msg)
        assert True
        # print(c,p)
    except:
        pytest.fail("Error custom message")

def test_multi_msg():
    a =  """
    [message]
    vec_t-a = 1
    name = "a"
    id = 50
    """
    b =  """
    [message]
    a-b = 1
    name = "b"
    id = 51
    """

    for txt in [a,b]:
        try:
            msg = read_tomls(txt)
            c=create_cpp(msg)
            p=create_python(msg)
            print(c,p)
            assert True
        except:
            pytest.fail("Error multi message")