#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int m[1000][1000];

int main() {
  int x1, y1, x2, y2;
  memset(m, 0, sizeof(m));
  while (!feof(stdin)) {
    scanf("%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2);

    if (x1 == x2) {
      for (int i = min(y1, y2); i <= max(y1, y2); i++) {
        m[x1][i]++;
      }
    } else if (y1 == y2) {
      for (int i = min(x1, x2); i <= max(x1, x2); i++) {
        m[i][y1]++;
      }
    } else {
      if (x1 < x2) {
        if (y1 < y2) {
          for (int i = x1, j = y1; i <= x2; i++, j++) {
            m[i][j]++;
          }
        } else {
          for (int i = x1, j = y1; i <= x2; i++, j--) {
            m[i][j]++;
          }
        }
      } else {
        if (y1 < y2) {
          for (int i = x2, j = y2; i <= x1; i++, j--) {
            m[i][j]++;
          }
        } else {
          for (int i = x2, j = y2; i <= x1; i++, j++) {
            m[i][j]++;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (m[i][j] > 1) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

