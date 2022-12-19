#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

const int MAX_ALLERGENS = 16;
const int MAX_INGREDIENTS = 256;
const int MAX_FOODS = 100;

vector<string> algs, ings;
map<string, int> ingids, algids;
bitset<MAX_INGREDIENTS> bs[MAX_ALLERGENS];
bitset<MAX_INGREDIENTS> foods[MAX_FOODS];

static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
    return !std::isspace(ch);
  }));
}

vector<string> split(const string& s, char delim) {
  int p = 0;
  vector<string> res;
  while (true) {
    int np = s.find(delim, p);
    if (np == string::npos) {
      string buf(s.substr(p));
      ltrim(buf);
      res.push_back(buf);
      break;
    } else {
      string buf(s.substr(p, np - p));
      ltrim(buf);
      res.push_back(buf);
      p = np + 1;
    }
  }
  return res;
}

int main() {
  string s;
  int fc = 0;
  while (getline(cin, s)) {
    bitset<MAX_INGREDIENTS> b;
    auto p = s.find(" (contains ");
    vector<string> v = split(s.substr(0, p), ' ');
    for (const auto &ing: v) {
      int ingid;
      if (ingids.count(ing) == 0) {
        ings.push_back(ing);
        ingids[ing] = ingid = ings.size() - 1;
      } else {
        ingid = ingids[ing];
      }
      b.set(ingid);
    }
    foods[fc] = b;
    p += 11;
    v = split(s.substr(p, s.size() - p - 1), ',');
    for (const auto &alg: v) {
      if (algids.count(alg) == 0) {
        algs.push_back(alg);
        algids[alg] = algs.size() - 1;
        bs[algs.size() - 1] = b;
      } else {
        bs[algids[alg]] &= b;
      }
    }
    fc++;
  }

  int ans = 0;
  for (int i = 0; i < ings.size(); i++) {
    bool ok = true;
    for (int j = 0; j < algs.size(); j++) {
      if (bs[j].test(i)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (int j = 0; j < fc; j++) {
        if (foods[j].test(i)) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
