//
// Created by Liu Yuan on 2023/9/22.
//

#ifndef SORT_SRC_TEST_ENV_HPP_
#define SORT_SRC_TEST_ENV_HPP_

#include <gtest/gtest.h>

#include <array>
#include <random>
#include <vector>

struct algorithm_info {
  std::function<void(std::vector<int> &)> algorithm;
  std::string name;
};

class test_env : public testing::TestWithParam<algorithm_info> {
protected:
  static std::vector<std::vector<int>> test_cases;

  // is all test cases' capacity is set
  static bool is_init;
  // random device to generate random number
  static std::random_device rd;
  static std::mt19937 gen;

protected:
  static void init_vecs();
  // The number of numbers in the vec
  // in: 1, 2, 4, 8, ..., 2^25
  static constexpr size_t TEST_CASE_NUM = 10;
  static constexpr int TEST_CASE_NUM_RANGE = 1000;

protected:
  std::function<void(std::vector<int> &)> sort_algorithm;
  std::string algorithm_name;

public:
  explicit inline test_env() {
    const algorithm_info &info = GetParam();
    sort_algorithm = info.algorithm;
    algorithm_name = info.name;
  }

public:
  enum rand_type {
    empty,    // empty vec
    uniform,  // uniform: U(-TEST_CASE_NUM_RANGE)
    normal,   // normal: N(0, TEST_CASE_NUM_RANGE)
    poisson,  // possion: P(TEST_CASE_NUM_RANGE)
    ordered,  // ordered: [INT_FAST32_MIN, INT_FAST32_MAX]
    inverted, // inverted [INT_FAST32_MIN, INT_FAST32_MAX]
    rand_type_count
  };

private:
  // generate empty test data
  static void generate_empty();
  // generate uniform distribution test data
  static void generate_uniform();
  // generate normal distribution test data
  static void generate_normal();
  // generate Possion distribution test data
  static void generate_poisson();
  // generate ordered test data
  static void generate_ordered();
  // generate inverted test data
  static void generate_inverted();

protected:
  void measure_and_print(std::vector<int> &arr, std::function<bool()> judge,
                         const std::string &error_info);

public:
  static void generate_data(rand_type type);

public:
  inline void SetUp() override { init_vecs(); }
};

#endif // SORT_SRC_TEST_ENV_HPP_
