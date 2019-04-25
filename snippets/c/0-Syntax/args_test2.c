#include <stdio.h>

int main(int argc, char** args)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", args[i]);
    }
}
