// Uses: binary search

#include <iostream>

using namespace std;

int a[50000], b[50000];

int binsearch(int lo, int hi, int val) {
  if (lo == hi - 1) {
    return a[lo] == val ? lo : -1;
  }
  int mid = (lo + hi) / 2;
  if (val < a[mid]) {
    return binsearch(lo, mid, val);
  } else if (val > a[mid]) {
    return binsearch(mid, hi, val);
  }
  return mid;
}

int main(int argc, char const *argv[])
{
  int an, bn;
  cin >> an;
  for (int i = 0; i < an; i++) cin >> a[i];
  cin >> bn;
  for (int i = 0; i < bn; i++) cin >> b[i];
  for (int i = 0; i < bn; i++) {
    if (binsearch(0, an, 10000 - b[i]) != -1) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

