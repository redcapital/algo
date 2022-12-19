#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>

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
  int rot, fh, fv;
  vector<string> img;

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
vector<string> imgs[MAXD][MAXD];
bool monster[MAXD * 11][MAXD * 11];
vector<string> p;


vector<string> rotatevs(const vector<string>& vs) {
  int d = vs.size();
  vector<string> res(d);

  for (int i = 0; i < d; i++) res[i] = vs[i];

  for (int r = 0; r < d; r++) {
    for (int i = 0, j = d - 1; j >= 0; j--, i++) {
      res[r][i] = vs[j][r];
    }
  }
  return res;
}

vector<string> fliphvs(const vector<string>& vs) {
  int d = vs.size();
  vector<string> res(d);
  for (int i = 0; i < d; i++) {
    res[i] = vs[i];
    reverse(res[i].begin(), res[i].end());
  }
  return res;
}

vector<string> flipvvs(const vector<string>& vs) {
  int d = vs.size();
  vector<string> res(d);
  for (int i = 0; i < d; i++) {
    res[d - 1 - i] = vs[i];
  }
  return res;
}

vector<string> remove_borders(const vector<string>& vs) {
  int d = vs.size();
  vector<string> res(d - 2);
  for (int i = 1; i < d - 1; i++) {
    res[i - 1] = vs[i].substr(1, vs[i].size() - 2);
  }
  return res;
}

void searchmonster(const vector<string>& vs) {
  int rows = vs.size(), cols = vs[0].size();
  for (int r = 0; r < rows - p.size(); r++) {
    for (int c = 0; c < cols - p[0].size(); c++) {
      bool ok = true;
      for (int pr = 0; pr < p.size() && ok; pr++) {
        for (int pc = 0; pc < p[0].size() && ok; pc++) {
          if (p[pr][pc] == ' ') continue;
          ok = (p[pr][pc] == vs[r + pr][c + pc]);
        }
      }
      if (ok) {
        for (int pr = 0; pr < p.size() && ok; pr++) {
          for (int pc = 0; pc < p[0].size() && ok; pc++) {
            if (p[pr][pc] == '#') monster[r + pr][c + pc] = true;
          }
        }
      }
    }
  }
}


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
  p.push_back("                  # ");
  p.push_back("#    ##    ##    ###");
  p.push_back(" #  #  #  #  #  #   ");

  while (getline(cin, s)) {
    if (s.empty()) {
      int cellsize = buf.size();
      cell c;
      for (int i = 0; i < cellsize; i++) {
        if (buf[0][i] == '#') {
          c.vals[0][0] |= (1 << i);
        }
        if (buf[0][cellsize - 1 - i] == '#') {
          c.vals[0][1] |= (1 << i);
        }
        if (buf[cellsize - 1][i] == '#') {
          c.vals[2][0] |= (1 << i);
        }
        if (buf[cellsize - 1][cellsize - 1 - i] == '#') {
          c.vals[2][1] |= (1 << i);
        }
      }
      for (int i = 0; i < cellsize; i++) {
        if (buf[i][0] == '#') {
          c.vals[3][0] |= (1 << i);
        }
        if (buf[cellsize - 1 - i][0] == '#') {
          c.vals[3][1] |= (1 << i);
        }
        if (buf[i][cellsize - 1] == '#') {
          c.vals[1][0] |= (1 << i);
        }
        if (buf[cellsize - 1 - i][cellsize - 1] == '#') {
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
            fc.img = buf;
            fc.rot = rot;
            fc.fh = fh;
            fc.fv = fv;
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
      break;
    }
    used[all[i].id] = false;
  }

  for (int r = 0; r < d; r++) {
    for (int c = 0; c < d; c++) {
      int idx = placed[r][c];
      vector<string> cimg = all[idx].img;
      for (int count = all[idx].rot; count >= 0; count--) {
        cimg = rotatevs(cimg);
      }
      if (all[idx].fh == 0) cimg = fliphvs(cimg);
      if (all[idx].fv == 0) cimg = flipvvs(cimg);

      imgs[r][c] = remove_borders(cimg);
    }
  }

  vector<string> img;
  int imgsd = imgs[0][0].size();
  int cc = 0;
  for (int line = 0; line < d * imgsd; line++) {
    string t;
    int r = line / imgsd;
    for (int c = 0; c < d; c++) {
      t += imgs[r][c][line % imgsd];
    }
    img.push_back(t);
    cc++;
  }
  
  for (int rot = 0; rot < 4; rot++) {
    img = rotatevs(img);
    for (int fh = 0; fh < 2; fh++) {
      img = fliphvs(img);
      for (int fv = 0; fv < 2; fv++) {
        img = flipvvs(img);
        memset(monster, 0, sizeof(monster));
        searchmonster(img);
        
        int total = 0, m = 0;
        for (int r = 0; r < img.size(); r++) {
          for (int c = 0; c < img[r].size(); c++) {
            if (img[r][c] == '#') {
              total++;
              if (monster[r][c]) m++;
            }
          }
        }

        if (m) {
          cout << "monster count: " << m << ", non-monster: " << total - m << endl;
        }
      }
    }
  }

  return 0;
}
