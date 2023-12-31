//
// Created by Liu Yuan on 2023/9/22.
//

#ifndef SORT_INCLUDE_SORT_ALGORITHM_BASE_HPP_
#define SORT_INCLUDE_SORT_ALGORITHM_BASE_HPP_

#include "global.hpp"

#include <vector>

namespace my_algorithm {

class sort_algorithm_base {
public:
  virtual void operator()(std::vector<int> &arr) = 0;
};

} // namespace my_algorithm

#endif // SORT_INCLUDE_SORT_ALGORITHM_BASE_HPP_
