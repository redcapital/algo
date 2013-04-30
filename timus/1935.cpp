#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, t, mx = -1, ans = 0;
  cin >> n;
  while (n--) {
    cin >> t;
    ans += t;
    if (t > mx) mx = t;
  }
  cout << ans + mx << endl;
  return 0;
}
