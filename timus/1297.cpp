// For N like 10^6 this bruteforce will timeout.
// DP approach: for each index i,  try to expand a string centered at i to
// both left and right (consider even and odd length strings). This approach
// gives O(N*M) where M is the length of longest palindrome.

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  getline(cin, s);
  int n = s.length(), start, curmax = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = n - i; j >= 2; j--) {
      if (j <= curmax) break;
      bool ok = true;
      for (int k = 0; k < j / 2; k++) {
        if (s[i + k] != s[i + j - 1 - k]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        curmax = j;
        start = i;
        break;
      }
    }
  }
  if (curmax == 0) {
    cout << s[0];
  } else {
    cout << s.substr(start, curmax);
  }
  cout << endl;
  return 0;
}
