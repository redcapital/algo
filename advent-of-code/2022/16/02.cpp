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


map<string, int> ids;
int rates[64];
vector<int> dest[64];
int bits[64];
int nextid;
int nextbit;
int costs[64][64];
bool p1[64];

const int LIMIT = 26;
int res;

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

int runbfs(bool isp1) {
  int ans = 0;
  queue<st> q;
  q.push(st(0, getid("AA"), 0, 0, 0));

  while (!q.empty()) {
	  auto cur = q.front();
	  q.pop();
	  int remaining = LIMIT - min(cur.minute, LIMIT);
	  int pans = cur.score + cur.rate * remaining;
	  if (pans > ans) {
		  ans = pans;
	  }
	  if (cur.minute >= LIMIT) {
		  continue;
	  }
	  FOR(dd, nextid) {
		  // myself
		  if (cur.v == dd) continue;
		  // wrong partition
		  if (isp1 != p1[dd]) continue;
		  // bad valve
		  if (!rates[dd]) continue;
		  // cant reach
		  if (!costs[cur.v][dd]) continue;
		  // already open
		  if (isopen(cur.mask, dd)) continue;
		  int tmin = cur.minute + costs[cur.v][dd] + 1;
		  int pumped = min(LIMIT, tmin) - cur.minute;
		  // all good
		  q.push(st(tmin, dd, opened(cur.mask, dd), cur.rate + rates[dd], cur.score + cur.rate * pumped));
	  }
  }
  return ans;
}

void partition(int len, int idx = 0) {
	if (len == 0) {
		res = max(res, runbfs(false) + runbfs(true));
		return;
	}
	FOS(i,idx,64) {
		if (!rates[i]) continue;
		p1[i] = true;
		partition(len - 1, i + 1);
		p1[i] = false;
	}
}

// We have to partition all good valves in two sets: each set will be visited separately.
// For each set we run same BFS algo from part1 to calculate total score.
//
// i.e. the algo will be:
// - for every possible partitioning:
//     answer = max(answer, BFS(partition1) + BFS(partition2))
//
// In how many ways we can parition the set?
// If N = count of good valves, then we have
// num of partitions of length 1 = C(N,1) where C(n,m) is binomial coefficient from combinatorics
// of length 2 = C(N, 2)
// and so on up to length/2...
// With N being small, the total number of partitionings is not that large
int main() {
  nextid = 0;
  nextbit = 0;
  CLEAR(costs);
  CLEAR(rates);
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

  res = 0;
  FOSE(len, 1, nextbit / 2) {
	  CLEAR(p1);
	  partition(len, 0);
  }

  PRINTL(res);
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
