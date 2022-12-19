#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 120;

int main() {
  string g[2][N];
  int rows = 0, cols;
  while (getline(cin, g[0][rows])) {
    g[1][rows] = g[0][rows];
    rows++;
  }
  cols = g[0][0].size();

  int curGrid = 0;
  while (true) {
    int nextGrid = curGrid ? 0 : 1;

    for (int i = 0; i < rows; i++) {
      g[nextGrid][i] = g[curGrid][i];
      for (int j = 0; j < cols; j++) {
        if (g[curGrid][i][j] == '.') continue;

        int occupied = 0;
        for (int k = -1; k < 2; k++) {
          for (int m = -1; m < 2; m++) {
            if (k == 0 && m == 0) continue;

            int idx1 = i + k, idx2 = j + m;

            if (idx1 < 0 || idx1 >= rows || idx2 < 0 || idx2 >= cols) continue;

            if (g[curGrid][idx1][idx2] == '#') {
              occupied++;
            }
          }
        }

        if (g[curGrid][i][j] == 'L') {
          if (occupied == 0) {
            g[nextGrid][i][j] = '#';
          }
        } else if (g[curGrid][i][j] == '#') {
          if (occupied >= 4) {
            g[nextGrid][i][j] = 'L';
          }
        }
      }
    }

    bool same = true;
    for (int i = 0; i < rows; i++) {
      if (g[curGrid][i] != g[nextGrid][i]) {
        same = false;
        break;
      }
    }
    if (same) {
      break;
    }
    curGrid = nextGrid;
  }


  int ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (g[0][i][j] == '#') {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
