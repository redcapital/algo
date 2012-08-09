// Uses: binary search
//
// Bruteforce all arrays of size i + 1 to N
// and check if you can find element i in an array of size S using L steps

#include <iostream>
#include <vector>

const int N = 10000;
bool f[N + 1] = { 0 };

using namespace std;

int binsearch(int n, int elem) {
  int p = 0;
  int q = n - 1;
  int i, l = 0;
  while (p <= q) {
    i = (p + q) / 2;
    ++l;
    if (i == elem) return l; // Imaginary array where a[i] = i
    if (i > elem) q = i - 1;
    else p = i + 1;
  }
}

int main(int argc, char const *argv[])
{
  int a, b;
  cin >> a >> b;
  for (int i = a + 1; i <= N; i++)
    if (binsearch(i, a) == b) f[i] = true;

  vector <int> ans;
  int s = 0;
  for (int i = 1; i <= N + 1; i++) {
    if (f[i] && !s) {
      s = i;
    } else if (!f[i] && s) {
      ans.push_back(s);
      ans.push_back(i - 1);
      s = 0;
    }
  }
  cout << ans.size() / 2 << endl;
  for (int i = 0; i < ans.size(); i += 2) cout << ans[i] << " " << ans[i + 1] << endl;
  return 0;
}
