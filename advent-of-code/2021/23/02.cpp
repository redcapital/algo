#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<(s)<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

typedef long long ll;
typedef unsigned long long ull;

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};

const int col_pos[4] = { 2, 4, 6, 8 };
const char correct[4] = { 'A', 'B', 'C', 'D' };
const int cost[4] = { 1, 10, 100, 1000 };
int col_size;

struct State {
  vector<char> cols[4];
  char hall[11];

  void print(int indent) {
    FOR(i, indent * 2) cout << " ";
    FOR(i, 11) {
      cout << hall[i];
    }
    cout << endl;
    FOR(j, col_size) {
      FOR(i, indent * 2) cout << " ";
      cout << "##";
      FOR(i, 4) {
        cout << cols[i][j] << "#";
      }
      cout << "#" << endl;
    }
  }

  bool operator<(const State& b) const {
    FOR(i, 11) {
      if (hall[i] < b.hall[i]) return true;
      if (hall[i] > b.hall[i]) return false;
    }
    FOR(i, 4) {
      if (cols[i] < b.cols[i]) return true;
      if (cols[i] > b.cols[i]) return false;
    }
    return false;
  };

};

map<State, int> cached;

int rec(const State& s, int score, int depth) {
  auto it = cached.find(s);
  if (it != cached.end()) {
    return it->second;
  }

  int filled[4];
  bool is_correct[4];
  FOR(i, 4) {
    filled[i] = 0;
    is_correct[i] = true;
    FOR(j, col_size) {
      if (s.cols[i][j] != '.') {
        filled[i]++;
      }
      is_correct[i] = is_correct[i] && (s.cols[i][j] == '.' || s.cols[i][j] == correct[i]);
    }
  }

  bool done = true;
  FOR(i, 4) {
    if (!is_correct[i] || filled[i] != col_size) {
      done = false;
      break;
    }
  }
  if (done) {
    return cached[s] = score;
  }

  int result = 999999999;

  // Move from hall to a column
  FOR(i, 4) {
    if (filled[i] < col_size && is_correct[i]) {
      int next_pos = col_size - filled[i] - 1;
      assert(s.cols[i][next_pos] == '.');
      for (int sign = -1; sign < 2; sign += 2) {
        for (int step = 1; ; step++) {
          int p = col_pos[i] + sign * step;
          if (p < 0 || p > 10) break;
          if (s.hall[p] == '.') continue;
          if (s.hall[p] == correct[i]) {
            State n(s);
            n.hall[p] = '.';
            n.cols[i][next_pos] = correct[i];
            int tmp_result = rec(n, score + (step + next_pos + 1) * cost[i], depth + 1);
            result = min(result, tmp_result);
          }
          // Stop after moving first element
          break;
        }
      }
    }
  }

  // Move from a column to hall
  FOR(i, 4) {
    if (!is_correct[i]) {
      FOR(j, col_size) {
        if (s.cols[i][j] != '.') {
          for (int sign = -1; sign < 2; sign += 2) {
            for (int step = 1; ; step++) {
              int p = col_pos[i] + sign * step;
              if (p < 0 || p > 10) break;
              if (p == 2 || p == 4 || p == 6 || p == 8) continue;
              // Stop after encountering first non-empty spot.
              if (s.hall[p] != '.') break;

              State n(s);

              n.hall[p] = s.cols[i][j];
              n.cols[i][j] = '.';
              int tmp_result = rec(n, score + (step + j + 1) * cost[i], depth + 1);
              result = min(result, tmp_result);
            }
          }
          // Stop after moving first element
          break;
        }
      }
    }
  }

  return cached[s] = result;
}

int main() {
  string s;
  State start;
  while (getline(cin, s)) {
    if (s[3] >= 'A' && s[3] <= 'D') {
      FOR(i, 4) {
        start.cols[i].push_back(s[1 + col_pos[i]]);
      }
    }
  }
  FOR(i, 11) start.hall[i] = '.';
  col_size = start.cols[0].size();
  PRINTL(rec(start, 0, 0));
  return 0;
}

