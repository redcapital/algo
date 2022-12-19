#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> p[2];
  string s;
  int curp;
  while (getline(cin, s)) {
    if (s.empty()) continue;
    if (s[0] == 'P') {
      sscanf(s.c_str(), "Player %d", &curp);
    } else {
      int d;
      sscanf(s.c_str(), "%d", &d);
      p[curp - 1].push_back(d);
    }
  }

  while (true) {
    int x1 = p[0][0], x2 = p[1][0];
    p[0].erase(p[0].begin());
    p[1].erase(p[1].begin());
    if (x1 > x2) {
      p[0].push_back(x1);
      p[0].push_back(x2);
    } else {
      p[1].push_back(x2);
      p[1].push_back(x1);
    }

    if (p[0].empty()) {
      curp = 1;
      break;
    } else if (p[1].empty()) {
      curp = 0;
      break;
    }
  }

  cout << (curp + 1) << " has won " << endl;

  int ans = 0, mul = 1;
  for (auto it = p[curp].rbegin(); it != p[curp].rend(); it++, mul++) {
    ans += *it * mul;
  }

  cout << ans << endl;

  return 0;
}
