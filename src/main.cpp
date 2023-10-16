//
// Created by Liu Yuan on 2023/9/22.
//

// test framwork
#include <gtest/gtest.h>

// sort algorithms, utils
#include "Bubble.hpp"
#include "Heap.hpp"
#include "Insert.hpp"
#include "Quick.hpp"
#include "Select.hpp"
#include "Shell.hpp"
#include "global.hpp"

// test cases
#include "test_case.hpp"

// A small example code to generate a callable object
struct qsort_wrapper {
  inline __attribute__((always_inline)) void operator()(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
  }
};

// Add your test code here
// The functor should meet the requirement:
// std::function<void(std::vector<int>&)>
algorithm_info algorithms[] = {
    {my_algorithm::bubble(), "BubbleSort"},
    {my_algorithm::select(), "SelectSort"},
    {my_algorithm::insert(), "InsertSort"},
    {my_algorithm::shell(), "ShellSort"},
    {my_algorithm::quick(), "QuickSort"},
    {my_algorithm::heap(my_algorithm::heap::heap_type::heap_type_min),
     "HeapSort"},
};

INSTANTIATE_TEST_SUITE_P(test_env, test_env, testing::ValuesIn(algorithms));

int main() {
  ::testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}
