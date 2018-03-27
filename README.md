# Myrt Math

Simple math library used by the Myrt raytracer.

## Installation

```
> mkdir submodules && cd submodules && git clone https://github.com/artemeknyazev/myrt-math.git
```
Or
```
> git submodule add https://github.com/artemeknyazev/myrt-math.git ./submodules
```

## Usage

```
> g++ -I submodules/myrt-math/include <other options>
```
and
```cpp
#include "myrt-math/vec4.hpp"
```

Note, that currently the library exposes types into a global namespace. Will introduce a separate namespace later.

## Testing

```
// add test
TESTER->add_test("vector.unary.plus", []{
    assert_eq(+Vec4(1.f, 2.f, 3.f), Vec4(1.f, 2.f, 3.f));
    assert_eq(+Vec4(-1.f, -2.f, -3.f), Vec4(-1.f, -2.f, -3.f));
});
// run it
TESTER->run();
```
then
```
> make test
```

A simpliest testing "framework". Note, that `TESTER` is a macros, and so is `assert_eq`. The former abstracts `Singleton::getInstance()`, the latter calls an `assert_eq_impl` implementation function with a file name and a line as added arguments. The function calls `check_eq` function overloaded for each type defined in the library.
