#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, t, a[3] = { 0 };
  cin >> n;
  while (n--) {
    cin >> t;
    a[t - 1]++;
  }
  cout << (
      (a[0] && a[1] && a[2])
      || ((int)(a[0] > 1) + (int)(a[1] > 1) + (int)(a[2] > 1) > 1)
      || ((a[0] || a[1]) && a[2] > 4)
      || ((a[0] || a[2]) && a[1] > 4)
      || ((a[1] || a[2]) && a[0] > 4)

      ? "Yes"
      : "No"
  ) << endl;
  return 0;
}
