#include <stdio.h>

void f(int** pptr, int* target)
{
    *pptr = target;
    return;
}

int main(int argc, char** args)
{
    int data = 15;
    int target = 20;
    int* ptr = &data;
    int** pptr = &ptr;

    f(pptr, &target);

    printf("result: %d\n", **pptr);
    return 0;
}
