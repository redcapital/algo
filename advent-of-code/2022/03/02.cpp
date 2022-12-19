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
	if (g.size() == 3) {
		for (int p = 1; p <= 26; p++) {
			char c = ('a' + (p - 1));
			if (g[0].find(c) != string::npos && g[1].find(c) != string::npos && g[2].find(c) != string::npos) {
				ans += p;
				break;
			}
			c = ('A' + (p - 1));
			if (g[0].find(c) != string::npos && g[1].find(c) != string::npos && g[2].find(c) != string::npos) {
				ans += 26 + p;
				break;
			}
		}
		g.clear();
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
