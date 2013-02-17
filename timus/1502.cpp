#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  typedef long long ll;
  int n;
  cin >> n;
  int right = (n * (n + 1)) / 2;
  ll ans = 0;
  ++n;
  for (int i = 0; n >= 1; right -= i, i++, n--) {
    ans += (ll)(i * n + right);
  }
  cout << ans << endl;
  return 0;
}
