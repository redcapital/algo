#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned __int128 ull;

string tostring(ull val) {
  string res;
  while (val) {
    res += (val % 10) + '0';
    val /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

ull mem[1000000];

int main() {
  ull m_and, m_or;
  string s;
  for (int i = 0; i < 1000000; i++) mem[i] = 0;

  while (getline(cin, s)) {
    if (s[1] == 'a') {
      m_and = 0;
      m_or = 0;
      for (int i = 7, bit = 35; i < s.size(); i++, bit--) {
        if (s[i] == '1') {
          m_or |= ((ull)1 << bit);
        } else if (s[i] == '0') {
          m_and |= ((ull)1 << bit);
        }
      }
      m_and = ~m_and;
    } else {
      int addr, val;
      sscanf(s.c_str(), "mem[%d] = %d", &addr, &val);
      if (addr >= 1000000) {
        cerr << "large address" << addr << endl;
        return 1;
      }
      mem[addr] = ((ull)val & m_and) | m_or;
    }
  }

  ull ans = 0;
  for (auto const& cell : mem) {
    ans += cell;
  }

  cout << tostring(ans) << endl;
  // 3163133243 is too low
  // 1244408681787 is too low
  return 0;
}

