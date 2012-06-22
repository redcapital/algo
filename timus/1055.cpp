// Uses: Sieve of Eratosthenes

// Take some prime P. How many times does P occur in a factorization of X! ?
// Since X! = 1 * 2 * 3 ... * X, every P-th number will be divisable by P
// S = X / P (take only integer part)
// Every P^2-th number will be divisable by P too, and add 1 to the total amount
// S = S + X / (P ^ 2)
// And so on, so formula will be:
// num(X, P) = X / P + X / (P ^ 2) + ... + X / (P ^ i), for maximum possible i
//
// Now to the problem. Assume N > M.
// Let's denote (N - M) as A, so C = N! / (M! * A!)
// C will be divisible by some prime P iff
// num(C, P) - num(M, P) - num(A, P) > 0
//
// Iterate through all primes in range [2, N] and increment answer if the
// condition above holds.

#include <iostream>
#include <cstring>

using namespace std;

const int N = 50000;

bool primes[N + 1];

int main(int argc, char const *argv[])
{
  memset(primes, true, sizeof(primes));
  int n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << 0 << endl;
    return 0;
  }
  int a = n - m, ans = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      // Sieve
      for (long long j = (long long)i * i; j <= n; j += i) {
        primes[j] = false;
      }
      int diff = 0;
      for (long long power = i; power <= n; power *= i) {
        diff += n / power - m / power - a / power;
      }
      if (diff > 0) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
