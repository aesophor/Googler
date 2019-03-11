#include <stdio.h>  // printf()
#include <stdlib.h> // realloc()

int main(int argc, char* args[], char* envp[])
{
    int input;
    int *numbers1;
    int *numbers2;

    if((numbers2=(int*)malloc(sizeof(5*sizeof(int)))) == NULL)
    {
        printf("malloc memory unsuccessful");
        exit(1);
    }

    for(int i=0; i<5; i++)
    {
        *(numbers2 + i) = i;
        printf("numbers2's data: %d\n", *(numbers2 + i));
    }

    printf("Enter an integer value you want to realloc (enter 0 to stop): ");
    scanf("%d", &input);

    // Normally, we wouldn't write something like...
    // ptr = realloc(ptr, new_size);
    // If realloc fails, we won't be able to retrieve the original mem address.
    if((numbers1=(int*)realloc(numbers2, (5+input)*sizeof(int))) == NULL)
    {
        printf("Error (re)allocating memory");
        exit(1);
    }

    for(int i=0; i<5; i++)
    {
        printf("the number1s's data copy from numbers2: %d\n", *(numbers1 + i));
    }

    for(int i=0; i<input; i++)
    {
        *(numbers1 + 5 + i) = i*2;
        printf("number1's new data: %d\n", *(numbers1 + 5 + i));
    }

    printf("\n");
    free(numbers1);
    numbers1 = NULL;
    exit(0);
}
