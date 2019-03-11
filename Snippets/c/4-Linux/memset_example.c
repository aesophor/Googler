#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* args[], char* envp[])
{
    char* p = (char*)malloc(4*sizeof(char));
    memset(p, '\0', 4);
    printf("memset: memory is %s\n", memset(p, 'a', 3));

    bzero(p, 1);
    printf("memset: memory is %s\n", p);

    printf("memset: memory is %s\n", p+1);
    return 0;
}
