#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

const int MAXV = (1 << 11);
const int MAXID = 10000;
const int MAXD = 20;

struct cell {
  int vals[4][2];
  int t, ts, r, rs, b, bs, l, ls;

  cell() {
    memset(vals, 0, sizeof(vals));
    t = 0;
    r = 1;
    b = 2;
    l = 3;
    ts = rs = bs = ls = 0;
  }

  void rotate() {
    int tmp = t, tmps = ts;
    t = l;
    ts = ls ? 0 : 1;

    l = b;
    ls = bs;

    b = r;
    bs = rs ? 0 : 1;

    r = tmp;
    rs = tmps;
  }

  void flipH() {
    swap(l, r);
    swap(ls, rs);
    ts = ts ? 0 : 1;
    bs = bs ? 0 : 1;
  }

  void flipV() {
    swap(t, b);
    swap(ts, bs);
    ls = ls ? 0 : 1;
    rs = rs ? 0 : 1;
  }
};

struct finalized_cell {
  int id, t, r, b, l;

  ll hash() {
    ll tt = ((ll)t << 36) | ((ll)r << 24) | ((ll)b << 12) | l;
    return tt;
  }
};

vector<finalized_cell> all;
vector<int> byleft[MAXV], bytop[MAXV];
bool used[MAXID];
int placed[MAXD][MAXD];
set<ll> seen[MAXID];
int d;

bool place(int r, int c) {
  int nextr = r;
  int nextc = c + 1;
  if (nextc == d) {
    nextc = 0;
    nextr = r + 1;
  }

  if (c > 0) {
    int left = placed[r][c - 1];
    for (auto i: byleft[all[left].r]) {
      if (used[all[i].id]) continue;
      bool ok = true;
      if (r > 0) {
        // Check top too
        int top = placed[r - 1][c];
        ok = (all[top].b == all[i].t);
      }
      if (ok) {
        placed[r][c] = i;
        used[all[i].id] = true;

        if (nextr == d) {
          return true;
        }

        if (place(nextr, nextc)) {
          return true;
        }

        used[all[i].id] = false;
      }
    }
  } else {
    int top = placed[r - 1][c];
    for (auto i: bytop[all[top].b]) {
      if (used[all[i].id]) continue;
      bool ok = true;
      if (c > 0) {
        // Check left too
        int left = placed[r][c - 1];
        ok = (all[left].r == all[i].l);
      }
      if (ok) {
        placed[r][c] = i;
        used[all[i].id] = true;

        if (nextr == d) {
          return true;
        }

        if (place(nextr, nextc)) {
          return true;
        }

        used[all[i].id] = false;
      }
    }
  }
  return false;
}

int main() {
  string s;
  vector<string> buf;
  int id;

  while (getline(cin, s)) {
    if (s.empty()) {
      int d = buf.size();
      cell c;
      for (int i = 0; i < d; i++) {
        if (buf[0][i] == '#') {
          c.vals[0][0] |= (1 << i);
        }
        if (buf[0][d - 1 - i] == '#') {
          c.vals[0][1] |= (1 << i);
        }
        if (buf[d - 1][i] == '#') {
          c.vals[2][0] |= (1 << i);
        }
        if (buf[d - 1][d - 1 - i] == '#') {
          c.vals[2][1] |= (1 << i);
        }
      }
      for (int i = 0; i < d; i++) {
        if (buf[i][0] == '#') {
          c.vals[3][0] |= (1 << i);
        }
        if (buf[d - 1 - i][0] == '#') {
          c.vals[3][1] |= (1 << i);
        }
        if (buf[i][d - 1] == '#') {
          c.vals[1][0] |= (1 << i);
        }
        if (buf[d - 1 - i][d - 1] == '#') {
          c.vals[1][1] |= (1 << i);
        }
      }

      for (int rot = 0; rot < 4; rot++) {
        c.rotate();
        for (int fh = 0; fh < 2; fh++) {
          c.flipH();
          for (int fv = 0; fv < 2; fv++) {
            c.flipV();

            finalized_cell fc;
            fc.id = id;
            fc.t = c.vals[c.t][c.ts];
            fc.r = c.vals[c.r][c.rs];
            fc.b = c.vals[c.b][c.bs];
            fc.l = c.vals[c.l][c.ls];

            ll h = fc.hash();
            if (seen[id].count(h) > 0) {
              continue;
            }
            seen[id].insert(h);

            all.push_back(fc);

            byleft[fc.l].push_back(all.size() - 1);
            bytop[fc.t].push_back(all.size() - 1);
          }
        }
      }
      buf.clear();
    } else if (s[0] == 'T') {
      sscanf(s.c_str(), "Tile %d", &id);
    } else {
      buf.push_back(s);
    }
  }

  // Each cell has 4*2*2 configurations, but half of them are identical
  d = sqrt(all.size() / 8);
  if (d * d * 8 != all.size()) {
    cerr << "Non square data, wtf" << endl;
    return 1;
  }

  memset(used, 0, sizeof(used));

  for (int i = 0; i < all.size(); i++) {
    placed[0][0] = i;
    used[all[i].id] = true;
    if (place(0, 1)) {
      cout << "Placed successfully" << endl;
      ll ans = 
        (ll)all[placed[0][0]].id *
        (ll)all[placed[0][d - 1]].id *
        (ll)all[placed[d - 1][0]].id *
        (ll)all[placed[d - 1][d - 1]].id;
      cout << "ans: " << ans << endl;
      break;
    }
    used[all[i].id] = false;
  }

  return 0;
}
