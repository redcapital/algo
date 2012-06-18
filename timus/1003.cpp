// Uses: disjoint set union

// Let a[n] be the array of bits
// Suppose a[k] = sum(a[i]) % 2, 1 <= i <= k, i.e. sum of first k
// bits modulo 2
// Initially a[0] = 0
//
// If sum of subsequence [l, r] is even then a[l - 1] = a[r]
// Likewise, if sum of subsequence [l, r] is odd then a[l - 1] != a[r]
//
// The idea of using DSU is that a[k] and !a[k] should always be in
// different sets (because they have different values). I've used
// k and -k as vertex numbers. For k = 0, we take some special value
// which is very big.
//
// For a statement when [l, r] is said to be even we combine
// vertices (l - 1) and r into one set, -(l - 1) and -r into another.
// When [l, r] is odd we combine -(l - 1) and r into one set and
// (l - 1) and -r into another.
// After each statement we must check whether vertices -(l - 1)
// and (l - 1) or -r and r belong to one set. If so, we stop and
// output number of the statement.

#include <iostream>
#include <map>
#include <string>

// Fake zero
const int Z = 1000000001;

using namespace std;


// Disjoint set union

map<int, int> parent;

void make_set(int v) {
  if (parent.count(v) == 0) {
    parent[v] = v;
  }
}

int find_set(int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    parent[b] = a;
  }
}

int main()
{
  int n, qc, l, r;
  string oe;
  do {
    cin >> n;
    if (n == -1) break;
    parent.clear();
    cin >> qc;
    int ans = -1;
    for (int i = 0; i < qc; i++) {
      cin >> l >> r >> oe;
      if (ans != -1) continue;
      if (l < 1) l = 1;
      if (r > n) r = n;
      l -= 1;
      if (l == 0) l = Z;
      make_set(r);
      make_set(-r);
      make_set(l);
      make_set(-l);
      if (oe == "even") {
        union_sets(l, r);
        union_sets(-l, -r);
      } else {
        union_sets(-l, r);
        union_sets(l, -r);
      }

      if (find_set(l) == find_set(-l) || find_set(r) == find_set(-r)) {
        ans = i;
      }
    }
    if (ans == -1) ans = qc;
    cout << ans <<endl;
  } while (true);
  return 0;
}

