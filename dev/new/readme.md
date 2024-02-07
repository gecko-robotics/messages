# Messages

Message formats should be short and simple, but if you want, it can also be complex.
 
Files:
 
- `imu.toml` where the name of the message is the name of the file
- `global.toml` which holds common or global setting for all messages
 
## Message File
 
```toml
[global]
comments = "string"
namespace = "string"
license = string    # full text of what you want at the top of each file
version = string    # anything you want like 1.0.2 or 2022.2.23
 
[global.serialize]
yivo = bool         # true | false
mavlink = bool
 
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

comments = string     # optional, will be attached to the `struct`
id = bool             # can be in global.toml [ids] or here, value must be between 20 - 255
frozen = bool         # only for python dataclass
 
# this is really a message library for serialization, so only put functions if
# you really need to, otherwise, let some other part of your code base
# handle this
[functions]
c = string
python = string
```

This can be represented as a `json`:
 
```json
{
  "global": {
    "comments":  string,
    "namespace": string
  },
  ...
}
```
 
The minimum message file is the table `message` and at least one variable:
 
```toml
[message]
float-x = 0.0
```
 
## Global File
 
Now you can shorten your message file because a lot of these are repetitive across message files using a global file
to capture the common settings. Basically, anything in the “global” space of a message file can be moved here.
 
```toml
[global]
namespace = string
license = string
[global.serialize]
yivo = bool
mavlink = bool # useful?
 
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
