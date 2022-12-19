#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

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


int ans = 0;
const int BASE = 5000000;
const int Y = 2000000;
bool m[10000000];

int main() {
  string s;
  CLEAR(m);
  vector<int> sx, sy, bx, by;
  int sz = 0;
  while (getline(cin, s)) {
	  sx.push_back(0);
	  sy.push_back(0);
	  bx.push_back(0);
	  by.push_back(0);
	  sscanf(s.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &sx[sz], &sy[sz], &bx[sz], &by[sz]);
	  sz++;
  }
  FOR(i,sz) {
	  int dist = abs(sx[i]-bx[i]) + abs(sy[i]-by[i]);
	  int rem = abs(sy[i] - Y);
	  if (rem < dist) {
		  for (int c = 0; c <= dist - rem; c++) {
			  m[sx[i] - c + BASE] = true;
			  m[sx[i] + c + BASE] = true;
		  }
	  }
  }
  FOR(i,sz) {
	  if (by[i] == Y) {
		  m[bx[i] + BASE] = false;
	  }
  }
  FOR(i, 10000000) {
	  if (m[i]) ans++;
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
