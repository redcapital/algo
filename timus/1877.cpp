#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b;
  cin >> a >> b;
  if ((a % 2) == 0 || (b % 2) == 1) cout << "yes"; else cout << "no";
  return 0;
}
