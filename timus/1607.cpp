#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (a < c) {
    a += b;
    if (a > c) a = c;
    c -= d;
  }
  cout << a;
  return 0;
}
