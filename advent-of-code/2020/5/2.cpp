#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binsearch(int lo, int hi, const string& s) {
  for (int i = 0; i < s.size(); i++) {
    int mid = (lo + hi) / 2;
    if (s[i] == 'F' || s[i] == 'L') {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main() {
  string s;
  vector<int> ids;
  while (cin >> s) {
    int row = binsearch(0, 127, s.substr(0, 7));
    int col = binsearch(0, 7, s.substr(7, 3));
    int id = row * 8 + col;
    ids.push_back(id);
  }
  sort(ids.begin(), ids.end());
  for (int i = 1; i < ids.size(); i++) {
    if (ids[i] - ids[i - 1] > 1) {
      cout << "Gap between " << ids[i - 1] << " and " << ids[i] << endl;
    }
  }
  return 0;
}

