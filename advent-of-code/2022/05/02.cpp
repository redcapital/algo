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
  vector<string> g;
  string s;
  string stacks[20];
  int sn;
  while (getline(cin, s)) {
	  if (s.empty()) {
		  int last = g.size() - 1;
		  for (int i = 0; i < g[last].size(); i++) {
			  if (g[last][i] != ' ') {
				  sn = g[last][i] - '1';
				  for (int j = last - 1; j >= 0; j--) {
					  if (g[j].size() > i && g[j][i] != ' ') {
						  stacks[sn] += g[j][i];
					  }
				  }
			  }
		  }
		  break;
	  } else {
		  g.push_back(s);
	  }
  }
  while (getline(cin, s)) {
	  int amount, from, to;
	  sscanf(s.c_str(), "move %d from %d to %d", &amount, &from, &to);
	  from--;to--;
	  int start=stacks[from].size()-amount;
	  string slice(stacks[from].substr(start, amount));
	  stacks[to]+=slice;
	  stacks[from].erase(start,amount);
  }
  for (int i = 0; i <= sn; i++) {
	  cout << stacks[i][stacks[i].size()-1];
  }
  cout << endl;
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
