## Notes

Include all stuff
```cpp
#include <bits/stdc++.h>
```

Split a string into vector<string> by delimiter
```
vector<string> split(const string& s, const char delim) {
  stringstream ss(s);
  vector<string> tokens;
  string token;

  while (getline(ss, token, delim)) {
    if (token.size() > 1) {
      tokens.push_back(token);
    }
  }
  return tokens;
}
```
