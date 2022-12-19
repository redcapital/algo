#include <iostream>
#include <string>
#include <sstream>
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

int ans = 0;

// x y
bool g[5000][5000];
vector<int> fn;
vector<bool> ft;
int mx = 0, my = 0;

void dofoldx(int f) {
  //vertical
  cerr<<"folding x" << f << endl;
  for (int x=f+1; x<=mx; x++) {
    FOR(y,my+1) {
      if (g[x][y]) {
        g[f-(x-f)][y]=true;
      }
    }
  }
  mx=f-1;
}

void dofoldy(int f) {
  //horiz
  cerr<<"folding y" << f << endl;
  for (int y=f+1; y<=my; y++) {
    FOR(x,mx+1) {
      if (g[x][y]) {
        g[x][f-(y-f)]=true;
      }
    }
  }
  my=f-1;
}

int main() {
  // line by line
  string s;
  CLEAR(g);
  while (getline(cin, s)) {
    if (s.size() == 0) continue;
    if (s[0] == 'f') {
      string t1;
      char c, ftt;
      stringstream ss(s);
      int fold;
      ss >> t1 >> t1 >> ftt >> c >> fold;
      fn.push_back(fold);
      ft.push_back(ftt == 'x');
      //cout << "fold " << fold << endl;
    } else {
      int a, b;
      char c;
      stringstream ss(s);
      ss >> a >> c >> b;
      mx = max(mx, a);
      my = max(my, b);
      g[a][b] = true;
    }
  }

  FOR(i,ft.size()) {
    if (ft[i]) {
      dofoldx(fn[i]);
    } else {
      dofoldy(fn[i]);
    }
   break;
  }

  FOR(x,mx+1) {
    FOR(y,my+1) {
      if (g[x][y]) ans++;
    }
  }

  PRINTL(ans);
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
