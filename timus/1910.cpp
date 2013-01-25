#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
  int n, t, a, b, c, mi = 2, mv = 0;
  cin >> n >> a >> b >> c;
  mv = a + b + c;
  for (int i = 3; i < n; ++i) {
    cin >> t;
    a = b;
    b = c;
    c = t;
    if (a + b + c > mv) {
      mv = a + b + c;
      mi = i;
    }
  }

  cout << mv << " " << mi << endl;
  return 0;
}
