#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, x, y, s1, s2;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x >> y;
  if (x == y) {
    s1 = accumulate(a.begin(), a.begin() + x, 0);
    s2 = accumulate(a.begin() + x - 1, a.end(), 0);
    if (s1 < s2) {
      swap(s1, s2);
    }
    s2 -= a[x - 1];
  } else {
    if (x < y) {
      int d = y - x - 1;
      int mid = x + d / 2;
      s1 = accumulate(a.begin(), a.begin() + mid + d % 2, 0);
      s2 = accumulate(a.begin() + mid + d % 2, a.end(), 0);
    } else {
      int d = x - y - 1;
      int mid = y + d / 2;
      s1 = accumulate(a.begin() + mid, a.end(), 0);
      s2 = accumulate(a.begin(), a.begin() + mid, 0);
    }
  }
  cout << s1 << " " << s2 << endl;
  return 0;
}
