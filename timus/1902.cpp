#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, t, s;
  cin >> n >> t >> s;
  while (n--) {
    int a;
    double res;
    cin >> a;
    if (a > s) {
      res = a - s + (t - a + s) / 2.0;
    } else {
      res = (t - s + a) / 2.0;
    }
    printf("%.6lf\n", res + s);
  }
  return 0;
}
