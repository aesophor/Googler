#include <stdio.h>
#include <stdlib.h>

int f(int round)
{
    auto int i = 0;
    static int j = 5;

    i++;
    j++;

    i++;
    j++;

    printf("--round %d--\n", round);
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("\n");
}

int main(int argc, char** args)
{
    int (*func_p)(int) = f;
    func_p(1);
    func_p(2);
    return 0;
}
