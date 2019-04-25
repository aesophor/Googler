#include <stdio.h>
#include <stdlib.h>

int* f()
{
    int a = 15;
    int* ptr = &a;
    return ptr;
}

int main(int argc, char** args)
{
    int* p = f();
    // at this stage, 
    // local variable 'a' has been popped from the stack.
    // so although p holds a's original addr,
    // it's now possible be overwritten by other var/funcs.
    // as it is already freed by the operating system.
    
    return 0;
}
