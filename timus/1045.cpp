// Uses: depth-first search

#include <iostream>

using namespace std;

const int N = 1000;

int n, k, ans;
bool g[N + 1][N + 1] = { 0 };
bool u[N + 1] = { 0 };

// Returns true if the gamer who starts from vertex s wins, false otherwise
bool dfs(int s) {
  for (int i = 1; i <= n; i++) {
    if (g[s][i] && !u[i]) {
      u[i] = true;
      if (!dfs(i)) {
        ans = i;
        return true;
      }
      u[i] = false;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = true;
  }
  u[k] = true;
  if (dfs(k)) cout << "First player wins flying to airport " << ans;
  else cout << "First player loses";
  cout << endl;
  return 0;
}
