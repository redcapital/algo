#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<s<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};

int ans = 0;

int main() {
  string s;
  string temp;
  map<string, char> rules;
  map<string, long long> cnt[2];
  map<char, long long> pcnt;
  while (getline(cin, s)) {
    if (s.size() == 0) continue;
    if (temp.size() == 0) {
      temp = s;
      continue;
    }
    stringstream ss(s);
    string pair;
    char c;
    string bb;
    ss >> pair >> bb >> c;
    rules[pair] = c;
    //cout << pair << " " << c << endl;
  }
  FOR(i,temp.size()-1) {
    cnt[0][temp.substr(i,2)]++;
  }
  FOR(i,temp.size()) {
    pcnt[temp[i]]++;
  }
  int cur = 0;
  FOR(i,40) {
    int nc = (cur + 1) % 2;
    cnt[nc].clear();
    for (auto it : cnt[cur]) {
      auto rit = rules.find(it.first);
      if (rit == rules.end()) {
        cnt[nc][it.first] += it.second;
      } else {
        string s;
        s += it.first[0];
        s += rit->second;
        cnt[nc][s] += it.second;

        s.clear();
        s += rit->second;
        s += it.first[1];
        cnt[nc][s] += it.second;

        pcnt[rit->second] += it.second;
      }
    }
    cur = nc;
  }
  //auto [mn, mx] = minmax_element(ALL(pcnt));
  auto mn = min_element(ALL(pcnt), [](auto &a, auto &b) { return a.second < b.second; });
  auto mx = max_element(ALL(pcnt), [](auto &a, auto &b) { return a.second < b.second; });
  PRINTL(mx->second - mn->second);
  //PRINTL(ans);
  return 0;
}

/*

// comma separated
int x;
vector<int> a;
while (cin >> x) {
  a.push_back(x);
  if (cin.peek() == ',') cin.ignore();
}

// line by line
string s;
while (getline(cin, s)) {

}
*/
