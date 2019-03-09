#include <iostream>

int main() {
    int size = 5;
    int arr[size + 1] = {1,2,3,4,5}; // variable-sized object may not be initialized
    int arr[size + 1]; // ok

    int arr[5] = {1,2,3,4,5}; // ok
}
