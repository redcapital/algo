#include <iostream>
#include <string>
#include <vector>
#include <cstring>
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

int g[60][60];
int rows = 0, cols;
int ans = 0;

void mark(int r, int c) {
  FOS(r1,r-1,r+2) {
    FOS(c1,c-1,c+2) {
      if (r==r1 && c==c1) continue;
      if (r1<0||c1<0||r1>=rows||c1>=cols) continue;
      if (g[r1][c1]>9) continue;
      g[r1][c1]++;
      if (g[r1][c1]>9) {
        mark(r1,c1);
      }
    }
  }
}

int main() {
  string s;
  while (getline(cin, s)) {
    if (!rows) {
      cols = s.size();
    }
    FOR(j,cols) {
      g[rows][j] = s[j] - '0';
    }
    rows++;
  }
  ans=1;
  while (true) {
    FOR(r,rows) {
      FOR(c,cols) {
        if (g[r][c]>9) continue;
        g[r][c]++;
        if (g[r][c]>9) {
          mark(r,c);
        }
      }
    }
    bool all=true;
    FOR(r,rows) {
      FOR(c,cols) {
        if (g[r][c]>9) {
          g[r][c]=0;
        } else {
          all=false;
        }
      }
    }
    if (all) {
      break;
    }
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}

