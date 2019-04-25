#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef enum bool
{
    false,
    true
} bool_t;

typedef struct dataset
{
    int data[SIZE];
} dataset_t;


// generate a dataset with the size 'gen_size',
// with each element between gen_min and gen_max.
void gen_dataset(dataset_t* self, int gen_min, int gen_max)
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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(dataset_t* self)
{
    bool_t swapped = true;

    while(swapped)
    {
        swapped = false;

        for(int i=0; i<SIZE-1; i++)
        {
            if(self->data[i] > self->data[i+1])
            {
                swap(&self->data[i], &self->data[i+1]);
                swapped = true;
            }
        }
        print(self);
    }
}

int main(int argc, char** args)
{
    dataset_t* ds = (dataset_t*)malloc(sizeof(dataset_t));
    
    gen_dataset(ds, 1, 100);
    print(ds);

    bubble_sort(ds);
    print(ds);
    
    free(ds);
    return 0;
}
