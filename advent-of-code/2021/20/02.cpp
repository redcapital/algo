#include <iostream>
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

bool img0[1500][1500];
bool img1[1500][1500];
bool en[512];
int rs=500, cs=500;
int rows=0, cols=0;

bool defv = false;

void calcp(int s, int t, int r, int c) {
  int num=0, bit=(1<<8);
  FOS(i,-1,2) {
    FOS(j,-1,2) {
      int nr=r+i,nc=j+c;
      bool v=(s==0) ? img0[nr][nc] : img1[nr][nc];
      if (nr < rs || nr >= rs+rows || nc < cs || nc >= cs + cols) {
        v = defv;
      }
      if (v) {
        num |= bit;
      }
      bit >>= 1;
    }
  }
  if (t==0) img0[r][c] = en[num]; else img1[r][c] = en[num];
}

void enhance(int s, int t) {
  FOS(r,rs,rs+rows) {
    FOS(c,cs,cs+cols) {
      FOS(i,r-1,r+2) {
        FOS(j,c-1,c+2) {
          calcp(s, t, i, j);
        }
      }
    }
  }
  rs -= 1;
  cs -= 1;
  rows += 2;
  cols += 2;
  defv = !defv;
}

void printi(int s) {
  FOS(r,rs,rs+rows) {
    FOS(c,cs,cs+cols) {
      bool v = (s==0)?img0[r][c]:img1[r][c];
      cout << (v ? '#' : '.');
    }
    cout<<endl;
  }
  cout << endl;
}

int main() {
  string s;
  bool f=true;
  CLEAR(img0);
  while (getline(cin, s)) {
    if (!s.size()) continue;
    if (f) {
      FOR(i,512) en[i]=(s[i]=='#');
      f=false;
      continue;
    }
    if (!cols) {
      cols=s.size();
    }
    FOR(i,s.size()) {
      img0[rs+rows][cs+i]=(s[i]=='#');
    }
    rows++;
  }

  cout << rows << "x " << cols <<endl;

    printi(0);
  int ss=0, t=1;
  FOR(i,50) {
    if (t==0) CLEAR(img0); else CLEAR(img1);
    enhance(ss, t);
    //printi(t);
    ss=!ss;
    t=!t;
  }

  int ans=0;
  FOS(r,rs,rs+rows) {
    FOS(c,cs,cs+cols) {
      bool v = (ss==0) ?img0[r][c] :img1[r][c];
      if (v) ans++;
    }
  }

  // 25137
  // 19418 too high
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
