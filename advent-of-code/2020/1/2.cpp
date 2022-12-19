#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> s;
  while (cin >> n) {
    s.push_back(n);
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      for (int k = j + 1; k < s.size(); k++) {
        if (s[i] + s[j] + s[k] == 2020) {
          cout << s[i] * s[j] * s[k] << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

