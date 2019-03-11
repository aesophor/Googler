#include <stdio.h>
#include <stdlib.h>

int* retlocaladdr()
{
    /* variable 'i' will be popped from the stack
     * once this function ends!
     */
    int i = 12;
    return &i;
}

int* f()
{
    /* use malloc to allocate some space for it. */
    int* p = (int*)malloc(sizeof(int));
    *p = 12;
    return p;
}


int main(int argc, char** args)
{
    printf("%d\n", *f());
    printf("%d\n", *retlocaladdr());
    return 0;
}
