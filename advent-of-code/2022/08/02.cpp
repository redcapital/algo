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
int main() {
  string s;
  vector<string> g;
  while (getline(cin, s)) {
	  g.push_back(s);
  }
  int rows = g.size(), cols = g[0].size();
  for (int i = 0; i < rows; i++) {
	  for (int j = 0; j < cols; j++) {
		  int score = 1;
		  for (int d = 0; d < 4; d++) {
			  int k = 1;
			  for (;; k++) {
				  int r = i + dd[d][0] * k;
				  int c = j + dd[d][1] * k;
				  if (r < 0 || r == rows || c < 0 || c == cols) {
					  k--;
					  break;
				  }
				  if (g[r][c] >= g[i][j]) {
					  break;
				  }
			  }
			  score *= k;
		  }
		  ans = max(ans,score);
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
