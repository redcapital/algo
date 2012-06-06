// Uses: geometry

// Very simple problem, basically we need to sum the length of all segments
// and also add perimeter of a circle with radius R to the answer

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long double ld;
const ld PI = atan(1.0) * 4;

ld len(ld x1, ld y1, ld x2, ld y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(int argc, char const *argv[])
{
  int n;
  ld r, x, y, px, py, x0, y0, ans = 0;
  cin >> n >> r >> x0 >> y0;
  px = x0, py = y0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (i) ans += len(px, py, x0, y0);
    } else {
      cin >> x >> y;
      ans += len(x, y, px, py);
      px = x, py = y;
    }
  }
  ans += 2 * PI * r;
  printf("%.2Lf\n", ans);
  return 0;
}

