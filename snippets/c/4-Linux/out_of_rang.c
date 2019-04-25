#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[], char* envp[])
{
    int len = 5;
    int *p = (int*)malloc(len*sizeof(int));

    for(int i=0; i<len; i++)
    {
        p++;
    }
    *p = 5;

    printf("%d\n", *p);
    return 0;
}
