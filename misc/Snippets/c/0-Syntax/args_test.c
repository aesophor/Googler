#include <stdio.h>

int main(int argc, char* args[])
{
    // printf("sizeof(char) is %d\n", sizeof(char)); --> 1
    // printf("sizeof(char*) is %d\n", sizeof(char*)); --> 8 ( 64-bit machines have 8-bit ptrs )

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", args[i]);
    }
}
