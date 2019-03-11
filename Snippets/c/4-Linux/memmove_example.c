#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* args[], char* envp[])
{
    char* p1 = "fuxsocy";
    char* p2 = (char*)malloc(10*sizeof(char));
    char* p3 = memmove(p2, p1, 10);

    printf("*p3 = %s, *p2 = %s\n", p3, p2);
    free(p2);
    exit(0);
}
