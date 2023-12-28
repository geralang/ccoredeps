# The Gera core dependencies for the C target

This repository contains an implementation of all headers and functions that the C target of the Gera programming language needs.

This implementation depends on libc, meaning if you plan on compiling to a target which does not support libc, you will need to implement this set of functions yourself.

This repository is cloned by default by `gerap` when compiling for the C target and no custom implementation is provided.

## Links

- [Gera compiler](https://github.com/typesafeschwalbe/gerac)
- [Package manager](https://github.com/typesafeschwalbe/gerap)
- [Standard library](https://github.com/typesafeschwalbe/gerastd)

## Expectations by Gera

Gera expects `gera.h` and `geracoredeps.h` to be provided in the exact same form they are provided here.

`geratypes.h` may be modified, but `GeraFreeHandler`, `GeraAllocation`, `GeraArray`, `GeraString`, `gfloat`, `gint` and `gbool` are all expected to be defined in the exact same way they are defined here.

`geracoredeps.c` has to exist in the `src`-directory to be included in the compilation by default by `gerap`.