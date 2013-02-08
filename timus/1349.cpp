// Uses: Fermat's Last Theorem

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  if (n == 1) cout << "1 2 3";
  else if (n == 2) cout << "3 4 5";
  else cout << "-1";
  return 0;
}
