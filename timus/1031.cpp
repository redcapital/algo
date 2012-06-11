// Uses: dynamic programming

#include <iostream>

using namespace std;

const int INF = 2 * 1000 * 1000 * 1000;
const int N = 10000;
int dist[N + 1], ans[N + 1];

int main(int argc, char const *argv[])
{
  int l[3], c[3], i, j, k, n, a, b;
  for (i = 0; i < 3; i++) cin >> l[i];
  for (i = 0; i < 3; i++) cin >> c[i];
  cin >> n >> a >> b;
  if (a > b) { int t = a; a = b; b = t; }
  dist[1] = 0;
  for (i = 2; i <= n; i++) {
    cin >> dist[i];
  }
  for (i = 1; i <= N; i++) ans[i] = INF;
  ans[a] = 0;
  for (i = a; i < b; i++) {
    for (j = i + 1; j <= b; j++) {
      bool ok = false;
      for (k = 0; k < 3; k++) {
        if (dist[i] + l[k] >= dist[j]) {
          ok = true;
          ans[j] = min(ans[j], ans[i] + c[k]);
          break;
        }
      }
      if (!ok) break;
    }
  }
  cout << ans[b] << endl;
  return 0;
}
