#include <iostream>

using namespace std;

const int N = 100;

int main(int argc, char const *argv[])
{
  int i, j, n, t, a[N][N], c = 1;
  cin >> n;
  for (t = n - 1; t >= 0; t--) {
    j = t, i = 0;
    do {
      a[i][j] = c++;
    } while (++i < n && ++j < n);
  }
  for (t = 1; t < n; t++) {
    i = t, j = 0;
    do {
      a[i][j] = c++;
    } while (++i < n && ++j < n);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
