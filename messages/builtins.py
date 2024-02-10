
complex_types = [
    """
    [message]
    float-x = 0
    float-y = 0
    float-z = 0
    id = 1
    name = "vec_t"
    """,
    """
    [message]
    float-w = 1
    float-x = 0
    float-y = 0
    float-z = 0
    id = 2
    name = "quat_t"
    """,
    """
    [message]
    vec_t-linear = [0,0,0]
    vec_t-angular = [0,0,0]
    id = 3
    name = "twist_t"
    """,
    """
    [message]
    vec_t-force = [0,0,0]
    vec_t-torque = [0,0,0]
    id = 4
    name = "wrench_t"
    """,
    """
    [message]
    vec_t-position = [0,0,0]
    quat_t-orientation = [1,0,0,0]
    id = 5
    name = "pose_t"
    """]