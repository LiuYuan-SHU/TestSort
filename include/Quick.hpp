#ifndef SORT_INCLUDE_QUICK_HPP_
#define SORT_INCLUDE_QUICK_HPP_

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <vector>

using std::vector;

namespace my_algorithm {
class quick : sort_algorithm_base {
private:
  void quick_sort(vector<int> &arr, int from, int to);
  size_t partition(vector<int> &arr, int from, int to);

public:
  void __attribute__((always_inline)) operator()(vector<int> &arr) override {
    if (arr.size())
    quick_sort(arr, 0, arr.size() - 1);
  }
};

} // namespace my_algorithm

#endif // SORT_INCLUDE_QUICK_HPP_