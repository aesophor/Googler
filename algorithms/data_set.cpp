#include <iostream>
#include "data_set.hpp"

DataSet::DataSet(int capacity, int min, int max) : size(capacity) {
    data = new int[capacity];

    srand(time(NULL));
    for (int i = 0; i < capacity; i++) {
        data[i] = RandInt(min, max);
    }
}

DataSet::~DataSet() {
    delete data;
}


int DataSet::RandInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void DataSet::Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int& DataSet::operator[] (int i) const {
    return data[i];
}

std::ostream& operator<< (std::ostream& os, const DataSet& ds) {
    for (int i = 0; i < ds.size; i++) {
        os << ds[i];
        if (i != ds.size - 1) {
            os << " ";
        }
    }
    return os;
}
