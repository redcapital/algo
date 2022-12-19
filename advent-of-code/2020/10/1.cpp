#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  vector<int> v;
  while (cin >> n) {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  v.push_back(v[v.size() - 1] + 3);
  int cur = 0, c1 = 0, c3 = 0;
  for (int i = 0; i < v.size(); i++) {
    int dif = v[i] - cur;
    if (dif == 1) {
      c1++;
    } else if (dif == 3) {
      c3++;
    }
    cur = v[i];
  }
  cout << c1 * c3 << endl;
  return 0;
}
