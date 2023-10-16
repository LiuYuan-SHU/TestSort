#ifndef SORT_INCLUDE_HEAP_HPP_
#define SORT_INCLUDE_HEAP_HPP_

#include "global.hpp"
#include "sort_algorithm_base.hpp"

#include <exception>
#include <functional>
#include <string>
#include <vector>

using std::function;
using std::greater;
using std::less;
using std::vector;

namespace my_algorithm {

class heap : sort_algorithm_base {
public:
  enum heap_type { heap_type_min, heap_type_max, heap_type_size };

private:
  function<bool(int, int)> _comparer;

public:
  inline explicit heap(heap_type type = heap_type_max) noexcept {
    switch (type) {
    default:
    case heap_type_min:
      _comparer = less<>();
      break;
    case heap_type_max:
      _comparer = greater<>();
      break;
    }
  }

  /**
   * @brief Adjust the heap, make the elem with index `index_adjust` at 
   * appropriate place
   * 
   * @param arr The heap
   * @param index_adjust The index of the element
   * @param index_end Where to stop, [index_adjust, index_end)
   */
  void adjust(vector<int>& arr, int index_adjust, int index_end);

public:
  void operator()(vector<int> &arr) override;
};

} // namespace my_algorithm

#endif // SORT_INCLUDE_HEAP_HPP_