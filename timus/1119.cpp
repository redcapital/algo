// Uses: dynamic programming

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

const double INF = 1e12;
const double STEP = 100;
const double FSTEP = sqrt(STEP * STEP + STEP * STEP);

int main(int argc, char const *argv[])
{
  int n, m, k;
  set<int> fast;
  cin >> n >> m >> k;
  vector< vector<double> > d(n + 1, vector<double>(m + 1, INF));
  d[0][0] = 0;
  while (k--) {
    int a, b;
    cin >> a >> b;
    fast.insert((a - 1) * 1001 + b - 1);
  }

  queue< pair<int, int> > q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    pair<int, int> v = q.front();
    q.pop();
    double dist = STEP + d[v.first][v.second];
    if (v.first < n && dist < d[v.first + 1][v.second]) {
      d[v.first + 1][v.second] = dist;
      q.push(make_pair(v.first + 1, v.second));
    }
    if (v.second < m && dist < d[v.first][v.second + 1]) {
      d[v.first][v.second + 1] = dist;
      q.push(make_pair(v.first, v.second + 1));
    }
    if (fast.count(v.first * 1001 + v.second)) {
      dist = FSTEP + d[v.first][v.second];
      if (v.first < n && v.second < m && dist < d[v.first + 1][v.second + 1]) {
        d[v.first + 1][v.second + 1] = dist;
        q.push(make_pair(v.first + 1, v.second + 1));
      }
    }
  }

  cout << (long)round(d[n][m]) << endl;
  return 0;
}
