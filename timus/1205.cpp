// Uses: Dijkstra's_algorithm
//
// We have a graph where:
// - each station is a node
// - points A and B are nodes
// - all nodes have edges to every other node with edge cost = Distance/walking_speed (because we can walk from anywhere to anywhere)
// - each pair of connected stations have edges with edge cost = Distance/train_speed
//
// Now just run Dijkstra from node A and find min distance to B, while also remembering the path

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 200;
// vertex 0 = start
// vertex n + 1 = destination
double times[MAXN + 2][MAXN + 2];
double dist[MAXN + 2];
int path[MAXN + 2];
bool connected[MAXN + 2][MAXN + 2] = { 0 };
double x[MAXN + 2];
double y[MAXN + 2];
double speedF, speedU;

int main() {
  int n;
  cin >> speedF >> speedU;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  while (true) {
    int s1, s2;
    cin >> s1 >> s2;
    if (s1 == 0 && s2 == 0) break;
    connected[s1][s2] = connected[s2][s1] = true;
  }
  cin >> x[0] >> y[0] >> x[n + 1] >> y[n + 1];

  for (int v = 0; v <= n; v++) {
    for (int v2 = 1; v2 <= n + 1; v2++) {
      double diff = (x[v] - x[v2]) * (x[v] - x[v2]) + (y[v] - y[v2]) * (y[v] - y[v2]);
      times[v][v2] = sqrt(diff) / (connected[v][v2] ? speedU : speedF);
    }
  }

  for (int i = 1; i <= n + 1; i++) {
    dist[i] = -1;
  }
  dist[0] = 0;

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int v2 = 1; v2 <= n + 1; v2++) {
      double myDist = dist[v] + times[v][v2];
      if (dist[v2] < 0 || dist[v2] > myDist) {
        q.push(v2);
        dist[v2] = myDist;
        path[v2] = v;
      }
    }
  }
  printf("%.7f\n", dist[n + 1]);
  vector<int> ans;
  int v = path[n + 1];
  while (v != 0) {
    ans.push_back(v);
    v = path[v];
  }
  cout << ans.size() << " ";
  for (auto it = ans.rbegin(); it != ans.rend(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
