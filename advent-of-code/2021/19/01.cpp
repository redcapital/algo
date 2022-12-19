#include <iostream>
#include <string>
#include <tuple>
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

struct coord {
  int x,y,z;
  //int c[3];

  bool operator<(const coord& b) const {
    //return tie(x,y,z) < tie(b.x,b.y,b.z);
    if (x < b.x) return true;
    if (x > b.x) return false;
    if (y < b.y) return true;
    if (y > b.y) return false;
    if (z < b.z) return true;
    if (z > b.z) return false;
    return false;
  }
};

vector<coord> coords[500];
map<coord, bool> tot;
map<coord, bool> m[500];
vector<coord> gen1[500], gen2;
coord diffs[500];
bool processed[500];
int nump;

void trydir(const coord& a, int dir) {
  coord c;
  c.z = a.z;

  switch (dir) {
    case 0:
    c.x = a.x;
    c.y = a.y;
    break;
    case 1:
    c.x = -a.y;
    c.y = a.x;
    break;
    case 2:
    c.x = -a.x;
    c.y = -a.y;
    break;
    case 3:
    c.x = a.y;
    c.y = -a.x;
    break;
  }
  gen2.push_back(c);
}

void tryface(const coord& a, int face, int dir) {
  coord c;
  switch (face) {
    case 0:
    // facing X
    c.x = -a.z;
    c.y = a.y;
    c.z = a.x;
    break;
    case 1:
    // facing -X
    c.x = a.z;
    c.y = a.y;
    c.z = -a.x;
    break;
    case 2:
    // facing Z
    c.x = a.x;
    c.y = a.y;
    c.z = a.z;
    break;
    case 3:
    // facing -Z
    c.x = -a.x;
    c.y = a.y;
    c.z = -a.z;
    break;
    case 4:
    // facing Y
    c.x = a.x;
    c.y = -a.z;
    c.z = a.y;
    break;
    case 5:
    // facing -Y
    c.x = -a.x;
    c.y = -a.z;
    c.z = -a.y;
    break;
  }
  trydir(c, dir);
}

void printm() {
  cout << "tot is now: " << endl;
  for (auto x: tot) {
    if (x.second) {
      cout << x.first.x << "," << x.first.y << "," << x.first.z << endl;
    }
  }
}
int mcnt(int s, int dx, int dy, int dz) {
  int cnt=0;
  FOR(i,gen2.size()) {
    coord c;
    c.x = gen2[i].x + dx;
    c.y = gen2[i].y + dy;
    c.z = gen2[i].z + dz;
    if (m[s][c]) cnt++;
  }
  return cnt;
}

bool search(int s, int cur) {
  FOR(i,gen1[s].size()) {
    FOR(j,gen2.size()) {
      int dx = gen1[s][i].x - gen2[j].x;
      int dy = gen1[s][i].y - gen2[j].y;
      int dz = gen1[s][i].z - gen2[j].z;
      if (mcnt(s, dx, dy, dz) >= 12) {
        gen1[cur].clear();
        m[cur].clear();
        diffs[cur].x = dx;
        diffs[cur].y = dy;
        diffs[cur].z = dz;
        cout << "scanner " << cur << " diff is " << dx << "," << dy << "," << dz << endl;
        FOR(k,gen2.size()) {
          coord c;
          c.x = gen2[k].x + dx;
          c.y = gen2[k].y + dy;
          c.z = gen2[k].z + dz;
          tot[c]=m[cur][c]=true;
          gen1[cur].push_back(c);
          //cout << "match for " << c.x << "," << c.y << "," << c.z << endl;
          //if (m[c]) {
            //cout << "match for " << c.x << "," << c.y << "," << c.z << endl;
          //}
        }
        //printm();
        return true;
      }
    }
  }
  return false;
}


int main() {
  int sc;

  string s;
  while (getline(cin, s)) {
    if (!s.size()) continue;
    if (s[0] == '-' && s[1] == '-') {
      sscanf(s.c_str(), "--- scanner %d ---", &sc);
      continue;
    }
    coord c;
    sscanf(s.c_str(), "%d,%d,%d", &c.x, &c.y, &c.z);
    coords[sc].push_back(c);
  }

  /*
  for (int i = 0; i <= sc; i++) {
    cout << "--- scanner " << i << " ---" << endl;
    for (auto x: coords[i]) {
      cout << x.x << "," << x.y << "," << x.z << endl;
    }
    cout << endl;
  }
  return 0;
  */

  //PRINTL(coords[0].size());
  //for(const auto& c: coords[0]) {
    //cout << c.x << " " << c.y << " " << c.z << endl;
  //}
  //return 0;


  CLEAR(processed);
  for(const auto& c: coords[0]) {
    tot[c] = m[0][c] = true;
    gen1[0].push_back(c);
  }
  diffs[0].x = 0;
  diffs[0].y = 0;
  diffs[0].z = 0;
  processed[0] = true;
  nump = 1;
  printm();

  while (nump != sc + 1) {
    for (int i = 0; i <= sc; i++) {
      if (processed[i]) continue;
      bool ok = false;
      FOR(face,6) {
        FOR(dir,4) {
          gen2.clear();
          for(const auto& c: coords[i]) {
            tryface(c, face, dir);
          }
          FOSE(s,0,sc) {
            if (!processed[s]) continue;
            if (search(s, i)) {
              cout << "Station " << i << " overlaps with " << s << " in conf " << face << " " << dir << endl;
              ok=true;
              //gen1 = gen2;
              //m.clear();
              //for (const auto& c: gen2) {
                //cout << "marking " << c.x << ","<<c.y<<","<<c.z<<endl;
                //tot[c]=m[c]=true;
              //}
              //for(const auto& c: coords[i]) {
                //tryface(c, face, dir, true);
              //}
              break;
            }
          }
          if (ok) break;
        }
        if (ok) break;
      }
      if (ok) {
        processed[i] = true;
        nump++;
        cout << "pr size is now " << nump << endl;
        break;
      }
    }
  }

  PRINTL(tot.size());

  int ans = 0;
  FOSE(i,0,sc) {
    FOSE(j,0,sc) {
      if (i==j) continue;
      int d = abs(diffs[i].x-diffs[j].x) + abs(diffs[i].y-diffs[j].y) + abs(diffs[i].z-diffs[j].z);
      ans = max(d, ans);
    }
  }
  PRINTL(ans);

  // facing X
  // -z, y, x
  // -y, -z, x
  // z, -y, x
  // y, z, x
  //
  // facing -X
  // z, y, -x
  // -y, z, -x
  // -z, -y,-x
  // y, -z, -x
  //
  // facing Z
  // x, y, z
  // -y,x, z
  // -x,-y,z
  // y,-x, z
  //
  // facing -Z
  // -x, y, -z
  // -y, -x,-z
  // x, -y, -z
  // y, x, -z
  //
  // facing Y
  // x, -z, y
  //
  // facing -Y
  // -x, -z, -y

  // x, y, z
  // -z,y, x
  // -x,y,-z
  // z,y,-x
  //
  // x,z,-y
  // y,z,x
  // -x,z,y
  // -y,z,-x
  // 
  // 
  // 
  // 
  //
  // -x,y,z
  // -x,-y,z
  // x,y, -z
  // x,-y,-z
  // -x,y,z
  // -x,-y,z
  //
  // -x,y,z
  // x,y,z
  // x,y,z
  //

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
