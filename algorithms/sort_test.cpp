#include "data_set.hpp"
#include "sort.hpp"
#include <iostream>

using namespace std;

int main() {
    DataSet ds = DataSet();
    cout << ds << endl;

    sort::BubbleSort(ds);
    cout << ds << endl;
}
