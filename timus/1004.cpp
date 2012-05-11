// Uses: Dijkstra's algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1000000000;

// Graph is represented as an array of pairs, where array index is vertex number,
//  and pair's first element is destination vertex number, second element is weight
vector < vector < pair<int, int> > > g;

// Variables for Dijkstra algo
vector <int> d;
bool u[101];
int p[101];

int n, m, minloop;

// This will contain final answer (if any)
vector<int> minpath;

// Standard implementation of Dijkstra, nothing special
// Finds all distances from vertex s
void dijkstra(int s) {
  d.clear();
  d.resize(n + 1, INF);
  d[s] = 0;
  memset(p, 0, sizeof(p));
  memset(u, 0, sizeof(u));
  for (int i = 1; i <= n; i++) {
    int v = -1;
    for (int j = 1; j <= n; j++)
      if (!u[j] && (v == -1 || d[j] < d[v])) v = j;
    if (d[v] == INF) break;

    u[v] = true;
    for (int j = 0; j < g[v].size(); j++) {
      int to = g[v][j].first, len = g[v][j].second;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int s;
  while (true) {
    cin >> n;
    if (n == -1) break;

    // Read graph
    g.clear();
    g.resize(n + 1);
    cin >> m;
    for (size_t i = 0; i < m; ++i)
    {
      int e, w;
      cin >> s >> e >> w;
      g[s].push_back(make_pair(e, w));
      g[e].push_back(make_pair(s, w));
    }

    minloop = INF;
    // Loop through every vertex
    for (int i = 1; i <= n; i++) {
      int min1, min2 = -1;
      dijkstra(i);

      // Loop through every edge and consider those which don't belong to
      // the tree of minimum distances
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < g[j].size(); k++) {
          int to = g[j][k].first, len = g[j][k].second;
          if (p[j] != to && p[to] != j) {
            // If such edge forms a loop which is shorter than minloop, then
            // save its vertices
            if (d[j] + len + d[to] < minloop) {
              minloop = d[j] + len + d[to];
              min1 = j;
              min2 = to;
            }
          }
        }
      }
      if (min2 != -1) {
        // If we found a better loop, construct its path
        // Path is constructed as <Path from v to min1> + <Path from min2 to v>
        minpath.clear();
        for (int v = min1; v != i; v = p[v]) minpath.push_back(v);
        minpath.push_back(i);
        reverse(minpath.begin(), minpath.end());
        for (int v = min2; v != i; v = p[v]) minpath.push_back(v);
      }
    }
    if (minloop == INF) {
      cout << "No solution." ;
    } else {
      for (int i = 0; i < minpath.size(); i++) cout << minpath[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
