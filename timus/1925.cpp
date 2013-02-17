#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k;
  cin >> n >> k;
  int s = k - (n + 1) * 2, s2 = 0;
  for (int i = 0; i < n; i++) {
    int b, g;
    cin >> b >> g;
    s += b;
    s2 += g;
  }
  if (s - s2 < 0) cout << "Big Bang!";
  else cout << s - s2 ;
  return 0;
}
