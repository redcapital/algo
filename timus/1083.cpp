#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k = 0, s = 0;
  cin >> n;
  char c;
  while (cin >> c) ++k;
  for (s = n, n -= k; n > 0; n -= k)  s *= n ;
  cout << s << endl;
  return 0;
}
