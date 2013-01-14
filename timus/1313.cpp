#include <iostream>

using namespace std;

const int N = 100;

int main(int argc, char const *argv[])
{
  int n, i, j, a[N][N];
  cin >> n;
  for (i = 0; i < n; i++) for (j = 0; j < n; j++) cin >> a[i][j];
  for (i = 0, j = 0; i < n; i++, j = 0) {
    int r = i;
    do {
      cout << a[r][j] << " ";
    } while (--r >= 0 && ++j < n);
  }

  for (j = 1, i = n - 1; j < n; j++, i = n - 1) {
    int c = j;
    do {
      cout << a[i][c] << " ";
    } while (--i >= 0 && ++c < n);
  }
  return 0;
}
