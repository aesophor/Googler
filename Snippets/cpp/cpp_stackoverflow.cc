#include <iostream>

using namespace std;

int f() {
    static int count = 1;
    cout << count << endl;
    count++;
    f();
}

int main() {
    f();
}
