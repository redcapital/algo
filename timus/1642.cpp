#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, x, left = -1001, right = 1001;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t < 0 && t > left) left = t;
    if (t > 0 && t < right) right = t;
  }
  if (x > left && x < right) {
    if (x > 0) {
      cout << x << " " << -2 * left + x << endl;
    } else {
      cout << 2 * right + (-x) << " " << -x << endl;
    }
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
