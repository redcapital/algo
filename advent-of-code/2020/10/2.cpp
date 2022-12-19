#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  vector<long long> v, d;
  v.push_back(0);
  while (cin >> n) {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  v.push_back(v[v.size() - 1] + 3);
  int sz = v.size();
  d.resize(sz, 0);
  d[0] = 1;

  for (int i = 0; i < sz - 1; i++) {
    for (int j = i + 1; j < sz; j++) {
      if (v[j] - v[i] > 3) {
        break;
      }
      d[j] += d[i];
    }
  }

  // 688136192 is too low
  cout << d[sz - 1] << endl;
  return 0;
}
