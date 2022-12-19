#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <list>

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

const int ORE = 0;
const int CLAY = 1;
const int OBS = 2;
const int GEO = 3;

const int TIME = 32;

struct blueprint {
	int id;
	int costs[4][3];

	void reset() {
		CLEAR(costs);
	}
} bp;

struct sstate {
	int robots[4];
	int resources[4];
	int elapsed;

	void reset() {
		elapsed = 0;
		FOR(i, 4) robots[i] = resources[i] = 0;
		robots[ORE] = 1;
	}

	void passtime(int amount) {
		int actual = min(amount, TIME - elapsed);
		FOR(i, 4) resources[i] += robots[i] * actual;
		elapsed += actual;
	}

	void buildrobot(int robot) {
		FOR (i, 3) resources[i] -= bp.costs[robot][i];
		passtime(1);
		robots[robot]++;
	}
};

int ans = 0;

int dfs(const sstate& st) {
	if (st.elapsed == TIME) return st.resources[GEO];

	int res = 0;

	FOR(i, 4) {
		int topass = 0;
		bool canbuild = true;
		FOR(j, 3) {
			int need = bp.costs[i][j] - st.resources[j];
			if (need > 0) {
				if (st.robots[j]) {
					topass = max(topass, need / st.robots[j] + ((need%st.robots[j])?1:0));
				} else {
					canbuild = false;
					break;
				}
			}
		}
		if (canbuild) {
			sstate n = st;
			if (topass) n.passtime(topass);
			if (n.elapsed < TIME) {
				n.buildrobot(i);
			}
			res = max(res, dfs(n));
		}
	}

	sstate n = st;
	n.passtime(TIME - n.elapsed);
	res = max(res, dfs(n));
	return res;
}

int main() {
  string s;
  int cnt = 0;
  ans = 1;
  while (getline(cin, s)) {
	  bp.reset();
	  sscanf(
			  s.c_str(),
			  "Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.",
			  &bp.id,
			  &bp.costs[ORE][ORE],
			  &bp.costs[CLAY][ORE],
			  &bp.costs[OBS][ORE], &bp.costs[OBS][CLAY],
			  &bp.costs[GEO][ORE], &bp.costs[GEO][OBS]
		);
	  sstate st;
	  st.reset();
	  int simmax = dfs(st);
	  cout << simmax << endl;
	  ans *= simmax;
	  cnt++;
	  if (cnt == 3) break;
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
