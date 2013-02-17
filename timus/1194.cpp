#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int t, ans = 0;
  cin >> t >> t;
  while (cin >> t) {
    cin >> t;
    vector<int> q(t);
    for (int i = 0; i < t; i++) {
      cin >> q[i] >> q[i];
    }
    for (int i = 0; i < t - 1; i++) {
      for (int j = i + 1; j < t; j++) {
        ans += q[i] * q[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
