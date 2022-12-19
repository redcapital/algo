#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  string s;
  map<int, pair<int, int>> seen;
  int i = 1, recent;
  while (getline(cin, s, ',')) {
    recent = stoi(s);
    seen[recent] = make_pair(i, 0);
    i++;
  }
  for (; i <= 30000000; i++) {
    if (seen[recent].second == 0) {
      recent = 0;
    } else {
      recent = seen[recent].second - seen[recent].first;
    }

    if (seen.count(recent) == 0) {
      seen[recent] = make_pair(i, 0);
    } else {
      if (seen[recent].second == 0) {
        seen[recent].second = i;
      } else {
        seen[recent].first = seen[recent].second;
        seen[recent].second = i;
      }
    }
  }

  cout << recent << endl;
}

