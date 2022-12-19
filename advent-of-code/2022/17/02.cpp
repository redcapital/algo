#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <chrono>

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
const int B = 100000;
const ll LIMIT = (ll)1000000000000;

unsigned char gr[B];
unsigned char bits_on[W];
unsigned char bits_off[W];
unsigned char fullb;

struct shape {
	vector<vector<bool>> g;
	int r, c;

	void toggle(int nr, int nc, bool val) {
		FOR(i, g.size()) {
			FOR(j, g[0].size()) {
				if (g[i][j]) {
					if (val) {
						gr[nr + i] |= bits_on[nc + j];
					} else {
						gr[nr + i] &= bits_off[nc + j];
					}
				}
			}
		}
	}

	void place(int nr, int nc) {
		toggle(r, c, false);
		r = nr;
		c = nc;
		toggle(r, c, true);
	}

	bool check(int nr, int nc) {
		if (nr < 0) return false;
		if (nc < 0) return false;
		if (nc + g[0].size() > W) return false;
		if (nr + g.size() > B) return false;
		bool ok = true;
		toggle(r, c, false);
		FOR(i, g.size()) {
			FOR(j,g[0].size()) {
				int ar = nr + i;
				int ac = nc + j;
				if (g[i][j] && (gr[ar] & bits_on[ac])) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		toggle(r, c, true);
		return ok;
	}
};
shape shapes[5];

struct sresult {
	int h, idx;
	ll rocknum;
	ll rocks_done;
	ll ans;
};

sresult simulate(const string& s, ll start, int h, int idx, bool stop) {
  sresult res;
  res.ans = h;
  ll rocknum = start;
  for (; rocknum != LIMIT; rocknum++) {
	  auto& shape = shapes[rocknum % 5];
	  shape.c = 2;
	  shape.r = h - shape.g.size() - 3;
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

	  int hh = h - 7;
	  for (;; hh++) if (gr[hh]) break;
	  h = hh;

	  if (stop && gr[h] == fullb) break;
  }
  res.rocks_done = rocknum - start + 1;
  res.h = h;
  res.idx = idx;
  res.rocknum = rocknum + 1;
  res.ans = res.ans - h;
  return res;
}

// This shit only works on my input and not on sample,
// so it's probably not a generic solution.
// I noticed that as you simulate falling rocks you enter a cycle
// where for every R rocks you build the tower P points high.
// After noticing that you just need to:
// - find at which iteration(s) cycle starts and ends
// - simulate falling until you get to the cycle start
// - do N iterations of the cycle (so answer = answer + N * P)
// - resume the last portion of simulation from where the cycle ends
//
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
  fullb = 0;
  FOR(i, W) {
	  bits_on[i] = (1 << i);
	  fullb |= bits_on[i];
	  bits_off[i] = ~(1 << i);
  }

  string s;
  cin >> s;

  int h = B;
  int idx = 0;
  ll rocknum = 0;
  ll ans = 0;

  vector<sresult> ress;
  while (true) {
	  auto res = simulate(s, rocknum, h, idx, true);
	  h = res.h;
	  idx = res.idx;
	  rocknum = res.rocknum;
	  ans += res.ans;
	  bool found = false;
	  FOR(i, ress.size()) {
		  if (res.idx == ress[i].idx) {
			  found = true;
			  break;
		  }
	  }
	  if (found) break;
	  ress.push_back(res);
  }
  ll cyclerocks = 0;
  ll cycleans = 0;
  // run one more cycle to collect cycle stats
  FOR(i, ress.size()) {
	  ress[i] = simulate(s, rocknum, h, idx, true);
	  h = ress[i].h;
	  idx = ress[i].idx;
	  rocknum = ress[i].rocknum;
	  cycleans += ress[i].ans;
	  cyclerocks += ress[i].rocks_done;
	  ans += ress[i].ans;
  }

  // Run enough cycles that we are almost done

  ll remaining_rocks = LIMIT - rocknum + 1;
  ll numcycles = remaining_rocks / cyclerocks;

  ans += (ll)cycleans * numcycles;
  rocknum += cyclerocks * numcycles;

  // Now run the last simulation until we done
  // Resume simulation from the last item in cycle
  h = ress[1].h;
  idx = ress[1].idx;

  auto res = simulate(s, rocknum, h, idx, false);

  ans += res.ans;

  // 1569054442629 too high
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
