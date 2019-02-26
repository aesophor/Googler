#include "sort.hpp"

void sort::BubbleSort(DataSet& data_set) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < data_set.size - 1; i++) {
            if (data_set.data[i] > data_set.data[i+1]) {
                DataSet::Swap(data_set.data[i], data_set.data[i+1]);
                sorted = false;
            }
        }
    }
}
