#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int avg = n / k;
    int avgCount = k;
    int upCount = n % k;
    avgCount -= upCount;

    int ans = 0, used = 0;
    for (int i = 1; i <= k - 1; i++) {
      int cnt = i <= avgCount ? avg : (avg + 1);
      used += cnt;
      ans += cnt * (n - used);
    }

    cout << ans << endl;
  }
  return 0;
}
