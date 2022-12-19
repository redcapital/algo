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

bool img0[1000][1000];
bool img1[1000][1000];
bool en[512];
int rows=0, cols=0;
int sr,sc;
int rs, cs;

const int padding = 60;
const int np = 40;

void enhance(int s, int t) {
  FOS(r,sr,) {
    FOR(c,cols) {
      int num=0, bit=(1<<8);
      FOS(i,-1,2) {
        FOS(j,-1,2) {
          int nr=r+i,nc=j+c;
          bool v=(s==0) ? img0[nr][nc] : img1[nr][nc];
          if (nr>=0 && nr < rows && nc >=0 && nc < cols && v) {
            num |= bit;
          }
          bit >>= 1;
        }
      }
      if (r <= np || c <= np || (rows-r<=np) || (cols-c<=np)) {
        if (t==0) img0[r][c] = false; else img1[r][c] = false;
        continue;
      }
      //if (!r || !c || r==rows-1 || c==cols-1) num=0;
      if (t==0) img0[r][c] = en[num]; else img1[r][c] = en[num];
    }
  }
}

void printi(int s) {
  FOR(r,rows) {
    FOR(c,cols) {
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
      cols=s.size()+padding*2;
    }
    FOR(i,padding) img0[rows][i]=false;
    FOR(i,s.size()) {
      img0[rows][i+padding]=(s[i]=='#');
    }
    FOR(i,padding) img0[rows][i+padding+s.size()]=false;
    rows++;
  }
  rows += padding;

  cout << rows << "x " << cols <<endl;

  int ss=0, t=1;
  sr=padding,sc=padding;
  FOR(i,10) {
    if (t==0) CLEAR(img0); else CLEAR(img1);
    enhance(ss, t);
    printi(t);
    ss=!ss;
    t=!t;
  }

  int ans=0;
  FOR(r,rows) {
    FOR(c,cols) {
      bool v = (ss==0) ?img0[r][c] :img1[r][c];
      if (r && c && v) ans++;
    }
  }

  // 25137
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
