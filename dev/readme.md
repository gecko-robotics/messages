# gentools

## ToDo

- [ ] allow comments on `enum` values
- [ ] for complex types, use `&` in args
- [ ] fix python function indent issues
- [ ] enable `yivo` packing and `struct` format
- [ ] handle arrays: `uint8[32]`
    - Maybe :
    ```python
    if s.find("[") > -1:
        s = s.replace("["," ").replace("]"," ")
        toks = s.split(" ")
        type_array, size = toks
        val = [0]*size
    ```