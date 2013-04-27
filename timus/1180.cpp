// Any N divisible by 3 is a bad number, meaning first player loses.
//
// Case N = 3 it's trivial, whatever the first player takes (1 or 2) he'll lose.
//
// Now, when N % 3 == 0, say first player take X stones. Thus:
// (N - X) % 3 = N % 3 - X % 3 = 1 or 2 (because X isn't divisible by 3, it's
// a power of 2, remember?)
//
// Depending on remainder, second player takes that amount (1 or 2) stones and
// now N % 3 == 0 again (meaning first player is in losing state again).
// Since each turn reduces N, eventually first player will end up with N = 3.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int s = 0;
  char c;
  while (cin >> c) {
    s = (s + (c - '0')) % 3;
  }
  cout << (s ? 1 : 2) << endl;
  if (s) cout << s << endl;
  return 0;
}
