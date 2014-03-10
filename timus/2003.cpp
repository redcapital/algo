// Uses: integer factorization
//
// If you end up with an array with three equal numbers:
//
// {x, y, z, z, z}
//
// then no matter how many times you do transform, you'll end up with at least
// the three of those numbers again. Now consider this:
//
// {a, b, c, 2c, 4c}
//
// Last three numbers will transform into {c, c, 2c} and then into {c, c, c}
// and this again leads to infinite result. So if you have at least three
// numbers in the array with equal GCD, then the result is infinity. Otherwise,
// if you have two for each prime number, then it will take two steps. If you
// have just one number for each prime, then it takes one step.

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, a, ans = 0, maxPrimeCount = 0;
  cin >> n;
  map<int, int> cnt;
  while (n--) {
    cin >> a;
    int sq = (int)sqrt(a * 1.0);
    for (int i = 2; i <= sq; i++) {
      if (a % i == 0) {
        cnt[i]++;
        while (a % i == 0) a /= i;
        maxPrimeCount = max(maxPrimeCount, cnt[i]);
        if (maxPrimeCount > 2) goto printResult;
      }
    }
    if (a != 1) {
      cnt[a]++;
      maxPrimeCount = max(maxPrimeCount, cnt[a]);
      if (maxPrimeCount > 2) goto printResult;
    }
  }

printResult:

  if (maxPrimeCount > 2) cout << "infinity";
  else cout << maxPrimeCount;
  cout << endl;
  return 0;
}
