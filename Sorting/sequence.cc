#include <iostream>

#include "sequence.h"

Sequence::Sequence(int capacity, int min, int max) : size(capacity) {
  data = new int[capacity];

  srand(time(NULL));
  Randomize(min, max);
}

Sequence::~Sequence() {
  delete data;
}


Sequence& Sequence::Randomize(int min, int max) {
  for (int i = 0; i < size; i++) {
    data[i] = RandInt(min, max);
  }
  return *this;
}

int Sequence::RandInt(int min, int max) {
  return min + (rand() % (max - min + 1));
}

void Sequence::Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}


int& Sequence::operator[] (int i) const {
  return data[i];
}

std::ostream& operator<< (std::ostream& os, const Sequence& ds) {
  for (int i = 0; i < ds.size; i++) {
    os << ds[i];
    if (i != ds.size - 1) {
      os << " ";
    }
  }
  return os;
}
