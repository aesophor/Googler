#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T>
class Vector {
 public:
  Vector();
  virtual ~Vector();

 private:
  T* data_;
};

#endif // VECTOR_H_
