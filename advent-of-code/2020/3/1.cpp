#include <iostream>
#include <cstring>

using namespace std;

bool m[1000][1000];

int main() {
  string s;
  int row = 0, col = 0;
  while (cin >> s) {
    col = s.size();
    for (int i = 0; i < s.size(); i++) {
      m[row][i] = s[i] == '#';
    }
    row++;
  }
  cout << row << " x " << col << endl;
  int r = 0, c = 0, ans = 0;
  while (r < row - 1) {
    r++;
    c = (c + 3) % col;
    if (m[r][c]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

