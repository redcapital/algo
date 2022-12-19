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
  int ans = 0;
  int c = 0;
  char ch[5000];
  string s;
  while (getline(cin, s)) {
    char type;
    FOR(i, s.size()) {
      bool ok=true;
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
            ans += 3;
          }
          c--;
          break;
        case ']':
          if (ch[c-1] != '[') {
            ok=false;
            ans += 57;
          }
          c--;
          break;
        case '}':
          if (ch[c-1] != '{') {
            ok=false;
            ans += 1197;
          }
          c--;
          break;
        case '>':
          if (ch[c-1] != '<') {
            ok=false;
            ans += 25137;
          }
          c--;
          break;
      }
      if (!ok) break;
    }
  }

  PRINTL(ans);
  return 0;
}
