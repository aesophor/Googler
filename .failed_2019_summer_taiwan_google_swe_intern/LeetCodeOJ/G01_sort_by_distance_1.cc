#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void PrintSorted(int n) {
    int current = 0;
    int end = pow(10, n) - 1;

    bool increment = true;
    int count = 0;

    while (current <= end) {
        for (int i = 0; i < 9; i++) {
            cout << current << " ";

            if (increment) {
                current++;
            } else {
                current--;
            }
        }

        cout << current << " ";

        if (count == 9) {
            current += 100;
            count++;
        } else if (count > 9 && count <= 18) {
            current -= 10;
            count++;
        } else if (count == 19) {
            current += 100;
            count = 0;
        } else {
            current += 10;
            count++;
        }
        increment = !increment;
    }
}

int main() {
    int n = 3;
    PrintSorted(n);
}
