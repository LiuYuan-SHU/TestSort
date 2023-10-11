//
// Created by Liu Yuan on 2023/9/23.
//

#ifndef SORT_INCLUDE_SELECT_HPP_
#define SORT_INCLUDE_SELECT_HPP_

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <cstddef>
#include <vector>

namespace my_algorithm {

class select : public sort_algorithm_base {
public:
  void operator()(std::vector<int> &arr) override;
};

inline __attribute__((always_inline)) void
select::operator()(std::vector<int> &arr) {
  int index_min;
  for (size_t index = 0; index < arr.size(); ++index) {
    index_min = index;
    for (size_t index_inner = index + 1; index_inner < arr.size();
         ++index_inner) {
      if (arr[index_inner] < arr[index_min]) {
        index_min = index_inner;
      }
    }

    if (index_min != index) {
      std::swap(arr[index], arr[index_min]);
    }
  }
}

} // namespace my_algorithm

#endif // SORT_INCLUDE_SELECT_HPP_
