#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int l, k, h;
  cin >> l >> k >> h;
  const double EPS = 1e-5;
  int segments = l / k;
  double res = segments * h;
  if (l % k) {
    printf("%.8lf %.8lf\n", res, res + h);
  } else {
    printf("%.8lf %.8lf\n", res, res);
  }
}

