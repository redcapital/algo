// Intersection of sorted arrays by moving two pointers.
// Works in linear time. O(n), n - max size of input arrays

#include <iostream>

using namespace std;

const int N = 4000;

int a[N], b[N], ac, bc, ansc;

void intersect() {
  // Intersect a[] and b[], write result into a[]
  int i = 0, j = 0;
  ansc = 0;
  while (i < ac && j < bc) {
    if (a[i] == b[j]) {
      a[ansc++] = a[i];
      ++i;
      ++j;
    } else if (a[i] < b[j]) {
      ++i;
    } else {
      ++j;
    }
  }
}

int main(int argc, char const *argv[])
{
  int i;
  cin >> ac;
  for (i = 0; i < ac; ++i) cin >> a[i];
  cin >> bc;
  for (i = 0; i < bc; ++i) cin >> b[i];
  intersect();

  cin >> bc;
  for (i = 0; i < bc; ++i) cin >> b[i];
  ac = ansc;
  intersect();

  cout << ansc << endl;
  return 0;
}

