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

  int slopes[10] = {
    1, 1,
    3, 1,
    5, 1,
    7, 1,
    1, 2,
  };

  int ans = 1;
  for (int sl = 0; sl < 10; sl += 2) {
    int r = 0, c = 0, num = 0;
    while (true) {
      r += slopes[sl + 1];
      if (r >= row) break;
      c = (c + slopes[sl]) % col;
      if (m[r][c]) {
        num++;
      }
    }
    cout << "Slope " << sl << " has " << num << " trees " << endl;
    ans *= num;
  }
  cout << ans << endl;
  return 0;
}

