#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<s<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};

map<string,int> idx;
string vs[100];
int cnt=0;
int start,endv;
vector<int> g[100];
int path[100], pc=0;
bool small[100];
bool vis[100];
int ans=0;

int add(const string& s) {
  auto it=idx.find(s);
  if (it==idx.end()) {
    idx[s]=cnt;
    if (s[0] >= 'a' && s[0] <= 'z') {
      small[cnt]=true;
    }
    return cnt++;
  }
  return idx[s];
}

void connect(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

void rec(int v) {
  if (v==endv) {
    ans++;
    return;
  }
  FOR(i,g[v].size()) {
    int vv=g[v][i];
    if (vis[vv] && small[vv]) continue;
    vis[vv]=true;
    rec(vv);
    vis[vv]=false;
  }
}

int main() {
  string s;
  CLEAR(small);
  while (getline(cin, s)) {
    string v1, v2;
    int p = s.find('-');
    v1 = s.substr(0, p);
    v2 = s.substr(p + 1);
    int a = add(v1);
    int b = add(v2);
    connect(a, b);
    //cout << v1 << " " << v2 << endl;
  }
  start=idx["start"];
  endv=idx["end"];
  CLEAR(vis);
  vis[start]=true;
  rec(start);
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
