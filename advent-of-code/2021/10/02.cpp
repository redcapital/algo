#include <iostream>
#include <string>
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

int main() {
  long long ans = 0;
  int c = 0;
  char ch[5000];
  string s;
  vector<long long> ll;
  while (getline(cin, s)) {
    bool ok = true;
    ans = 0;
    c = 0;
    FOR(i, s.size()) {
      switch (s[i]) {
        case '[':
        case '(':
        case '{':
        case '<':
          ch[c++] = s[i];
          break;
        case ')':
          if (ch[c-1] != '(') {
            ok=false;
          }
          c--;
          break;
        case ']':
          if (ch[c-1] != '[') {
            ok=false;
          }
          c--;
          break;
        case '}':
          if (ch[c-1] != '{') {
            ok=false;
          }
          c--;
          break;
        case '>':
          if (ch[c-1] != '<') {
            ok=false;
          }
          c--;
          break;
      }
      if (!ok) break;
    }
    if (ok) {
      for (int i = c - 1; i >= 0; i--) {
        ans = ans * 5;
        switch (ch[i]) {
          case '(': ans += 1; break;
          case '[': ans += 2; break;
          case '{': ans += 3; break;
          case '<': ans += 4; break;
        }
      }
      ll.push_back(ans);
    }
  }
  sort(ALL(ll));
  PRINTL(ll[ll.size() / 2]);

  return 0;
}
