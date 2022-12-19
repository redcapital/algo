#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

long long cnt[257][9];
bool done[257][9];

long long getcnt(int days, int num) {
  if (done[days][num]) {
    return cnt[days][num];
  }
  long long ans = 0;
  for (int d = days - num - 1; d >= 0; d -= 7) {
    ans += 1 + getcnt(d, 8);
  }
  done[days][num] = true;
  return cnt[days][num] = ans;
}

int main() {
  memset(cnt, 0, sizeof(cnt));
  memset(done, 0, sizeof(done));
  int x;
  vector<int> nums;
  while (cin >> x) {
    nums.push_back(x);
    if (cin.peek() == ',') {
      cin.ignore();
    }
  }

  long long ans = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    ans += getcnt(256, nums[i]);
  }

  cout << ans << endl;
  return 0;
}

