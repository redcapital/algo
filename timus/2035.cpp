#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int x, y, c;
  cin >> x >> y >> c;
  int a = min(x, c);
  int b = c - a;
  if (b > y) cout << "Impossible"; else cout << a << " " << b;
  cout << endl;
  return 0;
}
