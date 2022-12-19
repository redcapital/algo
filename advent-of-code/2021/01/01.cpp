#include <iostream>

using namespace std;

int main() {
  int n, last = -1, ans = 0;
  while (cin >> n) {
    if (last > -1 && n > last) {
      ans++;
    }
    last = n;
  }
  cout << ans << endl;
  return 0;
}

