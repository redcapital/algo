#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int x;
  vector<int> nums;
  while (cin >> x) {
    nums.push_back(x);
    if (cin.peek() == ',') {
      cin.ignore();
    }
  }
  
  for (int d = 0; d < 80; d++) {
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      if (nums[i] == 0) {
        nums[i] = 6;
        nums.push_back(8);
      } else {
        nums[i]--;
      }
    }
  }

  cout << nums.size() << endl;
  return 0;
}

