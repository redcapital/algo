#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  pair<int, int> p[4];
  char x;
  for (int i = 0, n = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> x;
      if (x == 'X') {
        p[n].first = i;
        p[n].second = j;
        ++n;
      }
    }
  }

  string s[4], res;
  for (int i = 0; i < 4; i++) cin >> s[i];

  for (int i = 0; i < 4; i++) {
    sort(p, p + 4);
    for (int j = 0; j < 4; j++) {
      res += s[p[j].first][p[j].second];
      int nc = 3 - p[j].first;
      p[j].first = p[j].second;
      p[j].second = nc;
    }
  }

  cout << res;
  return 0;
}
