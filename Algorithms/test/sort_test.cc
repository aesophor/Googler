#include "data_set.h"
#include "sort.h"
#include <iostream>

using namespace std;

int main() {
    DataSet ds = DataSet();

    cout << "Bubble Sort:" << endl
        << ds << endl
        << sort::BubbleSort(ds) << endl << endl;

    cout << "Insertion Sort:" << endl
        << ds.Randomize() << endl
        << sort::InsertionSort(ds) << endl << endl;

    cout << "Selection Sort:" << endl
        << ds.Randomize() << endl
        << sort::SelectionSort(ds) << endl << endl;

    cout << "Merge Sort:" << endl
        << ds.Randomize() << endl
        << sort::MergeSort(ds) << endl << endl;

    cout << "Quick Sort:" << endl
        << ds.Randomize() << endl
        << sort::QuickSort(ds) << endl << endl;
}
