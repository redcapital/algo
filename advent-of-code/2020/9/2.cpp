#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int BAD = 26134589;

int main() {
  vector<int> a;
  int n;
  while (cin >> n) {
    a.push_back(n);
  }
  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size() && sum < BAD; j++) {
      sum += a[j];
      if (sum == BAD) {
        cout << "From " << i << " to " << j << endl;
        int small = a[i], large = a[i];
        for (int k = i; k <= j; k++) {
          small = min(small, a[k]);
          large = max(large, a[k]);
        }
        cout << "Answer: " << small + large << endl;
      }
    }
  }
  return 0;
}

