// Uses: breadth-first search

#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, c = 0, is = -1;
  vector<int> g[300];
  map<string, int> m;
  cin >> n;
  while (n--) {
    int b[3];
    for (int i = 0; i < 3; i++) {
      string t;
      cin >> t;
      if (!m.count(t)) {
        m[t] = c++;
      }
      b[i] = m[t];
      if (is < 0 && t == "Isenbaev") is = b[i];
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          g[b[i]].push_back(b[j]);
          g[b[j]].push_back(b[i]);
        }
      }
    }
  }

  int dist[300] = { 0 };

  if (is >= 0) {
    queue<int> q;
    q.push(is);
    for (int curdist = 1; !q.empty(); curdist++) {
      for (int sz = q.size(); sz; sz--) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
          if (g[v][i] != is && !dist[g[v][i]]) {
            dist[g[v][i]] = curdist;
            q.push(g[v][i]);
          }
        }
      }
    }
  }

  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " ";
    if (it->second == is) cout << 0;
    else if (!dist[it->second]) cout << "undefined";
    else cout << dist[it->second];
    cout << endl;
  }
  return 0;
}
