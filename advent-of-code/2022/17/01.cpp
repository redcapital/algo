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


const int W = 7;
const int B = 50000;

int gr[B][W];
int h;

struct shape {
	vector<vector<bool>> g;
	int r, c, id;

	void toggle(int nr, int nc, int val) {
		FOR(i, g.size()) {
			FOR(j, g[0].size()) {
				if (g[i][j]) {
					gr[nr - g.size() + 1 + i][nc + j] = val;
				}
			}
		}
	}

	void place(int nr, int nc) {
		toggle(r, c, 0);
		r = nr;
		c = nc;
		toggle(r, c, id);
	}

	bool check(int nr, int nc) {
		if (nr < 0 || nr >= B) return false;
		if (nc < 0) return false;
		if (nc + g[0].size() > W) return false;
		FOR(i, g.size()) {
			FOR(j,g[0].size()) {
				int ar = nr - g.size() + 1 + i;
				int ac = nc + j;
				if (g[i][j] && gr[ar][ac] && gr[ar][ac] != id) {
					return false;
				}
			}
		}
		return true;
	}
};
shape shapes[5];

int ans = 0;
int main() {
  CLEAR(gr);
  shapes[0].g = {
	  { true, true, true, true }
  };
  shapes[1].g = {
	  { false, true, false },
	  { true, true, true },
	  { false, true, false }
  };
  shapes[2].g = {
	  { false, false, true },
	  { false, false, true },
	  { true, true, true }
  };
  shapes[3].g = {
	  { true },
	  { true },
	  { true },
	  { true }
  };
  shapes[4].g = {
	  { true, true },
	  { true, true }
  };


  string s;
  cin >> s;

  h = B;
  int idx = 0;
  FOR(rocknum, 2022) {
	  auto& shape = shapes[rocknum % 5];
	  shape.id = rocknum + 1;
	  shape.c = 2;
	  shape.r = h - 4;
	  shape.place(shape.r, shape.c);

	  while (true) {
		  if (s[idx] == '<') {
			  if (shape.check(shape.r, shape.c - 1)) {
				  shape.place(shape.r, shape.c - 1);
			  }
		  } else {
			  if (shape.check(shape.r, shape.c + 1)) {
				  shape.place(shape.r, shape.c + 1);
			  }
		  }
		  idx++;
		  if (idx == s.size()) idx = 0;
		  bool ok = shape.check(shape.r + 1, shape.c);
		  if (ok) {
			  shape.place(shape.r + 1, shape.c);
		  } else {
			  break;
		  }
	  }

	  for (int hh = h - 4; ; hh++) {
		  bool ok = false;
		  FOR(j, W) {
			  if (gr[hh][j]) {
				  ok = true;
				  h = hh;
				  break;
			  }
		  }
		  if (ok) break;
	  }
  }

  PRINTL(B - h);
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
