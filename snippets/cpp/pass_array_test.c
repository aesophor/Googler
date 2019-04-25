#include <stdio.h>

void func(char arr[]) {
    printf("%c\n", arr[0]);
}

int main() {
    char arr[3] = {'W','o','w'};
    func(arr);
}
