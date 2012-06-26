// Uses: breadth-first search

// Consider the longest path formed by vertices v1, v2, v3, ..., vk
// If k is odd, center will be v[k / 2], otherwise there will be 2 centers:
// v[k / 2] and v[k / 2 + 1]
//
// To find this path, run BFS from any leaf (since vertice N is always a leaf,
// we can start from N) and take the farthest vertex V. This vertex will be
// a start of the path.
// Run BFS from V and take the farthest vertex U (store visited vertices to
// reconstruct the path). Path from V to U will be the longest.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 10000;

vector<int> g[N + 1];
bool f[N + 1] = { 0 };
int path[N + 1] = { 0 };

int main(int argc, char const *argv[])
{
  int n, t;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> t;
    g[t].push_back(i);
    g[i].push_back(t);
  }
  queue<int> q;
  q.push(n);
  f[n] = true;
  int v;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      if (!f[g[v][i]]) {
        f[g[v][i]] = true;
        q.push(g[v][i]);
      }
    }
  }

  int u = v;
  q.push(v);
  path[v] = v;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      if (!path[g[v][i]]) {
        path[g[v][i]] = v;
        q.push(g[v][i]);
      }
    }
  }
  vector<int> longestPath;
  while (v != u) {
    longestPath.push_back(v);
    v = path[v];
  }
  longestPath.push_back(u);
  if (longestPath.size() % 2) {
    cout << longestPath[longestPath.size() / 2] << endl;
  } else {
    int offset = (longestPath.size() - 2) / 2;
    if (longestPath[offset + 1] < longestPath[offset])
      swap(longestPath[offset + 1], longestPath[offset]);
    cout << longestPath[offset] << " " << longestPath[offset + 1] << endl;
  }
  return 0;
}
