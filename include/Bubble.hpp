//
// Created by Liu Yuan on 2023/9/22.
//

#ifndef SORT_INCLUDE_BUBBLE_HPP_
#define SORT_INCLUDE_BUBBLE_HPP_

#include "sort_algorithm_base.hpp"

#include <vector>

class bubble : sort_algorithm_base {
 public:
  void operator()(std::vector<int> &arr);
};

inline __attribute__ ((always_inline))void bubble::operator()(std::vector<int> &arr) {
  bool swapped = false;
  for (size_t index = 0; index < arr.size(); ++index, swapped = false) {
    for (size_t i_index = 0; i_index < arr.size() - index - 1; ++i_index) {
      if (arr[i_index] > arr[i_index + 1]) {
        std::swap(arr[i_index], arr[i_index + 1]);
        swapped = true;
      }
    }
    if (!swapped) { break; }
  }
}


#endif //SORT_INCLUDE_BUBBLE_HPP_
