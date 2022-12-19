#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main() {
  string s;
  int ans = 0;
  set<char> m;
  while (getline(cin, s)) {
    if (s.empty()) {
      ans += m.size();
      m.clear();
      continue;
    }
    for (int i = 0; i < s.size(); i++) {
      m.insert(s[i]);
    }
  }
  ans += m.size();
  cout << ans << endl;
  return 0;
}

