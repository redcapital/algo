// Uses: combinatorics

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int b, r, y, k, p = 1;
  cin >> b >> r >> y >> k;
  while (k--) {
    string t;
    cin >> t;
    if (t[0] == 'R') p *= r;
    else if (t[0] == 'Y') p *= y;
    else p *= b;
  }
  cout << p << endl;
  return 0;
}
