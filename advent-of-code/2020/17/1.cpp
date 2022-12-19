#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

const unsigned int BASE = 1000;

const int MID = 50;

typedef unsigned long long ull;
typedef int coor;

bool g[2][100][100][100];
int cg, ng;

int count_neighbors(coor x, coor y, coor z) {
  int res = 0;
  for (coor i = -1; i < 2; i++) {
    if (x + i < 0 || x + i > 99) continue;
    for (coor j = -1; j < 2; j++) {
      if (y + j < 0 || y + j > 99) continue;
      for (coor k = -1; k < 2; k++) {
        if (z + k < 0 || z + k > 99) continue;
        if (g[cg][x + i][y + j][z + k]) res++;
      }
    }
  }
  return res - (int)(g[cg][x][y][z]);
}

void cycle() {
  for (coor x = 0; x < 100; x++) {
    for (coor y = 0; y < 100; y++) {
      for (coor z = 0; z < 100; z++) {
        g[ng][x][y][z] = g[cg][x][y][z];
        int cnt = count_neighbors(x, y, z);
        if (g[cg][x][y][z]) {
          if (cnt != 2 && cnt != 3) {
            g[ng][x][y][z] = false;
          }
        } else {
          if (cnt == 3) {
            g[ng][x][y][z] = true;
          }
        }
      }
    }
  }
}

int main() {
  string s;
  int y = 0;
  cg = 0;
  ng = 1;
  memset(g, 0, sizeof(g));
  while (getline(cin, s)) {
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '#') {
        g[cg][MID + i][MID + y][MID] = true;
      }
    }
    y++;
  }

  for (int i = 0; i < 6; i++) {
    cycle();
    swap(cg, ng);
  }

  int ans = 0;
  for (coor x = 0; x < 100; x++) {
    for (coor y = 0; y < 100; y++) {
      for (coor z = 0; z < 100; z++) {
        ans += (int)g[cg][x][y][z];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
