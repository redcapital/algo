#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int x, mn, mx, sum = 0;
  vector<int> nums;
  while (cin >> x) {
    nums.push_back(x);
    if (!sum) {
      mn = mx = x;
    } else {
      mn = min(mn, x);
      mx = max(mx, x);
    }
    sum += x;
    if (cin.peek() == ',') {
      cin.ignore();
    }
  }

  int ans = -1;
  for (int i = mn; i <= mx; i++) {
    int cur = 0;
    for (int j = 0; j < nums.size(); j++) {
      int dif = abs(nums[j] - i);
      cur += ((1 + dif) * dif) / 2;
    }
    if (ans == -1 || (cur < ans)) {
      ans = cur;
    }
  }

  cout << ans << endl;
  return 0;
}

