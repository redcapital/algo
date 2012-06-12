// Uses: simulation, breadth-first search

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int N = 33;

int main(int argc, char const *argv[])
{
  int n, i, j, ans = 0;
  bool a[N + 2][N + 2] = { 0 }, u[N + 1][N + 1] = { 0 };
  cin >> n;
  for (i = 2; i < n + 2; i++)
    a[0][i] = a[n + 1][n - i + 1] = a[i][0] = a[n - i + 1][n + 1] = true;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) { char t; cin >> t; a[i][j] = t == '#'; }

  int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
  queue < pair<int, int> > q;
  q.push(make_pair(1, 1));
  q.push(make_pair(n, n));
  u[1][1] = u[n][n] = true;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (i = 0; i < 4; i++) {
      int nr = r + dir[i][0], nc = c + dir[i][1];
      if (nr >= 0 && nr <= n + 1 && nc >= 0 && nc <= n + 1 && a[nr][nc]) {
        ++ans;
      } else if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && !a[nr][nc] && !u[nr][nc]) {
        q.push(make_pair(nr, nc));
        u[nr][nc] = true;
      }
    }
  }
  cout << ans * 9 << endl;
  return 0;
}
