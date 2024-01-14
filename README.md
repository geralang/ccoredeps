<img src="logo.png" height="200" align="left"/>

# `ccoredeps`
*The default implementation of the core dependencies of the C target for [the Gera programming language](https://github.com/geralang).*

<br><br><br>

The Gera programming language depends on a couple of functions when compiling to C, such as memory allocation functions, console output or mutexes. This repository implements this set of functions using libc.

If you want to use Gera in an environment without libc, you will need to implement these functions yourself.

This repository is cloned by default by [`gerap`](https://github.com/geralang/gerap) when compiling for the C target and no custom implementation is provided.

## Expectations by Gera

Gera expects `gera.h` and `geracoredeps.h` to be provided in the exact same form they are provided here.

`geratypes.h` may be modified, but `GeraFreeHandler`, `GeraAllocation`, `GeraArray`, `GeraString`, `gfloat`, `gint` and `gbool` are all expected to be defined in the exact same way they are defined here.

`geracoredeps.c` has to exist at the directory root to be included in the compilation by default by `gerap`.