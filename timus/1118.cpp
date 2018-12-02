#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  long long a, b;
  cin >> a >> b;
  long long ans = -1, ansU;
  if (a == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (long long i = b; i >= a; i--) {
    long long sq = sqrt(i);
    long long cur = 0;
    for (long long j = 2; j <= sq; j++) {
      if (i % j == 0) {
        cur += j;
        if (j != i / j) cur += i / j;
      }
    }
    if (!cur) {
      ans = i;
      break;
    }
    if (ans == -1 || cur * ans < ansU * i) {
      ans = i;
      ansU = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
