// Uses: integer factorization

// The idea is simple: factorize N and count all primes less than 10
// If there is a prime greater than 9, then answer is -1, since we can't
// express such prime by multiplying two digits
// Then we do replacements in this order and add results to the answer array:
//   2 * 2 * 2-> 8 (i.e. three 2's will be replaced by one 8)
//   3 * 3 -> 9
//   2 * 3 -> 6
//   2 * 2 -> 4
//
// After this we'll add remaining primes to the answer array and sort it

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int PC = 4;
int main(int argc, char const *argv[])
{
  int N;
  int primes[PC] = { 2, 3, 5, 7 };
  cin >> N;
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (N == 0) {
    cout << 10 << endl;
    return 0;
  }

  // Number of primes
  int a[PC];
  memset(a, 0, sizeof(a));

  int i = 0;
  while (i < PC) {
    if (N % primes[i] == 0) {
      a[i]++;
      N /= primes[i];
    } else i++;
  }
  if (N > 1) {
    // N is prime greater than 10
    cout << -1;
  } else {
    vector<short int> ans;
    // Replacements
    while (a[0] > 2) {
      ans.push_back(8);
      a[0] -= 3;
    }
    while (a[1] > 1) {
      ans.push_back(9);
      a[1] -= 2;
    }
    while (a[0] > 0 && a[1] > 0) {
      ans.push_back(6);
      a[0] -= 1;
      a[1] -= 1;
    }
    while (a[0] > 1) {
      ans.push_back(4);
      a[0] -= 2;
    }

    // Add remaining primes
    for (int i = 0; i < PC; i++)
      for (int j = 0; j < a[i]; j++)
        ans.push_back(primes[i]);

    // Sort digits
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
  }
  cout << endl;
  return 0;
}
