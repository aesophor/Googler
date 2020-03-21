#include <iostream>

int main() {
  int A = 0;  // a + b
  int B = 0;  // b + c
  int C = 0;  // a + c
  std::cin >> A >> B >> C;

  // Reduce to rref
  // [1 1 0 | A]
  // [0 1 1 | B]
  // [1 0 1 | C]
  
  C -= A;
  C += B;
  C /= 2;
  B -= C;
  A -= B;

  std::cout << A << " " << B << " " << C << std::endl;
}
