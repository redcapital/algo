// Uses: dynamic programming

// Let d[N][K] be the number of N-digit sequences that sum up to K
// The recurrence relation:
// d[N + 1][K] = sum(d[N][i]), max(K - 9, 0) <= i <= K
//
// Obviously d[1][K] = 1 if 0<=K<=9, and 0 otherwise
//
// N = (number of digits in input) / 2
// Answer = sum(d[N][K] ^ 2), 0 <= K <= N * 9

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, i, ans = 0, cur;
  cin >> n;
  n /= 2;
  int d[2][40] = { 0 };
  for (i = 0; i < 10; i++) d[0][i] = 1;
  for (i = 2, cur = 1; i <= n; i++, cur = 1 - cur) {
    d[cur][0] = 1;
    for (int k = 1; k <= 9 * i; k++) {
      d[cur][k] = 0;
      for (int j = max(k - 9, 0); j <= k; j++) {
        d[cur][k] += d[1 - cur][j];
      }
    }
  }
  cur = 1 - cur;
  for (i = 0; i <= n * 9; i++) {
    ans += d[cur][i] * d[cur][i];
  }
  cout << ans << endl;
  return 0;
}
