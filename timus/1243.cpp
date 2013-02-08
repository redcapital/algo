// Uses: modular arithmetic
//
// Any n-digit number (in base 10) can be written as
// a[0] * 10^(n-1) + a[1] * 10^(n-2) + ... + a[n-1] * 10^0,
// where a[] represents digits, and a[0] is the most significiant digit
//
// Since we need to find "N mod 7" (remainder of N divided by 7), we can safely
// compute it as
// (a[0] * 10^(n-1) mod 7) + (a[1] * 10^(n-2) mod 7) ...
//
// The powers of 10 can also be computed as (10 mod 7) * (10 mod 7) ...

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int s = 0, deg = 1, n = 0;
  char c[51];
  while (cin >> c[n]) {
    c[n] = c[n] - '0';
    ++n;
  }
  while (n--) {
    s = (c[n] * deg + s) % 7;
    deg = (deg * 10) % 7;
  }
  cout << s;
  return 0;
}
