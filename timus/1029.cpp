// Uses: Dijkstra's algorithm, priority queue

// Restating original problem in terms of graph theory gives us a problem of
// finding shortest path.
// Each room can be seen as vertex with at most 3 edges: forward, backward and
// up (some rooms don't have all 3 edges).
//
// I've used priority queue to speed up retrieving vertex with a minimum
// distance

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int INF = 2 * 1000 * 1000 * 1000;
const int M = 100;
const int N = 500;
const int V = M * N + 1; // Maximum number of vertices

using namespace std;

int w[V], d[V], p[V];
priority_queue < pair<int, int> > q;

inline void relax(int v, int to) {
  if (d[v] + w[to] < d[to]) {
    d[to] = d[v] + w[to];
    p[to] = v;
    q.push(make_pair(-d[to], to));
  }
}

int main(int argc, char const *argv[])
{
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < m; i++) for (int j = 1; j <= n; j++) cin >> w[i * n + j];

  for (int i = 0; i < V; i++) d[i] = INF;
  int highestFloor = (m - 1) * n + 1;
  for (int j = 1; j <= n; j++) {
    d[j] = w[j];
    q.push(make_pair(w[j], j));
  }
  while (!q.empty()) {
    int v = q.top().second, cur_d = -q.top().first;
    q.pop();
    if (cur_d > d[v]) continue;

    int mod = v % n;
    if (n > 1) {
      if (mod != 0) {
        // Move forward
        relax(v, v + 1);
      }
      if (mod != 1) {
        // Move backward
        relax(v, v - 1);
      }
    }
    if (v < highestFloor) {
      // Move up
      relax(v, v + n);
    }
  }

  // Choose the minimum room on upper floor
  int lastRoom = m * n;
  int minP = highestFloor;
  for (int i = highestFloor + 1; i <= lastRoom; i++) {
    if (d[i] < d[minP]) minP = i;
  }

  // Restore path to this room
  int v = minP;
  vector<int> path;
  while (v > n) {
    path.push_back(v);
    v = p[v];
  }
  path.push_back(v);

  for (int i = path.size() - 1; i >= 0; i--) {
    int mod = path[i] % n;
    if (mod == 0) cout << n; else cout << mod;
    cout << " ";
  }
  cout << endl;
  return 0;
}
