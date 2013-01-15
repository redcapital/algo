#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
  int i, n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  for (i = 0; i < m; i++) {
    int t;
    cin >> t;
    ++a[t - 1];
  }
  for (i = 0; i < n; i++) {
    printf("%.2f%%\n", a[i] * 100.0 / m);
  }
  return 0;
}
