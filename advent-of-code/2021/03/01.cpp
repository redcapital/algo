#include <iostream>
#include <string>

using namespace std;

int main() {
  string c;
  int bits[16], len = -1, n = 0;
  while (cin >> c) {
    n++;
    if (len < 0) {
      len = c.size();
      for (int i = 0; i < len; i++) bits[i] = 0;
    }
    for (int i = 0; i < len; i++) {
      bits[i] += (c[i] == '1') ? 1 : 0;
    }
  }

  int gamma = 0, eps = 0;
  for (int i = 0; i < len; i++) {
    if (bits[i] * 2 > n) {
      gamma |= 1 << (len - i - 1);
      // 2^4 + 2^2 + 2^1
    } else {
      eps |= 1 << (len - i - 1);
    }
  }

  cout << gamma * eps << endl;
  return 0;
}

