#ifndef SORT_INCLUDE_QUICK_HPP_
#define SORT_INCLUDE_QUICK_HPP_

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <vector>

using std::vector;

namespace my_algorithm {
class quick : sort_algorithm_base {
private:
  /**
   * @brief Quick sort `arr` from index `from` to index `to`
   * 
   * @param arr The arr to be sorted
   * @param from The index to start
   * @param to The index to stop, [from, to)
   */
  void quick_sort(vector<int> &arr, int from, int to);

  /**
   * @brief Split the given range [from, to) into a smaller 
   * one, return the pivot's index
   * 
   * @param arr The arr to be sorted
   * @param from The index to start
   * @param to The index to stop
   * @return size_t The index of the pivot
   */
  size_t partition(vector<int> &arr, int from, int to);

public:
  void __attribute__((always_inline)) operator()(vector<int> &arr) override {
    if (arr.size())
    quick_sort(arr, 0, arr.size() - 1);
  }
};

} // namespace my_algorithm

#endif // SORT_INCLUDE_QUICK_HPP_