#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* args[], char* envp[])
{
    const char* p = "I am Mr Robot.";

    for(int i=0; i<16; i++)
    {
        printf("[%p]: %c\n", p, *p);
        p++;
    }
    
    // as you can see, ascii strings aren't saved in little endian form.
    // storing string in little endian in utter nonsense.
    return 0;
}
