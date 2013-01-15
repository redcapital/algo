#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, c, cur = -1, t;
  cin >> n;
  while (n--) {
    cin >> t;
    if (t != cur) {
      if (cur > 0) cout << c << " " << cur << " ";
      c = 0;
      cur = t;
    }
    ++c;
  }
  cout << c << " " << cur << endl;
  return 0;
}
