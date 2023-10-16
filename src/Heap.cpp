#include "Heap.hpp"

#include <vector>

using std::vector;

namespace my_algorithm {
void heap::adjust(vector<int> &arr, int index_adjust, int index_end) {
  for (int index = 2 * index_adjust + 1; index < index_end;
       index = 2 * index + 1) {
    // choose _comparer child
    if (index < index_end - 1 && !_comparer(arr[index], arr[index + 1])) {
      ++index;
    }
    // if father is not greater/less than child, swap
    if (!_comparer(arr[index_adjust], arr[index])) {
      std::swap(arr[index_adjust], arr[index]);
      // recurse
      index_adjust = index;
    } else {
      break;
    }
  }
}

void heap::operator()(vector<int> &arr) {
  vector<int> result;

  // build heap
  for (int index = arr.size() / 2 - 1; index >= 0; --index) {
    adjust(arr, index, arr.size());
  }

  for (int index = 0; index < arr.size(); ++index) {
    result.push_back(arr[0]);
    std::swap(arr[0], arr[arr.size() - 1 - index]);
    adjust(arr, 0, arr.size() - index - 1);
  }

  std::swap(arr, result);
}
} // namespace my_algorithm