#ifndef SORT_HPP_
#define SORT_HPP_

#include "data_set.hpp"

namespace sort {
    DataSet& BubbleSort(DataSet& data_set);
    DataSet& InsertionSort(DataSet& data_set);
    DataSet& SelectionSort(DataSet& data_set);
} // namespace sort

#endif
