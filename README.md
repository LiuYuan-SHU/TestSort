# TestSort

> An automatic sort test frame work in Cmake and xmake

## Quick Start

> Xmake is preferred, update in CMake might be latter than Xmake

1. With Cmake:
    
    ```shell
    cmake -B build build
    cmake --build build
    ./build/bin/sort 
    ```
2. With xmake:
   
   ```shell
   xmake
   xmake run
   ```

If you are using xmake, a debug version is built by default. If you want a fast version without debug symbols and so on, run:

```shell
xmake f -m fastest
xmake build
xmake run
```

In version 1.0.0, executable in fastest mode will cost 7ms while debug version costs 77 ms for 18 tests.

## How to Use

1. Implement your sorting algorithm, provide a [callable](https://en.cppreference.com/w/cpp/named_req/Callable) object **to `algorithms` in `src/main.cpp`.** If you are not sure if your code fits the requirement, here is a small example:
   
   ```cpp
   struct qsort_wrapper {
     inline __attribute__((always_inline)) void operator()(std::vector<int> &vec) {
       std::sort(vec.begin(), vec.end());
     }
   };
   ```
  
   Or you can inherit `sort_algorithm_base` in `include/sort_algorithm_base.hpp` and override `operator()` and provide an instance of the class, just like the example codes in `src/main.cpp`.
2. Compile and run codes as [Quick Start](#quick-start)
