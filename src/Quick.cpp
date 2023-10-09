#include <Quick.hpp>
#include <cstddef>

namespace my_algorithm {
void quick::helper(vector<int> &arr, size_t from, size_t to) {
  if (arr.size() == 0 || from >= to) {
    return;
  }

  const int &pivot_element = arr[to];

  std::size_t rhs_pointer = to;
  std::size_t lhs_pointer = from;

  while (lhs_pointer < rhs_pointer) {
    while (arr[lhs_pointer] <= pivot_element && lhs_pointer < rhs_pointer) {
      ++lhs_pointer;
    }

    while (arr[rhs_pointer] >= pivot_element && rhs_pointer > lhs_pointer) {
      --rhs_pointer;
    }

    std::swap(
        arr[lhs_pointer],
        arr[rhs_pointer]
    );
  }

  std::swap(
      arr[lhs_pointer],
      arr[to]
  );

  if (lhs_pointer != 0) {
    helper(arr, from, lhs_pointer - 1);
  }
  helper(arr, lhs_pointer + 1, to);
}
} // namespace my_algorithm