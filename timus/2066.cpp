#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b, c;
  cin >> a >> b >> c;
  int x = b * c;
  int y = b + c;
  cout << a - max(x, y) << endl;
  return 0;
}
