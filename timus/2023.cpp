#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, ans = 0, cur = 1;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s[0] == 'A' || s[0] == 'P' || s[0] == 'O' || s[0] == 'R') {
      ans += abs(cur - 1);
      cur = 1;
    } else if (s[0] == 'B' || s[0] == 'M' || s[0] == 'S') {
      ans += abs(cur - 2);
      cur = 2;
    } else {
      ans += abs(cur - 3);
      cur = 3;
    }
  }
  cout << ans << endl;
  return 0;
}
