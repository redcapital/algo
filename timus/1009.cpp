// Uses: inclusion-exclusion principle

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define NMAX 16
int main(int argc, char const *argv[])
{
  int N, K, degs[NMAX];
  cin >> N >> K;

  int F = K - 1;
  degs[0] = 1;
  for (int i = 1; i < N; i++) {
    degs[i] = degs[i - 1] * K;
  }

  int bad = 0; // Total number of elements in bad sets
  int setCount = N - 2; // Total number of bad sets
  bool active[NMAX - 2], zeroMask[NMAX - 1];
  for (int i = 1; i <= setCount; i++) {
    // i - Count of sets being intersected
    memset(active, 0, sizeof(active));

    // Look all possible combinations of i sets and sum them
    int sum = 0;
    for (int j = 0; j < i; j++) {
      active[setCount - j - 1] = true;
    }
    do {
      memset(zeroMask, 0, sizeof(zeroMask));
      for (int j = 0; j < setCount; j++) {
        if (active[j]) {
          // "00" starts from j
          zeroMask[j] = zeroMask[j + 1] = true;
        }
      }
      int nonZeros = N - 1;
      for (int j = 0; j < N - 1; j++) {
        if (zeroMask[j]) nonZeros--;
      }
      sum += F * degs[nonZeros];
    } while (next_permutation(active, active + setCount));

    // Sum with overall bad count
    if (i % 2 == 0) sum = -sum;
    bad += sum;
  }

  cout << (F * degs[N - 1] - bad) << endl;
  return 0;
}

