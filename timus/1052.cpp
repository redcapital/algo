// Uses: geometry

// Line crossing two points A (xa, ya) and B (xb, yb) is represented by equation:
// (ya - yb) * x + (xb - xa) * y = xb * ya - xa * yb

#include <iostream>

using namespace std;

const int N = 200;

struct point {
  int x, y;
};

int main(int argc, char const *argv[])
{
  int n, ans = 0;
  point p[N];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int x = p[i].y - p[j].y, y = p[j].x - p[i].x,
          c = p[j].x * p[i].y - p[i].x * p[j].y,
          cur = 2;
      for (int k = j + 1; k < n; k++) {
        if (x * p[k].x + y * p[k].y == c) cur++;
      }
      if (cur > ans) ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
