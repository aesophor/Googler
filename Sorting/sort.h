#ifndef SORT_H_
#define SORT_H_

#include "sequence.h"

namespace sort {
  Sequence& BubbleSort(Sequence& ds);
  Sequence& InsertionSort(Sequence& ds);
  Sequence& SelectionSort(Sequence& ds);
  Sequence& MergeSort(Sequence& ds);
  Sequence& QuickSort(Sequence& ds);
} // namespace sort

#endif
