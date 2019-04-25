#include <stdio.h>  // printf()
#include <stdlib.h> // malloc()
#include <string.h> // memset()

extern void* calloc(size_t nmemb, size_t size)
{
    void* p;
    size_t total;
    total = nmemb * size;
    p = malloc(total);

    if(p != NULL) { memset(p, '\0', total); }
    return p;
}


int main(int argc, char* args[], char* envp[])
{
    int count = 20;
    int* ptr = (int*)calloc(count, sizeof(int));

    for(int i=0; i<count; i++)
    {
        printf("[%p] %4d\n", ptr, *ptr);
        ptr++;
    }

    exit(0);
}
