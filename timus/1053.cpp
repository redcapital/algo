// Uses: greatest common divisor

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[])
{
  int n, a, t;
  cin >> n >> a;
  while (--n) {
    cin >> t;
    a = gcd(a, t);
  }
  cout << a << endl;
  return 0;
}
