#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>

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
int air[M][M][M];
bool vis[M][M][M];

int ans = 0;

struct cube {
	int x, y, z;

	cube() {}
	cube(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}

	bool within_bounds() {
	  return (x >= 0 && x < M && y >= 0 && y < M && z >= 0 && z < M);
	}

	bool is_occupied() {
		return v[x][y][z];
	}

	void fillout() {
		CLEAR(vis);
		stack<cube> st;
		st.push(*this);
		vis[x][y][z]=true;
		bool closed = true;
		while (!st.empty()) {
			auto c = st.top();
			st.pop();
			FOR(i, 6) {
				  cube next(c.x + ddd[i][0], c.y + ddd[i][1], c.z + ddd[i][2]);
				  if (!next.within_bounds()) {
					  closed = false;
					  continue;
				  }
				  if (next.is_occupied()) continue;
				  if (vis[next.x][next.y][next.z]) continue;
				  vis[next.x][next.y][next.z] = true;
				  st.push(next);
			}
		}
		FOR(a,M) FOR(b,M) FOR(e,M) if (vis[a][b][e]) air[a][b][e] = closed ? 1 : 2;
	}

	bool is_air() {
		if (!air[x][y][z]) {
			fillout();
		}
		return (air[x][y][z] == 1);
	}
};


// Same as part 1, but for every empty cube:
// - fill out empty space starting from that cube, using e.g. DFS
// - if it is enclosed, mark all of that space as air
// - if it goes outside bounds mark it as non-air (coordinates are all within [0,100])
int main() {
  CLEAR(v);
  CLEAR(air);
  string s;
  vector<cube> cubes;
  while (getline(cin, s)) {
	  cube c;
	  sscanf(s.c_str(), "%d,%d,%d", &c.x, &c.y, &c.z);
	  v[c.x][c.y][c.z] = true;
	  cubes.push_back(c);
  }
  for(const auto& c: cubes) {
	  FOR(j,6) {
		  cube n(c.x + ddd[j][0], c.y + ddd[j][1], c.z + ddd[j][2]);
		  if (!n.is_occupied() && !n.is_air()) ans++;
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
