// Just compare every pair of neighbour points.
// Pair with maximum difference of function's value will give largest
// absolute value of inclination.
// Therefore, this algorithm runs in O(N)

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, ans = 0;
  cin >> n;
  long long a, b, mx;
  for (int i = 0; i < n; i++) {
    if (i) {
      cin >> b;
      long long dif = (a > b) ? a - b : b - a;
      if (ans == 0 || mx < dif) {
        mx = dif;
        ans = i;
      }
      a = b;
    } else {
      cin >> a;
    }
  }
  cout << ans << " " << ans + 1 << endl;
  return 0;
}
