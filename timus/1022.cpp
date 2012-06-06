// Uses: topological sorting

// The problem basically asks you to perform topological sorting

#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> g[101], ans;
bool u[101] = { 0 };

void dfs(int v) {
  u[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    if (!u[g[v][i]]) {
      dfs(g[v][i]);
    }
  }
  ans.push_back(v);
}

void topologicalSort() {
  for (int i = 1; i <= n; i++) if (!u[i]) dfs(i);
}

int main(int argc, char const *argv[])
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    while (t) {
      g[i].push_back(t);
      cin >> t;
    }
  }
  topologicalSort();
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
