#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
  int i, j, n, a[100][100], rs[100][100], ans = numeric_limits<int>::min();
  cin >> n;
  for (i = 0; i < n; i++) for (j = 0; j < n; j++) cin >> a[i][j];

  for (i = 0; i < n; i++) {
    rs[i][0] = a[i][0];
    for (j = 1; j < n; j++) rs[i][j] = rs[i][j - 1] + a[i][j];
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (int j2 = j; j2 < n; j2++) {
        int sum = 0;
        for (int i2 = i; i2 < n; i2++) {
          int segmentSum = rs[i2][j2];
          if (j) {
            segmentSum -= rs[i2][j - 1];
          }
          sum += segmentSum;
          ans = max(ans, sum);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
