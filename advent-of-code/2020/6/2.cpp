#include <iostream>
#include <cstring>

using namespace std;

int ans = 0;
int m[30], cnt;

void check() {
  for (int i = 0; i < 30; i++) {
    if (m[i] == cnt) {
      ans++;
    }
  }
}

int main() {
  string s;
  memset(m, 0, sizeof(m));
  cnt = 0;
  while (getline(cin, s)) {
    if (s.empty()) {
      check();
      memset(m, 0, sizeof(m));
      cnt = 0;
      continue;
    }
    cnt++;
    for (int i = 0; i < s.size(); i++) {
      m[s[i] - 'a']++;
    }
  }
  check();
  cout << ans << endl;
  return 0;
}

