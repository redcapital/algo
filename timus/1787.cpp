#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, k, s = 0, t;
  cin >> k >> n;
  while (n--) {
    cin >> t;
    s = max(s + t - k, 0);
  }
  cout << s << endl;
  return 0;
}
