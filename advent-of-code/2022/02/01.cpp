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
  map<char,int> shape;
  shape['X']=1;
  shape['Y']=2;
  shape['Z']=3;
  shape['A']=1;
  shape['B']=2;
  shape['C']=3;
  while (getline(cin, s)) {
	int t1=shape[s[0]],t2=shape[s[2]];
	ans+=t2;
	if (t1==t2) {
		ans += 3;
	} else {
		if (t1+1==t2 || (t1==3 && t2==1)){ 
			ans += 6;
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
