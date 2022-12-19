#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b, long long & x, long long & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

long long inverse(long long a, long long m) {
  long long x, y;
  long long g = gcd(a, m, x, y);
  if (g != 1) {
    cerr << "Cant find inverse" << endl;
  }
  return (x % m + m) % m;
}

int main() {
  long long mod[200], r[200], m[200], minv[200], sz = 0;
  string s;
  getline(cin, s);
  int i = 0;
  while (getline(cin, s, ',')) {
    if (s != "x") {
      mod[sz] = stoi(s);
      r[sz] = (10 * mod[sz] - i) % mod[sz];
      sz++;
    }
    i++;
  }
  for (i = 0; i < sz; i++) {
    cout << r[i] << " mod " << mod[i] << endl;
  }


  long long M = 1;
  for (int i = 0; i < sz; i++) {
    M *= mod[i];
  }
  for (int i = 0; i < sz; i++) {
    m[i] = M / mod[i];
  }
  for (int i = 0; i < sz; i++) {
    minv[i] = inverse(m[i], mod[i]);
  }

  long long ans = 0;
  for (int i = 0; i < sz; i++) {
    ans = (ans + r[i] * m[i] * minv[i]) % M;
  }

  cout << ans << endl;
  return 0;
}
