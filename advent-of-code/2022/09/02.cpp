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


const int BASE = 10000;
const int HEAD = 9;
int r[10], c[10];

pair<int,int> getclose(int ar, int ac, int br, int bc) {
	if (ar != br) {
		if (ar < br) ar++; else ar--;
	}
	if (ac != bc) {
		if (ac < bc) ac++; else ac--;
	}
	return make_pair(ar, ac);
}

pair<int,int> dragtail(int tr, int tc, int nr, int nc) {
	int dist = abs(nr-tr) + abs(nc-tc);
	if (nr == tr || nc == tc) {
		if (dist > 1) {
			return getclose(tr, tc, nr, nc);
		}
		return make_pair(tr, tc);
	}
	if (dist > 2) {
		return getclose(tr, tc, nr, nc);
	}
	return make_pair(tr, tc);
}

void moveknot(int idx, int nr, int nc) {
	if (r[idx] == nr && c[idx] == nc) {
		return;
	}
	r[idx] = nr;
	c[idx] = nc;
	if (idx > 0) {
		auto p = dragtail(r[idx - 1], c[idx - 1], nr, nc);
		moveknot(idx - 1, p.first, p.second);
	}
}

int main() {
  string s;
  set<int> vis;
  vis.insert(0);
  FOR(i,10) r[i]=c[i]=0;
  while (getline(cin, s)) {
	  char dir;
	  int steps, nr, nc;
	  sscanf(s.c_str(), "%c %d", &dir, &steps);
	  while (steps--) {
		  switch (dir) {
			  case 'R':
				  nr = r[HEAD];
				  nc = c[HEAD] + 1;
				  break;
			  case 'U':
				  nr = r[HEAD] - 1;
				  nc = c[HEAD];
				  break;
			  case 'L':
				  nr = r[HEAD];
				  nc = c[HEAD] - 1;
				  break;
			  case 'D':
				  nr = r[HEAD] + 1;
				  nc = c[HEAD];
				  break;
		  }
		  moveknot(HEAD, nr, nc);
		  vis.insert(r[0] * BASE + c[0]);
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
