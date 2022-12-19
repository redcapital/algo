#include <iostream>

using namespace std;

const long long MOD = 20201227;

int find_loopsize(long long num) {
  long long v = 1;
  for (int i = 1; ; i++) {
    v = (v * 7) % MOD;
    if (v == num) {
      return i;
    }
  }
}

long long transform(long long subject, int loopsize) {
  long long res = subject;
  for (int i = 1; i < loopsize; i++) {
    res = (res * subject) % MOD;
  }
  return res;
}

int main() {
  long long x1, x2;
  cin >> x1 >> x2;
  
  int m1 = find_loopsize(x1);
  cout << "Loop size: " << m1 << endl;
  cout << "Key: " << transform(x2, m1) << endl;
  
  return 0;
}
