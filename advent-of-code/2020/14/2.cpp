#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned __int128 ull;

map<long long, long long> mem;
string mask;
long long addr, val;

string tostring(ull val) {
  string res;
  while (val) {
    res += (val % 10) + '0';
    val /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

void writeMem(size_t i = 0) {
  if (i == mask.size()) {
    mem[addr] = val;
    return;
  }
  switch (mask[i]) {
    case '0':
      writeMem(i + 1);
      break;
    case '1':
      addr |= ((long long)1 << (35 - i));
      writeMem(i + 1);
      break;
    case 'X':
      addr |= ((long long)1 << (35 - i));
      writeMem(i + 1);
      addr &= ~((long long)1 << (35 - i));
      writeMem(i + 1);
      break;
  }
}

int main() {
  string s;

  while (getline(cin, s)) {
    if (s[1] == 'a') {
      mask = s.substr(7);
    } else {
      sscanf(s.c_str(), "mem[%lld] = %lld", &addr, &val);
      writeMem();
    }
  }

  ull ans = 0;
  for (auto const& cell : mem) {
    ans += (ull)cell.second;
  }

  cout << tostring(ans) << endl;
  return 0;
}

