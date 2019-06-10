#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string capitalize(string& sentence) {
  if (!sentence.empty()) {
    sentence[0] = std::toupper(sentence[0]);
  }

  bool nextCharShouldUpper = false;
  for (auto& c : sentence) {
    if (c == '.' || c == '?' || c == '!') {
      nextCharShouldUpper = true;
    } else if (nextCharShouldUpper && c != ' ') {
      c = std::toupper(c);
      nextCharShouldUpper = false;
    }
  }
  return sentence;
}

char* capitalize(char* sentence) {
  if (strlen(sentence) > 0) {
    sentence[0] = std::toupper(sentence[0]);
  }

  bool nextCharShouldUpper = false;
  for (int i = 0; i < (int) strlen(sentence); i++) {
    if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') {
      nextCharShouldUpper = true;
    } else if (nextCharShouldUpper && sentence[i] != ' ') {
      sentence[i] = std::toupper(sentence[i]);
      nextCharShouldUpper = false;
    }
  }
  return sentence;
}


int main() {
  cout << "Enter a sentence: ";
  /*
  string input;
  getline(cin, input);
  cout << capitalize(input);
  */

  char input[100] = {0};
  fgets(input, 100, stdin);
  cout << capitalize(input) << endl;

  return 0;
}
