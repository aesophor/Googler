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
        self->data[i] = rand() % (gen_max + 1) + gen_min;
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
        // pick up current data, and place it at correct position.
        int cur = self->data[i];
       
        // look for its correct position.
        for(int j=0; j<i; j++)
        {
            if(cur < self->data[j])
            {
                // found it. now make room for it.
                for(int k=i; k>=j; k--)
                {
                    self->data[k] = self->data[k-1];
                }
                self->data[j] = cur;
                break;
            }
        }

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
