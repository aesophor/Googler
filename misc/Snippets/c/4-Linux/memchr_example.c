#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* args[], char* envp[])
{
    char* p1 = "asdafsfaefuaesfa";
    char* p2 = NULL;
    char* p3 = NULL;

    p2 = memchr(p1, 0x75, 17);
    printf("search result: %d\n", p2-p1);

    exit(0);
}
