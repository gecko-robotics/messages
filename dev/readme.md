# gentools

Generate messages for python and C/C++.

## ToDo

- [ ] maybe move this to `yivo` since it might be tied to that like `mavlink`
pack/unpack is tied to its messages or `protobuf`
- [x] allow comments on `enum` values
- [x] for complex types, use `&` in args
- [ ] fix python function indent issues
- [ ] enable `yivo` packing and `struct` format
    - `yivo` is a class and an object must exist to use it ... maybe:
        - packing is a function, no state variables needed
        - unpacking is a class for the `parse(byte)`
        - also, don't like `YivoPack_t` ... maybe `ypkt_t`
- [x] handle arrays: `uint8[32]`
