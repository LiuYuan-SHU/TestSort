//
// Created by Liu Yuan on 2023/9/22.
//

#include <gtest/gtest.h>

#include "global.hpp"
#include "Bubble.hpp"
#include "Insert.hpp"
#include "Select.hpp"
#include "test_case.hpp"

struct qsort_wrapper {
  inline __attribute__((always_inline)) void operator()(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
  }
};

// Add your test code here
// The functor should meet the requirement: std::function<void(std::vector<int>&)>
algorithm_info algorithms[] = {
    {my_algorithm::bubble(), "BubbleSort"},
    {my_algorithm::select(), "SelectSort"},
    {my_algorithm::insert(), "InsertSort"},
};

INSTANTIATE_TEST_SUITE_P(test_env, test_env, testing::ValuesIn(algorithms));

int main() {
  ::testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}
