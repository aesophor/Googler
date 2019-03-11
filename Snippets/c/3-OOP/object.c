#include <stdio.h>
#include <stdlib.h>

typedef struct base
{
    /* base member here. */
} base_t;

typedef struct derived
{
    base_t* super;
} derived_t;


int main(int argc, char** args)
{
    base_t* b;
    derived_t* d = (derived_t*) b; /* downcast */

    b = (base_t*) d; /* upcast */
}
