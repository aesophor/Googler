#include <cassert>

int main() {
  int* i = new int();
  delete i;

  char* c = new char[1];
  assert(i == (int*) c);
}
