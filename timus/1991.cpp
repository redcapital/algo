#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k, unused = 0, survived = 0;
  cin >> n >> k;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    if (t > k) unused += t - k; else survived += k - t;
  }
  cout << unused << " " << survived << endl;
  return 0;
}
