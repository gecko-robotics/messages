# Messages

Message formats should be short and simple, but if you want, it can also be complex.

Files:

- `imu.toml` where the name of the message is the name of the file
- `global.toml` which holds common or global setting for all

```
toml(file) - > dict -> create_c/py -> string -> file
toml(string) -> dict -> create_c/py -> string -> file

read_folder(dir_path, output_path=./) -> calls below functions
read_toml(file) -> dict
read_tomls(string) -> dict

Msg_file(file_path, global_file=file_path/global.toml, output_path=./) -> string
Msg_string(str, global_str) -> string
```

Binary:
https://linuxcommandlibrary.com/man/protoc

```
msgcomp [--out_dir=DIR][--in_dir=DIR][--version][--verbose][--help][--cpp-only][--python-only]
```

verbose:
num msg found: x
global found: t/f
Id, Msg_name, size, fmt
…

Cpp and python need id2msg(int) -> string

## Message File

Message use standard types:

- `uint8` or `int8`
- `uint16` or `int16`
- `uint32` or `int32`
- `uint64` or `int64`
- `float`

Or complex types:

| ID | Message    | Info                             |
|----|------------|----------------------------------|
| 1  | `vec_t`    | {float x,y,z}
| 2  | `quat_t`   | {float w,x,y,z}
| 3  | `twist_t`  | {vec_t linear, vec_t angular}
| 4  | `wrench_t` | {vec_t force, vec_t torque}
| 5  | `pose_t`   | {vec_t position, quat_t orientation}

```toml
[global]
comments = "string"
namespace = "string"
license = "string" # full text of what you want at the top of each file
version = "string" # anything you want like 1.0.2 or 2022.2.23
frozen = "bool"    # is python dataclass frozen true or false

[global.serialize]
yivo = "bool"         # true | false
mavlink = "bool"

[enum.name] # optional, can have many of these, each must have
            # an original name and each value in an enum must
            # be unique (python uses `@unique` from `enum`
            # library)
Val1 = 1
Val2 = 2
Val3 = 3

# since python is not a strongly typed language, it will not always respect
# default types, so what should be an array (float[3]), you can set to a
# scalar int. C is the only one that will complain if you do this.
[message]
float-x = 0.0         # type-var_name = default_value
float-2-y = [0.0,0.0] # type-array_size-var_name = default_value
float-z = 0.0         # var names can only be ascii letters, numbers and -
vec_t-a = [1,2,3]     # other messages CANNOT be arrays, this will also automatically
                      # add `#include “vec_t.hpp”` and `from vec_t import *` when generated

comments = "string"     # optional, will be attached to the `struct`
id = "bool"             # can be in global.toml [ids] or here, value must be between 20 - 255
frozen = "bool"         # only for python dataclass

# this is really a message library for serialization, so only put functions if
# you really need to, otherwise, let some other part of your code base
# handle this
[functions]
c = "string"
python = "string"
```

The minimum message file is:

```toml
[message]
float-x = 0.0
id = 33 # this can be in global.toml under [global.ids]
name = "simple"
```

## Global File

Now you can shorten your message file because a lot of these are repetitive across message files using a global file
to capture the common settings. Basically, anything in the “global” space of a message file can be moved here.

```toml
[global]
namespace = "string"
license = "string"

[global.serialize]
yivo = "bool"
mavlink = "bool" # useful?

# put native types in var_types VarTypes(name, size, fmt, id) ... native ids = 0,
# complex ids > 0, remove complex altogether ids between 20 - 255. This is nice
# to put message ids here, because you can see them all in one place and know you don’t
# have any conflicts.
[global.ids]
imu_t = int
calibration_t = int
my_cool_msg = int
awesome_msg = int
```