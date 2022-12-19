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


int ans = 100000000;
vector<int> g[200];
int scor[200][200];
int rows=0,cols=0;
int er, ec;

void gogo(int sr, int sc) {
  queue<pair<int,int>> q;
  FOR(i,rows) FOR(j,cols) scor[i][j] = 100000000;
  scor[sr][sc] = 0;
  q.push(make_pair(sr, sc));

  while (!q.empty()) {
	  auto p = q.front();
	  q.pop();
	  int cr = p.first, cc = p.second;
	  int nexts = scor[cr][cc] + 1;
	  FOR(d,4) {
		  int r = cr + dd[d][0];
		  int c = cc + dd[d][1];
		  if (r >= 0 && r < rows && c >= 0 && c < cols) {
			  if (
				  g[r][c] - g[cr][cc] <= 1 &&
				  scor[r][c] > nexts
			     ) {
				  q.push(make_pair(r, c));
				  scor[r][c] = nexts;
			  }
		  }
	  }
  }
}

int main() {
  string s;
  rows=cols=0;
  while (getline(cin, s)) {
	  if (!cols) {
		  cols = s.size();
	  }
	  FOR(i,cols) {
		  if (s[i] == 'S') {
			  g[rows].push_back(0);
		  } else if (s[i] == 'E') {
			  g[rows].push_back(26);
			  er = rows;
			  ec = i;
		  } else {
			  g[rows].push_back(s[i]-'a');
		  }
	  }
	  rows++;
  }


  FOR(i,rows) {
	  FOR(j,cols) {
		  if (g[i][j] == 0) {
			  gogo(i,j);
			  ans = min(ans, scor[er][ec]);
		  }
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
