// Uses: integer factorization, combinatorics

// Suppose that factorization of some number X is
// p[1] ^ c[1] + p[2] ^ c[2] + ... + p[n] ^ c[n]
//
// Where p is an array of prime numbers.
//
// Number of different dividers of X (including 1 and X) is computed by this
// formula:
// L = (c[1] + 1) * (c[2] + 1) * ... * (c[n] + 1)
//
// We need only last digit of the L, so multiplication is done modulo 10

#include <iostream>
#include <vector>

using namespace std;

const int N = 10000;
const int M = 10;

int c[N + 1] = { 0 };

void factorize(int a) {
  for (int i = 2; a != 1;) {
    if (a % i == 0) {
      a /= i;
      ++c[i];
    } else i++;
  }
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 10; i++) {
    int a;
    cin >> a;
    factorize(a);
  }
  int ans = 1;
  for (int i = 2; i <= N; i++) {
    ans = (ans * (c[i] + 1)) % M;
  }
  cout << ans << endl;
  return 0;
}
