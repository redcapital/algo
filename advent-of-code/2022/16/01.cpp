#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <queue>

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
map<string, int> ids;
int rates[64];
vector<int> dest[64];
int bits[64];
int nextid;
int nextbit;
int costs[64][64];

int getid(const string& name) {
	auto iter = ids.find(name);
	if (iter != ids.end()) {
		return iter->second;
	}
	return ids[name] = nextid++;
}

bool isopen(int mask, int v) {
	return mask & bits[v];
}

int opened(int mask, int v) {
	return mask | bits[v];
}

struct st {
	int minute, v, mask, rate, score;
	st(int minn,int _v,int m,int r,int s) : minute(minn), v(_v), mask(m), rate(r), score(s) {}
};

void findcosts(int v) {
	queue<pair<int,int>> q;
	q.push(make_pair(v, 0));
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto vv: dest[p.first]) {
			if (vv == v) continue;
			int vcost = p.second + 1;
			if (!costs[v][vv] || costs[v][vv] > vcost) {
				costs[v][vv] = vcost;
				q.push(make_pair(vv, vcost));
			}
		}
	}
}

// We need to find optimal path that visits all possible good valves in time limit (good=has non-zero flow rate)
// - find shortest distances between every pair of valve
// - run BFS but only visit every good valve
// - in BFS state store: the valve we're currently at, time to reach it, total score, total rate
//
// Keep in mind we might finish visiting all valves and still have some time left, so add the (remaining time * total rate) to total score
int main() {
  nextid = 0;
  nextbit = 0;
  CLEAR(costs);
  string s;
  while (getline(cin, s)) {
	  char v[4];
	  int r;
	  sscanf(s.c_str(), "Valve %s has flow rate=%d", &v, &r);
	  int source = getid(string(v));
	  rates[source] = r;
	  if (r) {
		  bits[source] = (1 << nextbit);
		  nextbit++;
	  }

	  int p = s.find(',');
	  if (p == string::npos) {
		  string name(s.substr(s.size() - 2));
		  dest[source].push_back(getid(name));
	  } else {
		  p -= 2;
		  while (p < s.size() && p != string::npos) {
			  int cm = s.find(',', p);
			  string name;
			  if (cm == string::npos) {
				  name = s.substr(p);
				  p = cm;
			  } else {
				  name = s.substr(p, cm - p);
				  p = cm + 2;
			  }
			  dest[source].push_back(getid(name));
		  }
	  }
  }


  FOR(i, nextid) findcosts(i);

  queue<st> q;
  q.push(st(0, getid("AA"), 0, 0, 0));
  while (!q.empty()) {
	  auto cur = q.front();
	  q.pop();
	  int remaining = 30 - min(cur.minute, 30);
	  ans = max(ans, cur.score + cur.rate * remaining);
	  if (cur.minute >= 30) {
		  continue;
	  }
	  FOR(dd, nextid) {
		  // myself
		  if (cur.v == dd) continue;
		  // bad valve
		  if (!rates[dd]) continue;
		  // cant reach
		  if (!costs[cur.v][dd]) continue;
		  // already open
		  if (isopen(cur.mask, dd)) continue;
		  int tmin = cur.minute + costs[cur.v][dd] + 1;
		  int pumped = min(30, tmin) - cur.minute;
		  q.push(st(tmin, dd, opened(cur.mask, dd), cur.rate + rates[dd], cur.score + cur.rate * pumped));
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
