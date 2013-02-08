#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, a[101] = { 0 };
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    t -= 600;
    a[t]++;
  }
  int res = 0;
  for (int i = 0; i < 101; i++) {
    res += a[i] / 4;
  }
  cout << res << endl;
  return 0;
}
