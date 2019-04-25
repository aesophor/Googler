#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* gen_num()
{
    // generate a number between 0~14.
    srand(time(NULL));
    int ret = rand()%15;
    int* p = &ret;
    return p;
}

int sum(int* a, int* b)
{
    return (*a)+(*b);
}

int main(int argc, char** args)
{
    // Callback function without fp.
    int result = sum(gen_num(), gen_num());
    printf("The result is: %d\n", result);

    // Callback function with fp.
    //(int*)gen_num() = &gen_num;
    int* (*p_gen_num)() = gen_num;
    int fp_result = sum(p_gen_num(), p_gen_num());
    printf("The result is: %d\n", fp_result);
}
