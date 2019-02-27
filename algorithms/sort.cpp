#include "sort.hpp"

DataSet& sort::BubbleSort(DataSet& ds) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < ds.size - 1; i++) {
            if (ds[i] > ds[i+1]) {
                DataSet::Swap(ds[i], ds[i+1]);
                sorted = false;
            }
        }
    }
    return ds;
}

DataSet& sort::InsertionSort(DataSet& ds) {
    // For each iteration, choose the leftmost element
    // from the unsorted section and "insert" it at the
    // correct position in the sorted section.
    for (int i = 1; i < ds.size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (ds[j] > ds[j+1]) {
                DataSet::Swap(ds[j], ds[j+1]);
            }
        }
    }
    return ds;
}

DataSet& sort::SelectionSort(DataSet& ds) {
    // Select the minimum element from the unsorted section
    // and place it in the correct position within the
    // sorted section.
    //
    // 0 5 | 3 2 7
    //         ^
    for (int i = 1; i < ds.size; i++) {
        int min_index = i;
        for (int j = i; j < ds.size; j++) {
            if (ds[i] < ds[min_index]) {
                min_index = j;
            }
        }

        for (int k = min_index - 1; k >= 0; k--) {
            if (ds[k] > ds[k+1]) {
                DataSet::Swap(ds[k], ds[k+1]);
            }
        }
    }
    return ds;
}


namespace {

    void Merge(DataSet& ds, int left, int mid, int right) {
        int left_size = mid - left + 1;
        int right_size = right - mid;

        int left_array[left_size];
        int right_array[right_size];

        for (int i = 0; i < left_size; i++) {
            left_array[i] = ds[left+i];
        }
        for (int i = 0; i < right_size; i++) {
            right_array[i] = ds[mid+1+i];
        }


        int left_current = 0;
        int right_current = 0;
        for (int i = 0; i < left_size + right_size; i++) {
            if (left_current == left_size && right_current < right_size) {
                // Right array still has remaining shit
                ds[left+i] = right_array[right_current];
                right_current++;
            } else if (left_current < left_size && right_current == right_size) {
                // Left array still has remaining shit
                ds[left+i] = left_array[left_current];
                left_current++;
            } else {
                // Both left and right array have remaining shit.
                if (left_array[left_current] <= right_array[right_current]) {
                    ds[left+i] = left_array[left_current];
                    left_current++;
                } else {
                    ds[left+i] = right_array[right_current];
                    right_current++;
                }
            }
        }
    }

    void MergeSort(DataSet& ds, int left, int right) {
        if (left < right) {
            // 1. Find the middle point (last index of the left half).
            int mid = (left + right) / 2;

            // 2. Call MergeSort for the left half.
            MergeSort(ds, left, mid);

            // 3. Call MergeSort for the right half.
            MergeSort(ds, mid + 1, right);

            // 4. Merge the two halves sorted in 2 and 3.
            Merge(ds, left, mid, right);
        }
    }

} // namespace

DataSet& sort::MergeSort(DataSet& ds) {
    ::MergeSort(ds, 0, ds.size - 1);
    return ds;
}


namespace {

    void QuickSort(DataSet& ds, int left, int right) {
        if (left < right) {
            // We will select the last element as the pivot.
            int i = left - 1; // index of smaller element
            int pivot = right;

            for (int j = left; j < right; j++) {
                if (ds[j] <= ds[pivot]) {
                    i++;
                    DataSet::Swap(ds[i], ds[j]);
                    std::cout << ds << std::endl;
                }
            }

            // Swap ds[i+1] with pivot
            DataSet::Swap(ds[i+1], ds[pivot]);
            pivot = i + 1;
            std::cout << ds << std::endl;

            QuickSort(ds, left, pivot - 1);
            QuickSort(ds, pivot + 1, right);
        }
    }

} // namespace

DataSet& sort::QuickSort(DataSet& ds) {
    ::QuickSort(ds, 0, ds.size - 1);
    return ds;
}
