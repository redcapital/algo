#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<s<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};

int rows=0,cols=0;

vector<int> g[500];
vector<bool> vis[500];
int dists[500][500];

int rec(int x, int y, int dist) {
  if (x == rows - 1 && y == cols - 1) {
    return dist;
  }
  int ans = 9999;
  for (int d = 0; d < 4; d++) {
    int nx = x + dd[d][0];
    int ny = y + dd[d][1];
    cerr << nx << " " << ny << endl;
    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
      if (!vis[nx][ny]) {
        vis[nx][ny] = true;
        int ndist = rec(nx, ny, dist + g[nx][ny]);
        vis[nx][ny] = false;
        if (ndist < 0) continue;
        if (ans < 0 || ndist < ans) {
          ans = ndist;
        }
      }
    }
  }
  cout << "at  " << x << " " << y << " = " << ans <<endl;
  return ans;
}

struct gnode {
  int x, y, dist;
};

int main() {
  string s;
  vector<string> vs;
  while (getline(cin, s)) {
    if (!cols) {
      cols=s.size();
    }
    FOR(i,s.size()) {
      vis[rows].push_back(false);
      g[rows].push_back(s[i] - '0');
    }
    rows++;
  }
  //FOR(i,rows) {
    //FOR(j,cols) {
      //cout << g[i][j];
      //cout<<vis[i][j];
    //}
    //cout <<endl;
  //}
  FOR(i,rows) {
    FOR(j,cols) {
      dists[i][j] = 1000000000;
    }
  }
  dists[0][0] = 0;
  gnode sn;
  sn.x = sn.y = sn.dist = 0;
  queue<gnode> q;
  q.push(sn);
  while (!q.empty()) {
    sn = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = sn.x + dd[d][0];
      int ny = sn.y + dd[d][1];
      if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
        int ndist = sn.dist + g[nx][ny];
        if (ndist < dists[nx][ny]) {
          dists[nx][ny] = ndist;
          gnode n;
          n.x = nx;
          n.y = ny;
          n.dist = ndist;
          q.push(n);
        }
      }
    }
  }
  PRINTL(dists[rows-1][cols-1]);
  return 0;
}

/*

// comma separated
int x;
vector<int> a;
while (cin >> x) {
  a.push_back(x);
  if (cin.peek() == ',') cin.ignore();
}

// line by line
string s;
while (getline(cin, s)) {

}
*/
