#include <stdio.h>

#define ROW 2
#define COL 3

void Show(int* arr, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", arr[i*col + j]);
    }
  }
  printf("\n");
}

void ShowString(const char (*strings)[10], int count) {
  for (int i = 0; i < count; i++) {
    printf("%s\n", strings[i]);
  }
}

int main() {
  int arr[ROW][COL] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  Show((int*) arr, ROW, COL);


  char strings[2][10] = {
    "lol",
    "cat"
  };

  ShowString(strings, 2);
}


// 二維陣列感覺上是這樣
// 1 2 3
// 4 5 6

// 但在記憶體中是這樣
// 1 2 3 4 5 6
