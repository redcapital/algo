// Uses: dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

const int L = 0;
const int C = 1;
const int P = 2;
const long long MAXX = (long long)1 << 62;

struct upd {
  int d, p, t;
};
vector<upd> u[10001];
  long long d[10001][2];

int main() {
  int n, m;
  cin >> n >> m;
  int f;
  string tmp;
  for (int i = 0; i < m; i++) {
    upd cu;
    cin >> f >> cu.t >> cu.d;
    cin >> tmp;
    if (tmp[0] == 'L') cu.p = L;
    else if (tmp[0] == 'P') cu.p = P;
    else  cu.p = C;
    u[f].push_back(cu);
  }

  for (int i = 0; i < 10001; i++) d[i][0] = d[i][1] = MAXX;
  d[1][0] = d[1][1] = 0;
  for (int v = 1; v <= n; v++) {
    for (int i = 0; i < u[v].size(); i++) {
      long long dist;
      // from cracked
      if (d[v][1] < MAXX && u[v][i].p != L) {
        dist = d[v][1] + u[v][i].d;
        if (dist < d[u[v][i].t][1]) {
          d[u[v][i].t][1] = dist;
        }
      }

      // from legal
      dist = d[v][0] + u[v][i].d;
      int status = (u[v][i].p == P) ? 1 : 0;
      if (dist < d[u[v][i].t][status]) {
        d[u[v][i].t][status] = dist;
      }
    }
  }
  long long ans = min(d[n][0], d[n][1]);
  if (ans < MAXX) {
    cout << "Online" << endl << ans << endl;
  } else {
    cout << "Offline" << endl;
  }
  return 0;
}
