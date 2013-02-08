// It doesn't matter if you put plus or minus sign between numbers, the overall
// parity won't change.
// Every pair will be reduced to either odd or even number. You'll get odd
// if one of the numbers is odd and one is even, otherwise you get even number.
//
// In order for overall parity to be odd, the number of odd numbers must be
// odd. In this case, grimy team wins.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  if (((n + 1) / 2) % 2 == 1) cout << "grimy"; else cout << "black";
  return 0;
}
