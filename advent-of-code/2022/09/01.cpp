#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
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


int ans = 0;
const int BASE = 10000;
int main() {
  string s;
  int hr = 0, hc = 0, tr = 0, tc = 0;
  set<int> vis;
  vis.insert(0);
  while (getline(cin, s)) {
	  char dir;
	  int steps, nr, nc;
	  sscanf(s.c_str(), "%c %d", &dir, &steps);
	  while (steps--) {
		  switch (dir) {
			  case 'R':
				  nr = hr;
				  nc = hc + 1;
				  break;
			  case 'U':
				  nr = hr - 1;
				  nc = hc;
				  break;
			  case 'L':
				  nr = hr;
				  nc = hc - 1;
				  break;
			  case 'D':
				  nr = hr + 1;
				  nc = hc;
				  break;
		  }
		  int dist = abs(nr-tr) + abs(nc-tc);
		  if (nr == tr || nc == tc) {
			  if (dist > 1) {
				  tr = hr;
				  tc = hc;
			  }
		  } else {
			  if (dist > 2) {
				  tr = hr;
				  tc = hc;
			  }
		  }
		  hr = nr;
		  hc = nc;
		  vis.insert(tr * BASE + tc);
	  }
  }
  PRINTL(vis.size());
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
