#include <iostream>
#include <string>
#include <map>
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

typedef unsigned long long ull;

ull ans = 0;
const ull BASE = 100000;
const ull DIGIT = BASE * 2;
const ull MAXN = DIGIT * DIGIT * DIGIT;
const ull TN = 4 * MAXN;

map<ull, bool> t;

ull sum(ull v, ull tl, ull tr, ull l, ull r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  ull tm = (tl + tr) / 2;
  return sum (v*2, tl, tm, l, min(r,tm))
    + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (ull v, ull tl, ull tr, ull pos, bool new_val) {
  if (tl == tr)
    t[v] = new_val;
  else {
    ull tm = (tl + tr) / 2;
    if (pos <= tm)
      update (v*2, tl, tm, pos, new_val);
    else
      update (v*2+1, tm+1, tr, pos, new_val);
    t[v] = t[v*2] + t[v*2+1];
  }
}

vector<pair<ull, ull>> ons;

int main() {
  string s;
  int x1, x2, y1, y2, z1, z2;
  //CLEAR(m);
  //int xmi=99999999,xma,ymi,yma,zmi,zma;
  while (getline(cin, s)) {
    bool on=true;
    if (s[1] == 'f') {
      on=false;
      sscanf(s.c_str(), "off x=%d..%d,y=%d..%d,z=%d..%d", &x1, &x2, &y1, &y2, &z1, &z2);
    } else {
      sscanf(s.c_str(), "on x=%d..%d,y=%d..%d,z=%d..%d", &x1, &x2, &y1, &y2, &z1, &z2);
    }
    //cout << x1 << " " << x2 << endl;
    //cout << y1 << " " << y2 << endl;
    //cout << z1 << " " << z2 << endl;
    //break;
    /*
    if (xmi==99999999) {
      xmi=xma=x1;
      ymi=yma=y1;
      zmi=zma=z1;

      xmi=min(xmi, x2);
      ymi=min(ymi, y2);
      zmi=min(zmi, z2);
      xma=max(xma, x2);
      yma=max(yma, y2);
      zma=max(zma, z2);
    } else {
      xmi=min(xmi, x1);
      ymi=min(ymi, y1);
      zmi=min(zmi, z1);
      xma=max(xma, x1);
      yma=max(yma, y1);
      zma=max(zma, z1);

      xmi=min(xmi, x2);
      ymi=min(ymi, y2);
      zmi=min(zmi, z2);
      xma=max(xma, x2);
      yma=max(yma, y2);
      zma=max(zma, z2);
    }
    */
    if (x1 >= -50 && x1 <= 50 && y1 >= -50 && y1 <= 50 && z1 >= -50 && z1 <= 50 && 
        x2 >= -50 && x2 <= 50 && y2 >= -50 && y2 <= 50 && z2 >= -50 && z2 <= 50
       ) {
      x1 += BASE;
      y1 += BASE;
      z1 += BASE;
      x2 += BASE;
      y2 += BASE;
      z2 += BASE;

      ull v1 = x1 * BASE * BASE + y1 * BASE + z1;
      ull v2 = x2 * BASE * BASE + y2 * BASE + z2;


      if (v1 > v2) {
        ull tmp = v2;
        v2 = v1;
        v1 = tmp;
      }

      ons.push_back(make_pair(v1, v2));

      //update(1, 0, N - 1, 

    }
  }

  //cout << xmi << " " << xma << endl;
  //cout << ymi << " " << yma << endl;
  //cout << zmi << " " << zma << endl;
      //FOSE(x,0,100) {
        //FOSE(y,0,100) {
          //FOSE(z,0,100) {
            //if (m[x][y][z]) ans++;
          //}
        //}
      //}

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
