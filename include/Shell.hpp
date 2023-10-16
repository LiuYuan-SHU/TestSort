#ifndef SORT_INCLUDE_SHELL_HPP
#define SORT_INCLUDE_SHELL_HPP

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <algorithm>
#include <vector>

using std::vector;

namespace my_algorithm {
class shell : public sort_algorithm_base {
public:
  void operator()(vector<int> &arr) override;
};

void __attribute__((always_inline)) shell::operator()(vector<int> &arr) {
  for (int step = arr.size() / 2; step > 0; --step) {
    // sort each group with insert sort
    for (int index = 0; index < arr.size(); index += step) {
      if (index < arr.size() - step && arr[index] > arr[index + step]) {
        int tmp = arr[index + step];
        int index_swap;
        for (index_swap = index + step; index_swap >= step; index_swap -= step) {
          if (tmp < arr[index_swap - step]) {
            arr[index_swap] = arr[index_swap - step];
          } else {
            break;
          }
        }
        arr[index_swap] = tmp;
      }
    }
  }
}

} // namespace my_algorithm

#endif // SORT_INCLUDE_SHELL_HPP