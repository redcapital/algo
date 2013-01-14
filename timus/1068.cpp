#include <iostream>

using namespace std;

int iabs(int x) { return x < 0 ? -x : x; }

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  if (n <= 0) cout << (n + 1) * (iabs(n) + 2) / 2;
  else cout << (n + 1) * n / 2;
  return 0;
}
