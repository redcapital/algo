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


int ans = 0;
int minr, minc, maxr, maxc;
int rows,cols;
short int g[1000][1000];
vector<pair<int,int>> path[500];
const int SC = 500;
const int SR = 0;

int main() {
  string s;
  maxr = minr = SR;
  maxc = minc = SC;
  int pc = 0;
  while (getline(cin, s)) {
	  int p = 0;
	  while (p != string::npos && p < s.size()) {
		  int col, row;
		  int e = s.find(' ', p);
		  if (e == string::npos) {
			  sscanf(s.substr(p).c_str(), "%d,%d", &col, &row);
			  p = e;
		  } else {
			  sscanf(s.substr(p, e - p).c_str(), "%d,%d", &col, &row);
			  p = e + 4;
		  }
		  minr = min(minr, row);
		  maxr = max(maxr, row);
		  minc = min(minc, col);
		  maxc = max(maxc, col);
		  path[pc].push_back(make_pair(col,row));
	  }
	  pc++;
  }
  maxr = maxr + 2;
  minc -= 300;
  maxc += 300;
  rows = maxr - minr + 1;
  cols = maxc - minc + 1;
  CLEAR(g);
  FOR(c, 1000) {
	  g[rows-1][c] = 1;
  }
  FOR(i,pc) {
	  FOR(j, path[i].size() - 1) {
		  int fc = path[i][j].first, fr = path[i][j].second;
		  int tc = path[i][j + 1].first, tr = path[i][j + 1].second;
		  int incc = fc > tc ? -1 : 1;

		  for (int r = fr;;) {
			  for (int c = fc;;) {
				  g[r-minr][c-minc] = 1;
				  if (tc > fc) {
					  c++;
					  if (c > tc) break;
				  } else if (tc < fc) {
					  c--;
					  if (c < tc) break;
				  } else {
					  break;
				  }
			  }
			  if (tr > fr) {
				  r++;
				  if (r > tr) break;
			  } else if (tr < fr) {
				  r--;
				  if (r < tr) break;
			  } else {
				  break;
			  }
		  }
	  }
  }

  while (true) {
	  int r = SR - minr, c = SC - minc;
	  bool done = false;
	  while (true) {
		  if (r + 1 >= rows) {
			  done = true;
			  break;
		  }
		  if (!g[r + 1][c]) {
			  r = r + 1;
			  continue;
		  }
		  if (c - 1 < 0) {
			  done = true;
			  break;
		  }
		  if (!g[r + 1][c - 1]) {
			  r = r + 1;
			  c = c - 1;
			  continue;
		  }
		  if (c + 1 >= cols) {
			  done = true;
			  break;
		  }
		  if (!g[r + 1][c + 1]) {
			  r = r + 1;
			  c = c + 1;
			  continue;
		  }
		  if (g[r][c]) {
			  done = true;
			  break;
		  }
		  g[r][c] = 2;
		  break;
	  }
	  if (done) break;
	  ans++;
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
