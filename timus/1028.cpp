// Uses: interval tree

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 32001;

class IntervalTree {
  int t[MAXN * 4];

  public:
    IntervalTree() {
      memset(t, 0, sizeof(t));
    }

    int sum(int l, int r) {
      return sum(1, 0, MAXN - 1, l, r);
    }

    void increment(int pos) {
      increment(1, 0, MAXN - 1, pos);
    }


  private:
    int sum(int v, int tl, int tr, int l, int r) {
      if (v < 0) return 0;
      if (l > r) return 0;
      if (l == tl && r == tr) return t[v];
      int tm = (tl + tr) / 2;
      return sum(v * 2, tl, tm, l, min(r, tm))
        + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void increment(int v, int tl, int tr, int pos) {
      if (tl == tr) {
        t[v] += 1;
      } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
          increment(v * 2, tl, tm, pos);
        } else {
          increment(v * 2 + 1, tm + 1, tr, pos);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
      }
    }
};

int main(int argc, char const *argv[])
{
  IntervalTree tree;
  int n;
  cin >> n;
  int i, x, y, levels[15000] = { 0 };
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    levels[tree.sum(0, x)]++;
    tree.increment(x);
  }
  for (i = 0; i < n; i++) {
    cout << levels[i] << endl;
  }
  return 0;
}
