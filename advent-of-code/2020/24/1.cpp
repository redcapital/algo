#include <iostream>
#include <cstring>

using namespace std;

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

bool black[MAXN][MAXN];
int total;

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
  black[r][c] = !black[r][c];
  if (black[r][c]) {
    total++;
  } else {
    total--;
  }
}

int main() {
  memset(black, 0, sizeof(black));
  total = 0;
  string s;
  while (getline(cin, s)) {
    flip_color(s);
  }
  cout << total << endl;
  return 0;
}
