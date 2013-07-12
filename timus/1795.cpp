#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct request {
  string good;
  int amount;
  bool again;
};

int main(int argc, char const *argv[])
{
  map<string, int> inv;
  int n, m, amount, ans = 0, i;
  string t;
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> amount >> t >> t;
    inv[t] = amount;
  }
  cin >> n;
  vector<request> q(n);
  for (i = 0; i < n; i++) {
    cin >> q[i].amount >> q[i].good >> q[i].good;
    q[i].again = false;
  }

  i = 0;
  bool last = false;
  while (i < q.size()) {
    if (!last) ++ans;
    int remains = inv[q[i].good];
    if (remains > 0) {
      if (q[i].amount > remains) {
        q[i].again = true;
        q[i].amount = remains;
        if (i < q.size() - 1) {
          swap(q[i], q[i + 1]);
        } else {
          last = true;
        }
      } else {
        inv[q[i].good] -= q[i].amount;
        ++i;
      }
    } else {
      ++i;
    }
  }

  cout << ans << endl;
  return 0;
}
