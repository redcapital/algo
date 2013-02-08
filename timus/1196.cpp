// Uses: binary search

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, t, res = 0;
  cin >> n;
  vector<int> a;
  while (n--) {
    cin >> t;
    if (a.empty() || a.back() != t) a.push_back(t);
  }

  cin >> n;
  while (n--) {
    cin >> t;
    if (binary_search(a.begin(), a.end(), t)) ++res;
  }
  cout << res << endl;
  return 0;
}
