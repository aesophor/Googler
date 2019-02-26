#include "sort.hpp"

DataSet& sort::BubbleSort(DataSet& data_set) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < data_set.size - 1; i++) {
            if (data_set[i] > data_set[i+1]) {
                DataSet::Swap(data_set[i], data_set[i+1]);
                sorted = false;
            }
        }
    }
    return data_set;
}

DataSet& sort::InsertionSort(DataSet& data_set) {
    // For each iteration, choose the leftmost element
    // from the unsorted section and "insert" it at the
    // correct position in the sorted section.
    for (int i = 1; i < data_set.size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (data_set[j] > data_set[j+1]) {
                DataSet::Swap(data_set[j], data_set[j+1]);
            }
        }
    }
    return data_set;
}

DataSet& sort::SelectionSort(DataSet& data_set) {
    // Select the minimum element from the unsorted array
    // and place it in the correct position within the
    // sorted array.
    //
    // 0 5 | 3 2 7
    //         ^
    for (int i = 1; i < data_set.size; i++) {
        int min_index = i;
        for (int j = i; j < data_set.size; j++) {
            if (data_set[i] < data_set[min_index]) {
                min_index = j;
            }
        }

        for (int k = min_index - 1; k >= 0; k--) {
            if (data_set[k] > data_set[k+1]) {
                DataSet::Swap(data_set[k], data_set[k+1]);
            }
        }
    }
    return data_set;
}
