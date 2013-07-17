#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Vertex {
  string s[3];
  int from[3];
};

int main(int argc, char const *argv[])
{
  int i, j, k, n;
  cin >> n;
  vector<Vertex> unsorted(n), sorted;
  vector<int> permutation(n);
  for (i = 0; i < n; i++) for (j = 0; j < 3; j++) cin >> unsorted[i].s[j];
  for (i = 0; i < n; i++) cin >> permutation[i];

  for (i = 0; i < n; i++) {
    sorted.push_back(unsorted[permutation[i] - 1]);
    if (i) {
      for (j = 0; j < 3; j++) sorted[i].from[j] = -1;
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 0; j < 3; j++) {
      if (sorted[i - 1].from[j] < 0) continue;
      for (k = 0; k < 3; k++) {
        if (sorted[i - 1].s[j] < sorted[i].s[k]) {
          sorted[i].from[k] = j;
        }
      }
    }
  }

  j = -1;
  for (i = 0; i < 3; i++) {
    if (sorted[n - 1].from[i] >= 0) {
      j = i;
      break;
    }
  }
  if (j < 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<string> ans;
    for (i = n - 1; i >= 0; i--) {
      ans.push_back(sorted[i].s[j]);
      j = sorted[i].from[j];
    }
    for (i = n - 1; i >= 0; i--) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}
