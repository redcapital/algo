#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct rule {
  char literal = 0;
  vector<int> ids;
};
typedef vector<rule> ruleset;

ruleset grammar[1000];

vector<int> match(const string& s, int id, int pos);
vector<int> match_rule(const string& s, const rule& r, int pos);

vector<int> match(const string& s, int id, int pos) {
  vector<int> res;
  if (pos >= s.size()) {
    return res;
  }
  for (const auto& r: grammar[id]) {
    auto m = match_rule(s, r, pos);
    res.insert(res.end(), m.begin(), m.end());
  }
  return res;
}

vector<int> match_rule(const string& s, const rule& r, int pos) {
  vector<int> res;
  if (r.literal) {
    if (s[pos] == r.literal) {
      res.push_back(pos + 1);
    }
    return res;
  }

  auto m1 = match(s, r.ids[0], pos);

  if (r.ids.size() == 1) {
    return m1;
  }
  for (auto mpos: m1) {
    auto m2 = match(s, r.ids[1], mpos);
    res.insert(res.end(), m2.begin(), m2.end());
  }

  if (r.ids.size() == 2) {
    return res;
  }

  vector<int> res2;

  for (auto mpos: res) {
    auto m2 = match(s, r.ids[2], mpos);
    res2.insert(res2.end(), m2.begin(), m2.end());
  }

  return res2;
}

bool check(const string& s) {
  auto m = match(s, 0, 0);
  for (auto i: m) if (i == s.size()) return true;
  return false;
}

vector<string> split(const string& delimiter, const string& subject) {
  vector<string> res;
  int p = 0;
  while (true) {
    int p2 = subject.find(delimiter, p);
    if (p2 != string::npos) {
      res.push_back(subject.substr(p, p2 - p));
      p = p2 + delimiter.size();
    } else {
      res.push_back(subject.substr(p));
      break;
    }
  }
  return res;
}

int main() {
  int ans = 0;
  string s;
  while (getline(cin, s)) {
    if (s.empty()) continue;
    if (s.find(':') == string::npos) {
      if (check(s)) {
        ans++;
      }
    } else {
      ruleset rs;
      auto parts = split(": ", s);
      int id = stoi(parts[0]);
      if (parts[1][0] == '"') {
        rule r;
        r.literal = parts[1][1];
        rs.push_back(r);
      } else {
        parts = split(" | ", parts[1]);
        for (const auto &p: parts) {
          rule r;
          auto nums = split(" ", p);
          for (const auto &n: nums) {
            r.ids.push_back(stoi(n));
          }
          rs.push_back(r);
        }
      }
      grammar[id] = rs;
    }
  }

  cout << ans << endl;
	return 0;
}
