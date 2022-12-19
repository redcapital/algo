#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

const unsigned int BASE = 1000;

const int N = 30;
const int MID = N / 2;

typedef unsigned long long ull;
typedef int coor;

bool g[2][N][N][N][N];
int cg, ng;

int count_neighbors(coor x, coor y, coor z, coor w) {
  int res = 0;
  for (coor i = -1; i < 2; i++) {
    if (x + i < 0 || x + i >= N) continue;
    for (coor j = -1; j < 2; j++) {
      if (y + j < 0 || y + j >= N) continue;
      for (coor k = -1; k < 2; k++) {
        if (z + k < 0 || z + k >= N) continue;
        for (coor m = -1; m < 2; m++) {
          if (w + m < 0 || w + m >= N) continue;
          if (g[cg][x + i][y + j][z + k][w + m]) res++;
        }
      }
    }
  }
  return res - (int)(g[cg][x][y][z][w]);
}

void cycle() {
  for (coor x = 0; x < N; x++) {
    for (coor y = 0; y < N; y++) {
      for (coor z = 0; z < N; z++) {
        for (coor w = 0; w < N; w++) {
          g[ng][x][y][z][w] = g[cg][x][y][z][w];
          int cnt = count_neighbors(x, y, z, w);
          if (g[cg][x][y][z][w]) {
            if (cnt != 2 && cnt != 3) {
              g[ng][x][y][z][w] = false;
            }
          } else {
            if (cnt == 3) {
              g[ng][x][y][z][w] = true;
            }
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
        g[cg][MID + i][MID + y][MID][MID] = true;
      }
    }
    y++;
  }

  for (int i = 0; i < 6; i++) {
    cycle();
    swap(cg, ng);
  }

  int ans = 0;
  for (coor x = 0; x < N; x++) {
    for (coor y = 0; y < N; y++) {
      for (coor z = 0; z < N; z++) {
        for (coor w = 0; w < N; w++) {
          ans += (int)g[cg][x][y][z][w];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
