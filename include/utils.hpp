//
// Created by Liu Yuan on 2023/9/22.
//

#ifndef SORT_INCLUDE_UTILS_HPP_
#define SORT_INCLUDE_UTILS_HPP_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(out, ", "));
  return out;
}

template <class T> std::string to_string(const std::vector<int> &vec) {
  std::stringstream stream;
  stream << vec;
  return stream.str();
}

#endif // SORT_INCLUDE_UTILS_HPP_
