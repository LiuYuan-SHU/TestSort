#include "Quick.hpp"
#include <cstddef>

namespace my_algorithm {
void quick::quick_sort(vector<int> &arr, int from, int to) {
  if (from < to) {
    size_t index_pivot = partition(arr, from, to);
    quick_sort(arr, from, index_pivot - 1);
    quick_sort(arr, index_pivot + 1, to);
  }
}

size_t quick::partition(vector<int> &arr, int from, int to) {
  // choose the first element as pivot
  int pivot = arr[from];
  while (from < to) {
    while (from < to && arr[to] >= pivot) {
      --to;
    }
    arr[from] = arr[to];
    while (from < to && arr[from] <= pivot) {
      ++from;
    }
    arr[to] = arr[from];
  }
  arr[to] = pivot;

  return to;
}
} // namespace my_algorithm