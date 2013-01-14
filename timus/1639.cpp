#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
  int n, m;
  cin >> m >> n;
  cout << ((m * n % 2 == 0) ? "[:=[first]": "[second]=:]") << endl;
  return 0;
}
