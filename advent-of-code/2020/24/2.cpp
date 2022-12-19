#include <iostream>
#include <cstring>

using namespace std;

const int DAYS = 100;
const int MAXN = 300;
const int dd[2][6][2] = {
  // even
  {
    { -1, -1 },
    { -1, 0  },
    {  0, 1  },
    {  1, 0  },
    {  1, -1 },
    {  0, -1 },
  },
  // odd
  {
    { -1, 0  },
    { -1, 1  },
    {  0, 1  },
    {  1, 1  },
    {  1, 0  },
    {  0, -1 },
  },
};

bool black[2][MAXN][MAXN];
int cg, total;

void flip_color(const string& s) {
  int i = 0, r = MAXN / 2, c = MAXN / 2;
  while (i < s.size()) {
    switch (s[i]) {
      case 'e':
        c++;
        i++;
        break;
      case 'w':
        c--;
        i++;
        break;
      case 's':
        if (r % 2) {
          if (s[i + 1] == 'e') {
            c++;
          }
        } else {
          if (s[i + 1] == 'w') {
            c--;
          }
        }
        r++;
        i += 2;
        break;
      case 'n':
        if (r % 2) {
          if (s[i + 1] == 'e') {
            c++;
          }
        } else {
          if (s[i + 1] == 'w') {
            c--;
          }
        }
        r--;
        i += 2;
        break;
    }
  }
  black[cg][r][c] = !black[cg][r][c];
}

void process_day() {
  int ng = cg ? 0 : 1;
  total = 0;
  for (int r = 0; r < MAXN; r++) {
    for (int c = 0; c < MAXN; c++) {
      black[ng][r][c] = black[cg][r][c];
      int cnt = 0;
      int idx = r % 2;
      for (int i = 0; i < 6; i++) {
        int nr = r + dd[idx][i][0];
        int nc = c + dd[idx][i][1];
        if (nr < 0 || nr == MAXN || nc < 0 || nc == MAXN) continue;
        if (black[cg][nr][nc]) cnt++;
      }
      if (black[cg][r][c]) {
        if (cnt == 0 || cnt > 2) {
          black[ng][r][c] = false;
        }
      } else {
        if (cnt == 2) {
          black[ng][r][c] = true;
        }
      }
      
      if (black[ng][r][c]) total++;
    }
  }
  cg = ng;
}

int main() {
  memset(black, 0, sizeof(black));
  cg = total = 0;
  string s;
  while (getline(cin, s)) {
    flip_color(s);
  }
  
  for (int day = 1; day <= DAYS; day++) process_day();
  
  cout << total << endl;
  return 0;
}
