#ifndef DATA_SET_H_
#define DATA_SET_H_

#include <iostream>

struct DataSet {
  DataSet(int capacity=10, int min=0, int max=100);
  ~DataSet();

  DataSet& Randomize(int min=0, int max=100);

  static int RandInt(int min, int max);
  static void Swap(int& a, int& b);

  int* data;
  const int size;

  int& operator[] (int i) const;
  friend std::ostream& operator<< (std::ostream& os, const DataSet& ds);
};

#endif
