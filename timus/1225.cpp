// Uses: dynamic programming

// It can be solved with Fibonacci sequence as well

#include <iostream>
#include <cstring>

using namespace std;

// 0 - white, 1 - red

long long mem[2][44];

long long e(int c, int rem) {
  if (rem == 0) return 1;
  if (mem[c][rem - 1]) return mem[c][rem - 1];
  int ans = 0;
  if (rem >= 2) {
    // Put blue and opposite
    ans += e(!c, rem - 2);
  }
  ans += e(!c, rem - 1);
  return mem[c][rem - 1] = ans;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  memset(mem, 0, sizeof(mem));
  cout << e(0, n - 1) + e(1, n - 1) << endl;
  return 0;
}
