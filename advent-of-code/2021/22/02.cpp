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

struct Cube {
  int x1, x2, y1, y2, z1, z2;
  Cube() {};
  Cube(int _x1, int _x2, int _y1, int _y2, int _z1, int _z2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2), z1(_z1), z2(_z2) {};

  ull vol() {
    ull x = x2 - x1 + 1, y = y2 - y1 + 1, z = z2 - z1 + 1;
    if (x <= 0 || y <= 0 || z <= 0) return 0;
    return x * y * z;
  }
};

vector<Cube> cubes;

vector<Cube> split_cube(const Cube& e, const Cube& c) {
  vector<Cube> res;

  if (c.x2 < e.x1 || c.x1 > e.x2 ||
      c.y2 < e.y1 || c.y1 > e.y2 ||
      c.z2 < e.z1 || c.z1 > e.z2) {
    res.push_back(e);
    //cout << "here return";
    return res;
  }

  if (c.x1 > e.x1) 
    res.push_back(Cube(e.x1, c.x1 - 1, e.y1, e.y2, e.z1, e.z2));
  if (c.x2 < e.x2) 
    res.push_back(Cube(c.x2 + 1, e.x2, e.y1, e.y2, e.z1, e.z2));
  if (c.y1 > e.y1) 
    res.push_back(Cube(max(e.x1, c.x1), min(e.x2, c.x2), e.y1, c.y1 - 1, e.z1, e.z2));
  if (c.y2 < e.y2) 
    res.push_back(Cube(max(e.x1, c.x1), min(e.x2, c.x2), c.y2 + 1, e.y2, e.z1, e.z2));
  if (c.z1 > e.z1) 
    res.push_back(Cube(max(e.x1, c.x1), min(e.x2, c.x2), max(e.y1, c.y1), min(e.y2, c.y2), e.z1, c.z1 - 1));
  if (c.z2 < e.z2) 
    res.push_back(Cube(max(e.x1, c.x1), min(e.x2, c.x2), max(e.y1, c.y1), min(e.y2, c.y2), c.z2 + 1, e.z2));

  return res;

}

void add(const Cube& c, bool on) {
  vector<Cube> res;
  for (const auto& e: cubes) {
    for (const auto& x: split_cube(e, c)) {
      res.push_back(x);
    }
  }
  if (on) {
    res.push_back(c);
  }
  cubes = res;
}

int main() {
  string s;
  while (getline(cin, s)) {
    Cube c;
    bool on=true;
    if (s[1] == 'f') {
      on=false;
      sscanf(s.c_str(), "off x=%d..%d,y=%d..%d,z=%d..%d", &c.x1, &c.x2, &c.y1, &c.y2, &c.z1, &c.z2);
    } else {
      sscanf(s.c_str(), "on x=%d..%d,y=%d..%d,z=%d..%d", &c.x1, &c.x2, &c.y1, &c.y2, &c.z1, &c.z2);
    }
    //cout << x1 << " " << x2 << endl;
    //cout << y1 << " " << y2 << endl;
    //cout << z1 << " " << z2 << endl;
    add(c, on);
  }

  for (auto& e: cubes) {
    ans += e.vol();
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
