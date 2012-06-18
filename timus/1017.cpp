// Uses: dynamic programming

#include <iostream>

using namespace std;

const int MAXN = 500;

long long d[MAXN + 1][MAXN] = { 0 };
bool f[MAXN + 1][MAXN] = { 0 };

long long cnt(int n, int maxHeight) {
  if (!f[n][maxHeight]) {
    f[n][maxHeight] = true;
    if (n == 0) {
      d[n][maxHeight] = 1;
    } else {
      for (int h = min(maxHeight, n); h >= 1; h--) {
        d[n][maxHeight] += cnt(n - h, h - 1);
      }
    }
  }
  return d[n][maxHeight];
}

int main() {
  int n;
  cin >> n;
  cout << cnt(n, n - 1) << endl;
  return 0;
}

