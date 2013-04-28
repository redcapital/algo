// If you write everything as one expression you'll get:
// 2^(some degree) * ( a1 * a2 * a3^2 * a4^4 * a5^8 * ... * an^(2^(n-2)) ) ^ ( 1 / 2 ^ (some degree))
//
// Doesn't look beautiful here, but the only part that matters to compute
// minimum possible weight is
// "a1 * a2 * ..." part.
// To minimize it you have to start from maximum weights because latter elements
// have a higher exponent.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);
  double res = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    res = 2 * sqrt(res * a[i]);
  }
  printf("%.2f\n", res);
  return 0;
}
