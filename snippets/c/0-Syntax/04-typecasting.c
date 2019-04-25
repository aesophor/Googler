#include <stdio.h>

int main(int argc, char** args)
{
    int arr[5] = {0,1,2,3,4};
    int* ptr = (int*)(&arr+1);
    printf("%d\n", *(ptr-1));
}
