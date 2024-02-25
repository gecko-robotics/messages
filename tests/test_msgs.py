import pytest
from gecko_messages import *
from gecko_messages.builtins import complex_types

def test_builtins():
    for cp in complex_types:
        try:
            msg = read_tomls(cp)
            create_cpp(msg)
            create_python(msg)
            # print(data)
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
    """

    try:
        msg = read_tomls(txt)
        create_cpp(msg)
        create_python(msg)
        assert True
    except:
        pytest.fail("Error custom message")