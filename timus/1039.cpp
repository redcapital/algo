// Uses: dynamic programming, topological sorting

// Let d[0][i] be maximum answer for a tree rooted at i, when we don't take i
// to the party
// Likewise, let d[1][i] be maximum answer when we take him to the party
//
// This leads to the following recurrent relations (i is some vertex):
// d[0][i] = sum(max(d[0][j], d[1][j])) for all j who is child of i
// d[1][i] = r[i] + sum(d[0][j]) for all j who is child of i
//
// Answer will be max(d[0][v], d[1][v]) where v is the root of the whole tree
//
// We need to solve subproblems bottom up, this means we must start from leafs
// To do so, we'll sort vertices in topological order

#include <iostream>
#include <vector>

using namespace std;

const int N = 6000;
bool u[N + 1] = { 0 };
int s[N + 1], n, r[N + 1], ss = 0, d[2][N + 1];
vector <int> g[N + 1];

void dfs(int v) {
  u[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    if (!u[g[v][i]]) dfs(g[v][i]);
  }
  s[ss++] = v;
}

void topologicalSort() {
  for (int i = 1; i <= n; i++) if (!u[i]) dfs(i);
}

int main(int argc, char const *argv[])
{
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> r[i];
  while (true) {
    int l, k;
    cin >> l >> k;
    if (l == 0 && k == 0) break;
    g[k].push_back(l);
  }
  topologicalSort();
  for (int i = 0; i < n; i++) {
    int v = s[i];
    d[0][v] = 0;
    for (int j = 0; j < g[v].size(); j++) {
      d[0][v] += max(d[0][g[v][j]], d[1][g[v][j]]);
    }
    d[1][v] = r[v];
    for (int j = 0; j < g[v].size(); j++) {
      d[1][v] += d[0][g[v][j]];
    }
  }
  cout << max(d[0][s[n - 1]], d[1][s[n - 1]]) << endl;
  return 0;
}
