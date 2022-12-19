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
const int ddd[6][3] = {
  { -1,  0, 0 },
  {  1,  0, 0 },
  {  0,  -1, 0 },
  {  0,  1, 0 },
  {  0, 0, -1 },
  {  0, 0, 1 }
};

const int M = 100;
bool v[M][M][M];
vector<int> x,y,z;

int ans = 0;
int main() {
  CLEAR(v);
  string s;
  int sz = 0;
  while (getline(cin, s)) {
	  x.push_back(0);
	  y.push_back(0);
	  z.push_back(0);
	  sscanf(s.c_str(), "%d,%d,%d", &x[sz], &y[sz], &z[sz]);
	  v[x[sz]][y[sz]][z[sz]] = true;
	  sz++;
  }
  FOR(i,sz) {
	  FOR(j,6) {
		  int xx = x[i] + ddd[j][0];
		  int yy = y[i] + ddd[j][1];
		  int zz = z[i] + ddd[j][2];
		  if (!v[xx][yy][zz]) ans++;
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
