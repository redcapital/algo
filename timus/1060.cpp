// Uses: breadth-first search

// There are only 2^16 = 65536 states

#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

const int N = 16;
const int WHITE = (1 << N) - 1;
bool f[1 << N] = { 0 };

int main(int argc, char const *argv[])
{
  bitset<N> b, t;
  char c;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      cin >> c;
      b[i * 4 + j] = c == 'w';
    }

  queue< bitset<N> > q;
  q.push(b);
  f[b.to_ulong()] = true;
  int ans = 0;
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      b = q.front();
      q.pop();
      if (b == 0 || b == WHITE) {
        cout << ans << endl;
        return 0;
      }
      for (int i = 0; i < N; i++) {
        t = b;
        t.flip(i);
        if (i % 4 != 3) t.flip(i + 1);
        if (i % 4 != 0) t.flip(i - 1);
        if (i < 12) t.flip(i + 4);
        if (i > 3) t.flip(i - 4);
        if (!f[t.to_ulong()]) {
          f[t.to_ulong()] = true;
          q.push(t);
        }
      }
    }
    ++ans;
  }
  cout << "Impossible" << endl;
  return 0;
}
