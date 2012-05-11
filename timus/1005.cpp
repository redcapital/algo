// Uses: dynamic programming


// This is the pseudo-polynomial solution
// Can be solved with bruteforce however
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
// t[i] is true if we can obtain weight i by summing some stones
bool t[2000001];
int main(int argc, char const *argv[])
{
  int n, w[20], s = 0;
  cin >> n;
  for (size_t i = 0; i < n; ++i)
  {
    cin >> w[i];
    s += w[i];
  }
  memset(t, 0, sizeof(t));

  // We can always obtain zero-weight
  t[0] = true;
  for (size_t i = 0; i < n; ++i)
  {
    for (int j = s - w[i]; j >= 0; j--)
    {
      if (t[j]) t[j + w[i]] = true; // Mark weight (j + w[i]) as reachable
    }
  }
  // We loop through every weight starting from s/2 and going down
  // because s / 2 is the most optimal weight of partition
  // Once we've found reachable weight, it'll be at most s / 2, so the diff
  // will be s - weight * 2
  for (size_t i = s / 2; i >= 0; i--)
  {
    if (t[i]) {
      cout << s - (i * 2) << endl;
      break;
    }
  }
  return 0;
}
