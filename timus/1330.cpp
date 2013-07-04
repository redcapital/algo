#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, i, j;
  long long t;
  vector<long long> sums;

  cin >> n;
  while (n--) {
    cin >> t;
    if (!sums.empty()) {
      t += sums.back();
    }
    sums.push_back(t);
  }

  cin >> n;
  while (n--) {
    cin >> i >> j;
    cout << sums[j - 1] - (i > 1 ? sums[i - 2] : 0) << endl;
  }
  return 0;
}
