// Uses: Gaussian elimination

// Consider a system of linear equations
// x1*a[1][1] + x2*a[1][2] + ... + xn*a[1][n] = 1 (mod 2)
// ...
// x1*a[n][1] + x2*a[n][2] + ... + xn*a[n][n] = 1 (mod 2)
//
// a[i][j] = 1 if valve i can be controlled by technician j, otherwise it's 0
// Now, we'll take i-th technician only if xi = 1
//
// We can solve this system using Gaussian elimination modulo 2

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 250;
typedef bitset<N + 1> vec;

vector<vec> a(N, 0);
int n;

vec gaussianSolve() {
  for (int i = 0; i < n; i++) a[i][n] = 1;
  for (int c = 0; c < n; c++) {
    for (int i = c; i < n; i++) if (a[i][c]) {
      swap(a[i], a[c]);
      break;
    }
    if (a[c][c] == 0) return 0;
    for (int i = 0; i < n; i++) if (i != c && a[i][c]) a[i] ^= a[c];
  }
  vec ans = 0;
  for (int i = 0; i < n; i++) ans[i] = a[i][n] == 1;
  return ans;
}

int main(int argc, char const *argv[])
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    while (true) {
      cin >> t;
      if (t == -1) break;
      a[t - 1][i] = 1;
    }
  }
  vec ans = gaussianSolve();
  if (ans == 0) {
    cout << "No solution";
  } else {
    for (int i = 0; i < n; i++) if (ans[i]) cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
