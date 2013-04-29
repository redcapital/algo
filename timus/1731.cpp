// Consider sequences a[] and b[]. There will be a pair of elements such that
// a[i] + b[j] == a[k] + b[t],
// only if abs(a[i] - a[k]) == abs(b[j] - b[t]), i.e. their differences are
// equal.
//
// So, that means all differences between any two elements in a[] must be
// different from all differences in b[]. To generate such a[] and b[],
// put numbers from 1 to n into a[]. The maximum difference in a[] will be
// n - 1.
//
// Then, put n + 1 as the first element of b[], and each successive element
// must have bigger difference (the difference between first two elements
// should be at least n) from previous.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cout << i;
    if (i < n) cout << " ";
  }
  cout << endl;
  int dif = n, cur = n + 1;
  for (int i = 0; i < m; i++, dif++) {
    if (i) cout << " ";
    cout << cur;
    cur += dif;
  }
  cout << endl;
  return 0;
}
