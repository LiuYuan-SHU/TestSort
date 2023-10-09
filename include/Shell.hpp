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
  size_t size = arr.size();
  for (int offset = size / 2; offset > 0; --offset) {
    for (int index = 0; index < size; ++index) {
      for (int index_group = index; index_group < size - offset;
           index_group += offset) {
        if (arr[index_group] > arr[index_group + offset]) {
          int tmp = arr[index_group + offset];
          int index_swap;
          for (index_swap = index_group + offset; index_swap >= offset;
               index_swap -= offset) {
            if (arr[index_swap] < arr[index_swap - offset]) {
              arr[index_swap] = arr[index_swap - offset];
            } else {
              break;
            }
          }
          arr[index_swap] = tmp;
        }
      }
      if (std::is_sorted(arr.begin(), arr.end())) {
        return;
      }
    }
  }
}

} // namespace my_algorithm

#endif // SORT_INCLUDE_SHELL_HPP