#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k, ans = 0, f = 1;
  cin >> n >> k;
  for (; f < k && f < n; f *= 2, ans++);
  if (f < n) {
    int rem = n - f;
    ans += rem / k + (rem % k ? 1 : 0);
  }
  cout << ans << endl;
  return 0;
}
