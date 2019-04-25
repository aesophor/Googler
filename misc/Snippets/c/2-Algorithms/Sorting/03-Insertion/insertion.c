#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

typedef struct dataset
{
    int data[SIZE];
} dataset_t;


void gen_data(dataset_t* self, int gen_min, int gen_max)
{
    srand(time(NULL));
    for(int i=0; i<SIZE; i++)
    {
        self->data[i] = (rand() % (gen_max-gen_min+1)) + gen_min;
    }
}

void print(dataset_t* self)
{
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", self->data[i]);
    }
    printf("\n");
}

void insertion_sort(dataset_t* self)
{
    // iterate through the array, starting from index 1.
    for(int i=1; i<SIZE; i++)
    {
        // we will place it at correct position in the sorted section.
        // cache its value first. (as it may be replaced later.)
        int cur = self->data[i];
        
        // make room for the new location of the data.
        // check from right to left.
        int ptr = i;
        while(cur < self->data[ptr-1])
        {
            self->data[ptr] = self->data[ptr-1];
            ptr--;
            
            if(ptr == 0) { break; }
        }
        self->data[ptr] = cur;
        
        print(self);
    }
}


int main(int argc, char** args)
{
    dataset_t* ds = (dataset_t*)malloc(sizeof(dataset_t));

    gen_data(ds, 0, 100);
    print(ds);

    insertion_sort(ds);
    print(ds);

    free(ds);
    return 0;
}
