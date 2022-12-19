#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
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

typedef long long ll;
typedef unsigned long long ull;


int main() {
  int x1, x2, y1, y2, ans = 0;
  scanf("target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1, &y2);
  /*
  int vx = 5, vy = 7;
      int ix = 0, iy = 0, vxt = vx, vyt = vy;
      bool ok = false;
      for (int i = 0; i < 1000; i++) {
        ix += vxt;
        iy += vyt;
        if (vxt > 0) vxt--; else if (vxt < 0) vxt++;
        vyt--;
        printf("%d,%d\n", ix, iy);
        if (ix >= x1 && ix <= x2 && iy >= y1 && iy <= y2) {
          ok = true;
          break;
        }
      }
      if (ok) {
        printf("found %d,%d\n", vx, vy);
        ans++;
      }
      */
  for (int vx = -1000; vx < 1000; vx++) {
    for (int vy = -1000; vy < 1000; vy++) {
      int ix = 0, iy = 0, vxt = vx, vyt = vy;
      bool ok = false;
      for (int i = 0; i < 1000; i++) {
        ix += vxt;
        iy += vyt;
        if (vxt > 0) vxt--; else if (vxt < 0) vxt++;
        vyt--;
        if (ix >= x1 && ix <= x2 && iy >= y1 && iy <= y2) {
          ok = true;
          break;
        }
      }
      if (ok) {
        printf("%d,%d\n", vx, vy);
        ans++;
      }
    }
  }
  PRINTL(ans);
  //PRINTL(x2);
  //PRINTL(y1);
  //PRINTL(y2);
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
