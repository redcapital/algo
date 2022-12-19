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
vector<int> g[200];
vector<int> scor[200];
int rows=0,cols=0;
int sr, sc, er, ec;


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
			  scor[rows].push_back(0);
			  sr = rows;
			  sc = i;
		  } else if (s[i] == 'E') {
			  g[rows].push_back(26);
			  scor[rows].push_back(100000000);
			  er = rows;
			  ec = i;
		  } else {
			  g[rows].push_back(s[i]-'a');
			  scor[rows].push_back(100000000);
		  }
	  }
	  rows++;
  }

  queue<pair<int,int>> q;
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
				  //g[r][c] >= g[cr][cc] && 
				  g[r][c] - g[cr][cc] <= 1 &&
				  scor[r][c] > nexts
			     ) {
				  q.push(make_pair(r, c));
				  scor[r][c] = nexts;
			  }
		  }
	  }
  }

  PRINTL(scor[er][ec]);
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
