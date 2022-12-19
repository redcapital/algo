#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<(s)<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

typedef long long ll;
typedef unsigned long long ull;

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};


const int N = 150;
char m[N][N], t[N][N];
int ans = 0, rows=0, cols=0;

bool move() {
  bool res=false;
  CLEAR(t);
  FOR(i,rows) {
    FOR(j,cols) {
      int nc=(j+1)%cols;
      if (m[i][j]=='>' && !m[i][nc]) {
        t[i][nc] = '>';
        //cout << " can move hor " << i << " " << j << " " << nc << endl;
        //cout << " and now " << t[i][nc] << " " << t[i][j] << endl;
        res=true;
      } else {
        if (!t[i][j]) t[i][j] = m[i][j];
        //cout << " cannot move hor " << i << " " << j << " "  << endl;
        //cout << " and now " <<  t[i][j] << endl;
      }
    }
  }

  //cout << "tmp " << endl;
    //FOR(i,rows) {
      //FOR(j,cols) {
        //if (t[i][j]) cout << t[i][j]; else cout << '.';
      //}
        //cout<<endl;
    //}

  CLEAR(m);
  FOR(i,rows) {
    FOR(j,cols) {
      int nr=(i+1)%rows;
      if (t[i][j]=='v' && !t[nr][j]) {
        m[nr][j] = 'v';
        res=true;
      } else {
        if (!m[i][j]) m[i][j] = t[i][j];
      }
    }
  }
  return res;
}

int main() {
  string s;
  CLEAR(m);
  while (getline(cin, s)) {
    if (!cols) {
      cols=s.size();
    }
    FOR(i,cols) {
      m[rows][i]=s[i]=='.' ? 0 : s[i];
    }
    rows++;
  }
    FOR(i,rows) {
      FOR(j,cols) {
        if (m[i][j]) cout << m[i][j]; else cout << '.';
      }
        cout<<endl;
    }
  while (true) {
    if (!move()) break;
    ans++;
    //cout << "After " << ans << " steps:" << endl;

    //FOR(i,rows) {
      //FOR(j,cols) {
        //if (m[i][j]) cout << m[i][j]; else cout << '.';
      //}
        //cout<<endl;
    //}
  }
  PRINTL(ans+1);
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
