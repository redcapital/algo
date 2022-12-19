#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  list<int> m;
  string s;
  cin >> s;
  int minx = 0, maxx = 0;
  for (auto c: s) {
    int v = (int)(c - '0');
    m.push_back(v);
    minx = min(minx, v);
    maxx = max(maxx, v);
  }
  auto cur = m.begin();
  int rem[3];
  for (int moves = 1; moves <= 100; moves++) {
    auto it = cur;
    it++;
    for (int i = 0; i < 3; i++) {
      if (it == m.end()) {
        it = m.begin();
      }
      rem[i] = *it;
      it = m.erase(it);
    }
    
    int desv = *cur;
    while (true) {
      desv--;
      if (desv == minx) {
        desv = maxx;
      } else if (desv == *cur) {
        desv--;
      }
      it = find(m.begin(), m.end(), desv);
      if (it != m.end()) {
        break;
      }
    }
    for (int i = 0; i < 3; i++) {
      it++;
      it = m.insert(it, rem[i]);
    }
    cur++;
    if (cur == m.end()) {
      cur = m.begin();
    }
  }
  
  auto it1 = find(m.begin(), m.end(), 1);
  auto it = it1;
  while (true) {
    it++;
    if (it == it1) {
      break;
    } else if (it == m.end()) {
      it = m.begin();
    }
    cout << *it;
  }
  
  return 0;
}
