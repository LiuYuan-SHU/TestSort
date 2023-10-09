//
// Created by Liu Yuan on 2023/9/23.
//

#ifndef SORT_INCLUDE_SELECT_HPP_
#define SORT_INCLUDE_SELECT_HPP_

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <vector>

namespace my_algorithm {

class select : public sort_algorithm_base {
public:
  void operator()(std::vector<int> &other) override;
};

inline __attribute__((always_inline)) void
select::operator()(std::vector<int> &other) {
  auto next_swap_index = other.begin();
  auto min = other.begin();

  while (next_swap_index != other.end()) {
    // find min
    for (auto iter = next_swap_index; iter != other.end(); ++iter) {
      if (*iter < *min) {
        min = iter;
      }
    }

    std::swap(*min, *next_swap_index);
    ++next_swap_index;
    min = next_swap_index;
  }
}

} // namespace my_algorithm

#endif // SORT_INCLUDE_SELECT_HPP_
