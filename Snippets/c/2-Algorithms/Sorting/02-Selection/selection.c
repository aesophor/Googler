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

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print(dataset_t* self)
{
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", self->data[i]);
    }
    printf("\n");
}

void selection_sort(dataset_t* self)
{
    // sorted | unsorted --> split into 2 sections
    for(int i=0; i<SIZE; i++)
    {
        int min = i;
        
        // find the smallest num in the unsorted section,
        // and store its index.
        for(int j=i+1; j<SIZE; j++)
        {
            if(self->data[j] < self->data[min])
            {
                min = j;
            }
        }
        
        // swap it with the currently pointed num..
        if(min != i)
        {
            swap(&self->data[min], &self->data[i]);
        }
        
        print(self);
    }
}

int main(int argc, char** args)
{
    dataset_t* ds = (dataset_t*)malloc(sizeof(dataset_t));

    gen_data(ds, 0, 100);
    print(ds);

    selection_sort(ds);
    print(ds);

    free(ds);
    return 0;
}
