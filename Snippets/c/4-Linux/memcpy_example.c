#include <stdio.h>  // printf()
#include <stdlib.h> // malloc()
#include <string.h> // memcpy()

int main(int argc, char* args[], char* envp[])
{
    char* p1 = "fuxsocy";
    char* p2 = (char*)malloc(10*sizeof(char));

    // we wouldn't write something like
    // p2 = memcpy(p2, p1, 10);
    // because if memcpy failed, we cant get the original address.
    char* p3 = memcpy(p2, p1, 10);

    printf("p3 = %p, p2 = %p\n", p3, p2);
    free(p2);

    exit(0);
}
