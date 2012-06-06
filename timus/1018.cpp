// Uses: dfs, dynamic programming

// Use DFS to construct the tree. Store left and right edges for each node
// Then use dynamic programming (function getMax below)

#include <iostream>
#include <stack>

using namespace std;

class Node {
  public:
  int lw, li, rw, ri;
  Node() {
    li = ri = 0;
  }
} a[101];
int f[101][101] = { 0 }, cache[101][101];
bool u[101] = { 0 }, cached[101][101] = { 0 };

// Returns maximum amount of apples when starting from node 's' and using 'edges'
// edges
int getMax(int s, int edges) {
  if (!cached[s][edges]) {
    cached[s][edges] = true;
    if ((edges == 0) || (!a[s].ri && a[s].li)) {
      cache[s][edges] = 0;
    } else if (a[s].li == 0) {
      cache[s][edges] = a[s].rw + getMax(a[s].ri, edges - 1);
    } else if (a[s].ri == 0) {
      cache[s][edges] = a[s].lw + getMax(a[s].li, edges - 1);
    } else {
      int ans = 0;
      for (int e = 0; e <= edges; e++) {
        int leftWeight = e ? a[s].lw + getMax(a[s].li, e - 1) : 0;
        int rightWeight = e < edges ? a[s].rw + getMax(a[s].ri, edges - e - 1) : 0;
        ans = max(ans, leftWeight + rightWeight);
      }
      cache[s][edges] = ans;
    }
  }
  return cache[s][edges];
}

int main(int argc, char const *argv[])
{
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    f[s][e] = f[e][s] = w;
  }
  // Construct the tree (recursive DFS would be just fine)
  stack<int> s;
  s.push(1);
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    u[cur] = true;
    for (int i = 1; i < 101; i++) {
      if (f[cur][i] && !u[i]) {
        if (a[cur].li == 0) {
          a[cur].li = i;
          a[cur].lw = f[cur][i];
        } else {
          a[cur].ri = i;
          a[cur].rw = f[cur][i];
        }
        s.push(i);
      }
    }
  }
  cout << getMax(1, q) << endl;
  return 0;
}

