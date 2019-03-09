#ifndef SORT_H_
#define SORT_H_

#include "data_set.h"

namespace sort {
    DataSet& BubbleSort(DataSet& ds);
    DataSet& InsertionSort(DataSet& ds);
    DataSet& SelectionSort(DataSet& ds);
    DataSet& MergeSort(DataSet& ds);
    DataSet& QuickSort(DataSet& ds);
} // namespace sort

#endif
