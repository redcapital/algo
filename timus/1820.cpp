#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << 2;
  } else {
    n *= 2;
    cout << n / k + ((n % k) ? 1 : 0) << endl;
  }
  return 0;
}
