#include <iostream>
#include <fstream>

using namespace std;

class A {
public:
  A();
  virtual ~A();

  friend ofstream& operator<< (ofstream& ofs, const A& a);

private:
  int member_ = 0;
};

ofstream& operator<< (ofstream& ofs, const A& a) {
  ofs << a.member_;
  return ofs;
}


int main() {
  A a;
  cout << a; // invalid operands to binary expression (ostream and A)

  ofstream fout("test.txt"); // ok
  fout << a;
}
