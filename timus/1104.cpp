#include <iostream>

using namespace std;

char a[1000000];

int main(int argc, char const *argv[])
{
  int n = 0, maxDigit = 0, ans = 0;
  char c;
  while (cin >> c) {
    if (!cin) break;
    if (c <= '9') c -= '0'; else c = c - 'A' + 10;
    a[n++] = c;
    if (c > maxDigit) maxDigit = c;
  }
  if (maxDigit == 0) {
    ans = 2;
  } else {
    for (int k = maxDigit + 1; k < 37; k++) {
      int rem = 0;
      for (int i = n - 1, prod = 1, div = k - 1; i >= 0; i--) {
        rem = (rem + a[i] * prod) % div;
        prod = (prod * k) % div;
      }
      if (rem == 0) {
        ans = k;
        break;
      }
    }
  }

  if (ans) cout << ans; else cout << "No solution.";
  cout << endl;
  return 0;
}
