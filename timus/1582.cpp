// Since all three events (1st win, 2nd win, draw) may occur with equal
// probabilities, we must ensure we'll get equal amount of money in any of
// these events:
//
// k1 * p1 = k2 * p2 = k3 * p3 = maximum possible outcome (i.e. the answer),
//
// where p[i] is amount of money to put on i-th event.
// Answer is equal in all cases, so we can calculate any of p1, p2 or p3.
// Also, note that
//
// p1 + p2 + p3 = 1000.
//
// Now, substituting p2 and p3 we have:
//
// p1 + k1 * p1 / k2 + k1 * p1 / k3 = 1000
//
// This equation allows us to compute p1:
//
// p1 = 1000 * k2 * k3 / (k2 * k3 + k1 * k3 + k1 * k2).
//
// Then, as we saw earlier, answer = p1 * k1

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  double k1, k2, k3, p;
  cin >> k1 >> k2 >> k3;
  p = 1000 * k2 * k3 / (k2 * k3 + k1 * k3 + k1 * k2);
  cout << round(p * k1) << endl;
  return 0;
}
