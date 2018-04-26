# Myrt Math

A simple math library used by [the Myrt raytracer.](https://github.com/artemeknyazev/myrt)

## Contents

* [Installation](https://github.com/artemeknyazev/myrt-math#installation)
* [Usage](https://github.com/artemeknyazev/myrt-math#usage)
* [Testing](https://github.com/artemeknyazev/myrt-math#testing)

## Installation

```shell
> mkdir submodules && cd submodules && git clone https://github.com/artemeknyazev/myrt-math.git
```
Or
```shell
> git submodule add https://github.com/artemeknyazev/myrt-math.git ./submodules
```

## Usage

Add `myrt-math` to include path

```shell
> g++ -I<submodules path>/myrt-math/include <other options>
```
and include header files:
```cpp
#include "myrt-math/color.hpp"
#include "myrt-math/vec4.hpp"
#include "myrt-math/ray4.hpp"
#include "myrt-math/mat4.hpp"
```

Note, that currently the library exposes types into a global namespace. Will introduce a separate namespace later.

## Testing

```shell
> make run
```

Myrt Math uses a [`googletest`](https://github.com/google/googletest) testing framework.
