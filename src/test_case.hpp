//
// Created by Liu Yuan on 2023/9/22.
//

#ifndef SORT_SRC_TEST_CASE_HPP_
#define SORT_SRC_TEST_CASE_HPP_

#include "test_env.hpp"

#include <gtest/gtest.h>

#include <algorithm>

TEST_P(test_env, SortEmptyVector) {
  generate_data(empty);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return arr.empty(); },
                                std::ref(arr)), "Sorted array is not empty");
}

TEST_P(test_env, SortAverageDistribution) {
  generate_data(uniform);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return std::is_sorted(arr.begin(), arr.end()); },
                                std::ref(arr)), "Array is not sorted");
}

TEST_P(test_env, SortNormalDistribution) {
  generate_data(normal);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return std::is_sorted(arr.begin(), arr.end()); },
                                std::ref(arr)), "Array is not sorted");
}

TEST_P(test_env, SortPossionDistribution) {
  generate_data(poisson);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return std::is_sorted(arr.begin(), arr.end()); },
                                std::ref(arr)), "Array is not sorted");
}

TEST_P(test_env, SortOrderedDistribution) {
  generate_data(ordered);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return std::is_sorted(arr.begin(), arr.end()); },
                                std::ref(arr)), "Array is not sorted");
}

TEST_P(test_env, SortInvertedDistribution) {
  generate_data(inverted);
  for (auto &arr : test_env::test_cases)
    measure_and_print(arr,
                      std::bind([](const std::vector<int> &arr) { return std::is_sorted(arr.begin(), arr.end()); },
                                std::ref(arr)), "Array is not sorted");
}

#endif //SORT_SRC_TEST_CASE_HPP_
