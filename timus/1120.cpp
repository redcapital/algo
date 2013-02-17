// Using formula of arithmetic progression:
// a1 + a2 + ... + ap = (a1 + p - 1) * p / 2
// Then:
// N = (a1 + p - 1) * p / 2
// 2N = (a1 + p - 1) * p
//
// So, 2N must be divisible by p. That means instead of bruteforcing all
// possible values for p, we can just check all divisors of 2N in descending
// order (given some p, we can calculate a1)
//
// It runs in O(sqrt(N)) time.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  n *= 2;

  // Factorize n
  vector<int> div;
  div.push_back(1);
  int sq = (int)sqrt((double)n);
  for (int i = 2; i <= sq; i++) {
    if (n % i == 0) {
      div.push_back(n / i);
      div.push_back(i);
    }
  }
  sort(div.begin(), div.end(), greater<int>());

  // Enumerate divisors as possible values for P
  for (int i = 0; i < div.size(); i++) {
    int r = n / div[i];
    r = r - div[i] + 1;
    // Check whether it's possible to find a1
    if (r > 0 && r % 2 == 0) {
      cout << r / 2 << " " << div[i];
      break;
    }
  }
  return 0;
}
