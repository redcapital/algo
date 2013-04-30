// Uses: bfs
//
// Make a graph with people as vertices and edges between them if they're
// friends.
//
// Start from some unseen vertex V and add it to set 1. All of its unseen friends
// (i.e.  neighbour vertices) will go to set 2. All of their friends' friends
// go to set 1. All of friends' friends' friends go to set 2 again and so on...
//
// Output any set as an answer.

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, v;
  vector<int> g[101], ans;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    while (true) {
      cin >> v;
      if (!v) break;
      g[i].push_back(v);
    }
  }
  bool used[101] = { 0 };
  list<int> cur;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    used[i] = true;
    cur.push_back(i);
    bool add = true;
    while (!cur.empty()) {
      int sz = cur.size();
      while (sz--) {
        v = cur.front();
        cur.pop_front();
        if (add) ans.push_back(v);
        for (int k = 0; k < g[v].size(); k++) {
          if (used[g[v][k]]) continue;
          used[g[v][k]] = true;
          cur.push_back(g[v][k]);
        }
      }
      add = !add;
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
