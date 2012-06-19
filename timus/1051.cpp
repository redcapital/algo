#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, m, a;
  cin >> n >> m;
  if (m > n) swap(m, n);
  if (m == 1) a = n / 2 + (n % 2);
  else {
    if (m % 3 == 0 || n % 3 == 0) a = 2; else a = 1;
  }
  cout << a << endl;
  return 0;
}
