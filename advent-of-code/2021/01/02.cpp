#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, ans = 0;
  vector<int> a;
  while (cin >> n) {
    a.push_back(n);
  }
  for (int i = 0; i < a.size() - 3; i++) {
    int s1 = a[i] + a[i + 1] + a[i + 2];
    int s2 = a[i + 1] + a[i + 2] + a[i + 3];
    if (s2 > s1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

