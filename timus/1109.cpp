// Uses: bipartite matching

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > g;
vector<int> from;
vector<bool> seen;
int n, m;

bool saturate(int v) {
  if (seen[v]) return false;
  seen[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (from[to] < 0 || saturate(from[to])) {
      from[to] = v;
      return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int k, bpSize = 0;
  cin >> n >> m >> k;
  g.resize(n);
  from.assign(m, -1);
  seen.resize(n);

  while (k--) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
  }

  for (int i = 0; i < n; i++) {
    fill(seen.begin(), seen.end(), false);
    if (!seen[i]) bpSize += saturate(i);
  }

  cout << n + m - bpSize << endl;
  return 0;
}
