#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// NOTE: int:
	/* The 32-bit int data type can hold integer values in the range of
	   −2,147,483,648 to 2,147,483,647. You may also refer to this data type as signed int or signed.
	*/

	// NOTE: unsigned int :
	/* The 32-bit unsigned int data type can hold integer values in the range of
	   0 to 4,294,967,295. You may also refer to this data type simply as unsigned.
	*/

    // 't' is the pointer to an object of type time_t (a signed int pointer),
    // where the seconds value will be stored.
    time_t t;
	t = time(NULL);

	// the code above can be replaced with the following...
	//unsigned* time_ptr;
	//time_ptr = time(NULL);

	// intializes random number generator. (both method below will work)
    srand((unsigned)time(&t));
	//srand(t);

    printf("In this program, we will use current time as seed, and generate 5 random numbers.\n");
    printf("Seed (seconds since 1970,1,1) = %d\n", t);
    
    // print 5 random numbers from 0 to 50.
    // NOTE: int i=0 is a new feature introduced in C99.
    //       back in C89, we have to use i=0 (old style).
    for(int i=0; i<5; i++) 
    {
        printf("[%d] %d\n", i+1, rand());
    }
    
    return(0);
}
