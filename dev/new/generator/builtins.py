
def vec_t():
    return """
    [message]
    float-x = 0
    float-y = 0
    float-z = 0
    id = 1
    name = "vec_t"
    """

def quat_t():
    return """
    [message]
    float-w = 1
    float-x = 0
    float-y = 0
    float-z = 0
    id = 2
    name = "quat_t"
    """

def twist_t():
    return """
    [message]
    vec_t-linear = [0,0,0]
    vec_t-angular = [0,0,0]
    id = 3
    """

def wrench_t():
    return """
    [message]
    vec_t-force = [0,0,0]
    vec_t-torque = [0,0,0]
    id = 4
    """

def pose_t():
    return """
    [message]
    vec_t-position = [0,0,0]
    quat_t-orientation = [1,0,0,0]
    id = 5
    """