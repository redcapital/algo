// Uses: combinatorics

// Let's slightly change the original problem:
// How many numbers not greater than T are a sum of K different integer
// degrees of B? Let's denote this function as numLower(T). Answer to the
// original problem is then equal to numLower(Y) - numLower(X - 1)
//
// First, convert T into base B, where a[0] is the most significiant digit.
// Let N = length(a) be the number of digits in a.
// Now, in order for T to be a sum of K different degrees of B there must be
// exactly K "1"s and (Z = N - K) "0"s in base B representation.
// In how many ways we can put these "0"s into Z positions in such a way that
// resulting number does not exceed T ? Let's denote this function as f(a[], Z)
//
// N = length(a) # recompute N
// If Z > N then answer is 0 since there are not enough digits.
//
// Define function rem(a[]) which returns all remaining digits of a except a[0],
// for example rem(1274) -> 274.
//
// If a[0] == 0, we reduce the original problem to f(rem(a), Z - 1)
// If a[0] == 1, we can put "0" or "1" in this position, since we won't exceed T.
//    If we put 1, we reduce the original problem to f(rem(a), Z)
//    If we put 0, we can put any digit in remaining positions. This means
//    we can put Z - 1 "0"s in any possible way into N - 1 positions.
//    This amount is equal to C(N - 1, Z - 1), where C(n, k) is a binomial
//    coefficient.
//    So answer for a[0] == 1 is f(rem(a), Z) + C(N - 1, Z - 1)
// If a[0] > 1, we can put "0" or "1". In any case we can put any digit in
// remaining positions and not exceed T. Thus:
//    If we put 1, there are C(N - 1, Z) valid ways
//    If we put 0, there are C(N - 1, Z - 1) valid ways
//    So answer for a[0] > 1 is C(N - 1, Z) + C(N - 1, Z - 1)
//
// Things to note:
// - there may be integer overflow when computing binomial coefficients
// - carefully handle corner cases

#include <iostream>
#include <algorithm>

using namespace std;

const int D = 32;

int a[D], an;
int x, y, k, b;
int c[D][D] = { 0 };

int f(int z, int s = 0) {
  if (z < 0) return 0;
  if (s == an) {
    return z ? 0 : 1;
  }
  switch (a[s]) {
    case 0:
      return z ? f(z - 1, s + 1) : 0;
    case 1:
      return f(z, s + 1) + (z ? c[an - s - 1][z - 1] : 0);
    default:
      return (z ? c[an - s - 1][z - 1] : 0) + c[an - s - 1][z];
  }
}


int numLower(int num) {
  // Convert num into base b
  an = 0;
  do {
    a[an++] = num % b;
    num /= b;
  } while (num);
  reverse(a, a + an);
  return f(an - k);
}

int main(int argc, char const *argv[])
{
  for (int n = 0; n < D; n++) {
    c[n][0] = c[n][n] = 1;
    for (int k = 1; k < n; k++) c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
  }
  cin >> x >> y >> k >> b;
  cout << numLower(y) - numLower(x - 1) << endl;
  return 0;
}
