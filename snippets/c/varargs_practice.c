#include <stdio.h>
#include <stdarg.h>

int sum(int argc, ...) {
  va_list ap;
  va_start(ap, argc);

  int sum = 0;
  for (int i = 0; i < argc; i++) {
    sum += va_arg(ap, int);
  }
  va_end(ap);
  return sum;
}

int main(int argc, char *args[]) {
  printf("the sum is: %d\n", sum(3, 2, 4, 6));
}
