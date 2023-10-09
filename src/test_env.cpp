//
// Created by Liu Yuan on 2023/9/22.
//
#include "test_env.hpp"

#include "utils.hpp"

#include <chrono>

// static class member initialization
std::vector<std::vector<int>> test_env::test_cases;
bool test_env::is_init = false;
std::random_device test_env::rd;
std::mt19937 test_env::gen(test_env::rd());

void test_env::init_vecs() {
  if (!is_init) {
    for (size_t index = 0; index < TEST_CASE_NUM; ++index) {
      test_cases.emplace_back(1 << (index + 1));
    }
    is_init = true;
  }
}
void test_env::generate_uniform() {
  static std::uniform_real_distribution<double> distribution(
      -TEST_CASE_NUM_RANGE, TEST_CASE_NUM_RANGE);
  for (auto &test_case : test_cases) {
    while (test_case.size() < test_case.capacity()) {
      test_case.push_back(static_cast<int>(distribution(gen)));
    }
  }
}
void test_env::generate_normal() {
  static std::normal_distribution<double> distribution(
      0, TEST_CASE_NUM_RANGE); // 均值和标准差
  for (auto &test_case : test_cases) {
    while (test_case.size() < test_case.capacity()) {
      test_case.push_back(static_cast<int>(distribution(gen)));
    }
  }
}
void test_env::generate_poisson() {
  static std::poisson_distribution<int> distribution(TEST_CASE_NUM_RANGE);
  for (auto &test_case : test_cases) {
    while (test_case.size() < test_case.capacity()) {
      test_case.push_back(distribution(gen));
    }
  }
}
void test_env::generate_ordered() {
  int assign = INT_FAST32_MIN;
  for (auto &test_case : test_cases) {
    while (test_case.size() < test_case.capacity()) {
      test_case.push_back(assign++);
    }
    assign = INT_FAST32_MIN;
  }
}
void test_env::generate_inverted() {
  int assign = INT_FAST32_MAX;
  for (auto &test_case : test_cases) {
    while (test_case.size() < test_case.capacity()) {
      test_case.push_back(assign--);
    }
    assign = INT32_MAX;
  }
}
void test_env::generate_data(test_env::rand_type type) {
  for (auto &test_case : test_cases) {
    test_case.clear();
  }

  switch (type) {
  default:
  case uniform:
    generate_uniform();
    break;
  case empty:
    generate_empty();
    break;
  case normal:
    generate_normal();
    break;
  case poisson:
    generate_poisson();
    break;
  case ordered:
    generate_ordered();
    break;
  case inverted:
    generate_inverted();
    break;
  }
}
void test_env::generate_empty() {
  for (auto &test_case : test_cases)
    test_case.clear();
}
void test_env::measure_and_print(std::vector<int> &arr,
                                 std::function<bool()> judge,
                                 const std::string &error_info) {
  // save data for next test
  std::vector<int> tmp(arr);
  tmp.resize(arr.capacity());

  auto start_time = std::chrono::high_resolution_clock::now();
  sort_algorithm(arr);
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
      end_time - start_time);

  EXPECT_TRUE(judge()) << error_info << std::endl
                       << "Your answer is: " << to_string<int>(arr) << std::endl
                       << "The array is sorted until index: "
                       << std::distance(
                              arr.begin(),
                              std::is_sorted_until(arr.begin(), arr.end()))
                       << std::endl;

  // restore data
  arr = std::move(tmp);

  /*std::cout << algorithm_name << " time: " << duration.count() << "
     microseconds "
            << "for " << arr.size() << " elements."
            << std::endl;*/
}
