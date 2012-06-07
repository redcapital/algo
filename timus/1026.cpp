// Uses: counting sort

// The problem basically asks to sort input array and output i-th element
// for each query
// I think quicksort will be accepted too

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[5001] = { 0 }, p[100000], pc = 1, k;

int main(int argc, char const *argv[])
{
  int t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    ++a[t];
  }
  for (int i = 1; i < 5001; i++) {
    for (int j = 0; j < a[i]; j++) p[pc++] = i;
  }
  scanf("\n###\n%d", &k);
  for (int i = 0; i < k; i++) {
    cin >> t;
    cout << p[t] << endl;
  }
  return 0;
}

