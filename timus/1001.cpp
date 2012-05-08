#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double res[200000];

int main() {
  long double a;
  int c = 0;
  while (cin >> a) {
    res[c++] = sqrt(a);
  }
  for (int i = c - 1; i >= 0; i--) {
    printf("%.4f\n", res[i]);
  }
  return 0;
}

