// Uses: integer factorization

// You'll need just accurate observations.
// The second player wins only when K = n(L + 1), where n is a natural number.
// Among all values for n you must choose the maximal (since problem asks to
// find minimal L).
//
// Also, I think there is a nonzero answer for any K since for prime values of
// K we can take n = 1 and L will be equal to K - 1.

#include <iostream>

using namespace std;

int K, ans;

void check(int t) {
  int p = K / t - 1;
  if (p > 1 && p < ans) ans = p;
}

int main(int argc, char const *argv[])
{
  cin >> K;
  ans = K;
  for (int i = 1; i * i <= K; i++) {
    if (K % i == 0) {
      check(i);
      check(K / i);
    }
  }
  if (ans == K) ans = 0;
  cout << ans << endl;
  return 0;
}

