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
  int x = 1;
  int cycles = 0;
  map<int, int> xx;
  while (getline(cin, s)) {
	  if (s[0] == 'a') {
		  int num = atoi(s.substr(5).c_str());
		  x += num;
		  cycles += 2;
	  } else {
		  cycles += 1;
	  }
	  xx[cycles] = x;
  }
  for (int r = 0; r < 6; r++) {
	  string d;
	  for (int c = 0; c < 40; c++) {
		  int cycle = r * 40 + c + 1;
		  auto it = xx.lower_bound(cycle);
		  x = 1;
		  if (it != xx.begin()) {
			  it--;
			  x = it->second;
		  }
		  if (c >= x - 1 && c <= x + 1) {
			  d += '#';
		  } else {
			  d += '.';
		  }
	  }
	  cout << d << endl;
  }
  //PRINTL(ans);
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
