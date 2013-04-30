#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, lo = 2, hi = 10, t;
  string w;
  cin >> n;
  bool ok = true;
  while (n--) {
    cin >> t >> w;
    if (w == "hungry") {
      if (t >= hi) {
        ok = false;
        break;
      }
      if (t > lo) lo = t;
    } else {
      if (t <= lo) {
        ok = false;
        break;
      }
      if (t < hi) hi = t;
    }
  }
  if (ok) cout << hi << endl; else cout << "Inconsistent" << endl;
  return 0;
}
