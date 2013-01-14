// i-th number of the sequence is 10^i, so it has exactly i digits.
// Therefore, the length of the string composed of first N numbers is:
// L = 1 + 2 + 3 + ... + N = (1 + N) * 2 / N
// So every (L + 1)-th character (and ONLY those) of the string will be "1"
// for any integer N >= 0.
//
// For given K we must tell whether we can find an integer N for the following
// quadratic equation:
// (1 + N) * N / 2 + 1 = K
// or
// N * N + N - (K - 1) * 2 = 0
//
// If we can find such N, then K-th position holds "1", otherwise "0".

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  long long k;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> k;
    k -= 1;
    k *= 2;
    long long d = 1 + 4 * k;
    long long s = (long long)sqrt((long double)d);
    if (s * s == d) cout << 1; else cout << 0;
    cout << " ";
  }
  return 0;
}

