#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<string, int> grades;
    grades["John"] = 35;
    grades["Tim"] = 50;
    grades["Marco"]++;

    // Check if key exists in an unordered_map
    if (grades.find("Marco") != grades.end()) {
        cout << "Key found!" << endl;
        cout << "His grade is: " << grades["Marco"] << endl;
    }
}
