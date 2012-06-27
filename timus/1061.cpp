// Suppose we know sum for some interval a[l, r] of K digits is S. To
// find sum for next interval we just calculate S - a[l] + a[r + 1].
// If a[r + 1] = '*' we try to find S starting from r + 2.
// This means the problem can be solved in O(N)

#include <iostream>
#include <string>

using namespace std;

const int N = 100000;

int main(int argc, char const *argv[])
{
  static int a[N];
  int n, k, an = 0;
  string tmp;
  cin >> n >> k;
  while (true) {
    cin >> tmp;
    for (int i = 0; i < tmp.length(); i++)
      a[an++] = (tmp[i] == '*') ? 10 : (tmp[i] - '0');
    if (an == n) break;
  }

  int s = 0, sc = 0, mins, ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 10) {
      sc = s = 0;
    } else {
      s += a[i];
      ++sc;
      if (sc == k) {
        if (!ans || s < mins) {
          ans = i - k + 2;
          mins = s;
        }
        s -= a[i - k + 1];
        --sc;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
