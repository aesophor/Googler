#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>

struct Sequence {
  Sequence(int capacity=10, int min=0, int max=100);
  ~Sequence();

  Sequence& Randomize(int min=0, int max=100);

  static int RandInt(int min, int max);
  static void Swap(int& a, int& b);

  int* data;
  const int size;

  int& operator[] (int i) const;
  friend std::ostream& operator<< (std::ostream& os, const Sequence& ds);
};

#endif // SEQUENCE_H_
