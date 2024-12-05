# s21_containers

This project is an implementation of custom STL-like containers in C++. The implemented containers include:

- `Vector`
- `List`
- `Stack`
- `Queue`
- `Map`
- `Set`
- `RB_Tree` (used internally for `Map` and `Set`)

The project is built using a `Makefile` for compilation and testing. Unit tests are written with Google Test to ensure the correctness of the implementation.

## Features

- Custom implementation of standard containers.
- Adheres to modern C++ standards (`C++17`).
- Extensive testing using Google Test.
- Tools for memory checking with Valgrind.

---

## Use tutorial

```cpp
#include "pathToProject/s21_containers.h"

int main() {

    ... 

    s21::vector<int> s21_vector;

    ...
}
