#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b, ans;
  cin >> a >> b;
  // Put 39 left ones, and 39 right ones unsuccessfully
  ans = 39 + 39 * 2;
  a -= 39;
  b -= 39;

  // Put remaining left, then try all remaining left ones, and finally right one
  int t = 1 + (a - 1) * 2 + 1;

  // Try and put all right ones then left
  int t2 = b * 2 + 1;

  // Get the worst time
  ans += max(t, t2);
  cout << ans << endl;
  return 0;
}
