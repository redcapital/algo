// Uses: greedy algorithm

// Take (K / 2 + 1) smallest groups. For each such group sum (c[i] / 2 + 1)
// where c[i] is the number of people in i-th smallest group

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  int K, c[102];
  cin >> K;
  for (int i = 0; i < K; i++) cin >> c[i];
  sort(c, c + K);
  int half = K / 2 + 1, ans = 0;
  for (int i = 0; i < half; i++) {
    ans += c[i] / 2 + 1;
  }
  cout << ans << endl;
  return 0;
}

