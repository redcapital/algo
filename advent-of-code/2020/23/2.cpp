#include <iostream>
#include <string>

using namespace std;

const int TOTAL_CUPS = 1000000;
const int MIN_LABEL = 1;
const int MAX_LABEL = TOTAL_CUPS;
const int MOVES = 10000000;

int nxt[TOTAL_CUPS + 1];

int main() {
  string s;
  cin >> s;
  int first = 0, last = 0, maxx = 0;
  for (auto c: s) {
    int v = (int)(c - '0');
    if (!first) first = v;
    if (v > maxx) maxx = v;
    if (last) nxt[last] = v;
    last = v;
  }
  for (int v = maxx + 1; v <= TOTAL_CUPS; v++) {
    nxt[last] = v;
    last = v;
  }
  nxt[last] = first;
  
  int cur = first;
  int rem[3];
  for (int moves = 1; moves <= MOVES; moves++) {
    int p = cur;
    for (int i = 0; i < 3; i++) {
      p = nxt[p];
      rem[i] = p;
    }
    nxt[cur] = nxt[rem[2]];
    int dest = cur;
    while (rem[0] == dest || rem[1] == dest || rem[2] == dest || dest == cur) {
      dest--;
      if (dest < MIN_LABEL) dest = MAX_LABEL;
    }
    int after_dest = nxt[dest];
    nxt[dest] = rem[0];
    nxt[rem[2]] = after_dest;
    
    cur = nxt[cur];
  }
  
  cout << nxt[1] << " x " << nxt[nxt[1]] << " = " << ((long long)nxt[1] * (long long)nxt[nxt[1]]) << endl;
  return 0;
}
