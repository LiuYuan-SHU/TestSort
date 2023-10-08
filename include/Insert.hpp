//
// Created by Liu Yuan on 2023/10/8.
//

#ifndef SORT_INCLUDE_INSERT_HPP_
#define SORT_INCLUDE_INSERT_HPP_

#include "sort_algorithm_base.hpp"
#include <cstddef>

namespace my_algorithm {

class insert : sort_algorithm_base {
public:
  void operator()(std::vector<int> &arr);
};

inline __attribute__((always_inline)) void
insert::operator()(std::vector<int> &arr) {
  int tmp, index, index_move;
  for (index = 1; index < arr.size(); ++index) {
    if (arr[index - 1] > arr[index]) {
      tmp = arr[index];
      for (index_move = index - 1; arr[index_move] > tmp && index_move >= 1;
           --index_move) {
        arr[index_move] = arr[index_move - 1];
      }
      arr[index_move] = tmp;
    }
  }
}

} // namespace my_algorithm

#endif // SORT_INCLUDE_INSERT_HPP_
