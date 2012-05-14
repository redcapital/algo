// Uses: breadth-first search
//
// Just implement what is written, nothing sophisticated

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool isNum(string& x) {
  for (size_t i = 0; i < x.length(); ++i) {
    if (x[i] < '0' || x[i] > '9') return false;
  }
  return true;
}

int toNum(string& x) {
  int res = 0;
  for (size_t i = 0; i < x.length(); ++i) {
    res = res * 10 + (x[i] - '0');
  }
  return res;
}

int main(int argc, char const *argv[])
{
  int a, b;
  string t;
  cin >> a >> b >> t;
  queue< pair<int,int> > q;
  if (isNum(t)) {
    // Image is in the first form. Store it as a boolean matrix 11x11
    bool f[11][11];
    memset(f, 0, sizeof(f));
    int n = a;
    a = b;
    b = toNum(t);
    f[a][b] = true;
    for (size_t i = 1; i < n; ++i) {
      cin >> a >> b;
      f[a][b] = true;
    }
    for (int a = 1; a <= 10; a++) {
      for (int b = 1; b <= 10; b++) {
        if (f[a][b]) {
          q.push(make_pair(a, b));
          f[a][b] = false;
          cout << a << " " << b << endl;
          bool first = true;
          while (!q.empty()) {
            if (first) first = false; else cout << "," << endl;
            pair<int, int> current = q.front();
            q.pop();
            t.clear();
            if (f[current.first + 1][current.second]) {
              f[current.first + 1][current.second] = false;
              q.push(make_pair(current.first + 1, current.second));
              t += "R";
            }
            if (f[current.first][current.second + 1]) {
              f[current.first][current.second + 1] = false;
              q.push(make_pair(current.first, current.second + 1));
              t += "T";
            }
            if (f[current.first - 1][current.second]) {
              f[current.first - 1][current.second] = false;
              q.push(make_pair(current.first - 1, current.second));
              t += "L";
            }
            if (f[current.first][current.second - 1]) {
              f[current.first][current.second - 1] = false;
              q.push(make_pair(current.first, current.second - 1));
              t += "B";
            }
            cout << t;
          }
        }
      }
    }
    cout << "." << endl;
  } else {
    // Image is in the second form. Store it in a vector
    vector< pair<int,int> > g;
    q.push(make_pair(a, b));
    while (!q.empty()) {
      pair<int, int> current = q.front(), adjacent;
      q.pop();
      g.push_back(current);
      for (size_t i = 0; i < t.length(); ++i) {
        adjacent = current;
        bool ok  = true;
        switch (t[i]) {
          case 'T':
            adjacent.second += 1;
            break;
          case 'R':
            adjacent.first += 1;
            break;
          case 'B':
            adjacent.second -= 1;
            break;
          case 'L':
            adjacent.first -= 1;
            break;
          default:
            ok = false;
        }
        if (ok) q.push(adjacent);
      }
      if (t != ".") cin >> t; else t.clear();
    }

    // Sorts by first member, then by second, just as we want :)
    // This sorting behaviour is possible by include'ing <utility> header
    sort(g.begin(), g.end());

    cout << g.size() << endl;
    for (size_t i = 0; i < g.size(); ++i) {
      cout << g[i].first << " " << g[i].second << endl;
    }
  }
  return 0;
}

