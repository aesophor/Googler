#ifndef SORT_HPP_
#define SORT_HPP_

#include "data_set.hpp"

namespace sort {
    DataSet& BubbleSort(DataSet& ds);
    DataSet& InsertionSort(DataSet& ds);
    DataSet& SelectionSort(DataSet& ds);
    DataSet& MergeSort(DataSet& ds);
    DataSet& QuickSort(DataSet& ds);
} // namespace sort

#endif
