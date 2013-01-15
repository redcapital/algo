// Uses: counting sort
//
// Any stable sorting algorithm would work. Could have used stable_sort
// from standard C++ library.

#include <iostream>

using namespace std;

const int N = 150000;

struct Team {
  int id, m;
} a[N], b[N];

int main(int argc, char const *argv[])
{
  int n, i, c[101] = { 0 };
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i].id >> a[i].m;
    ++c[a[i].m];
  }

  for (int cur = 0, i = 100; i >= 0; i--) {
    int old = c[i];
    c[i] = cur;
    cur += old;
  }

  for (i = 0; i < n; i++) {
    b[c[a[i].m]] = a[i];
    ++c[a[i].m];
  }

  for (i = 0; i < n; i++) {
    cout << b[i].id << " " << b[i].m << endl;
  }
  return 0;
}
