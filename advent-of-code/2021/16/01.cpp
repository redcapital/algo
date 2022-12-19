#include <iostream>
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

typedef unsigned long long ull;

struct packet {
  ull version;
  ull tid;
  ull val;
  int sindex;
  vector<packet> subs;
};

ull tonum(const string& s) {
  ull res=0;
  ull bit=((ull)1 << (s.size() - 1));
  FOR(i,s.size()) {
    if (s[i]=='1') res |= bit;
    bit >>= 1;
  }
  return res;
}

packet readpackets(const string& s, int start) {
  packet res;
  int i = start;

  res.version = tonum(s.substr(i, 3));
  i+=3;
  res.tid = tonum(s.substr(i, 3));
  i+=3;

  //cerr << res.version << " " << res.tid << endl;
  //return res;

  if (res.tid == 4) {
    string num;
    while (true) {
      string group = s.substr(i, 5);
      num += group.substr(1);
      i += 5;
      if (group[0] == '0') break;
    }
    res.val = tonum(num);
  } else {
    char lbit = s[i];
    packet subp;
    i += 1;
    if (lbit == '0') {
      ull bitlen = tonum(s.substr(i, 15));
      i += 15;
      string sub = s.substr(i, bitlen);
      i += bitlen;
      int subi = 0;
      while (subi < sub.size()) {
        subp = readpackets(sub, subi);
        res.subs.push_back(subp);
        subi = subp.sindex;
      }
    } else {
      ull subpacket_num = tonum(s.substr(i, 11));
      i += 11;
      FOR(j,subpacket_num) {
        subp = readpackets(s, i);
        res.subs.push_back(subp);
        i = subp.sindex;
      }
    }
  }
  res.sindex = i;
  return res;
}

ull sumversion(const packet& p) {
  ull ans = p.version;
  for (auto x: p.subs) {
    ans += sumversion(x);
  }
  return ans;
}

ull ev(const packet& p) {
  ull ans;
  switch (p.tid) {
    case 0:
      ans = 0;
      for (auto x: p.subs) {
        ans += ev(x);
      }
      break;
    case 1:
      ans = 1;
      for (auto x: p.subs) {
        ans *= ev(x);
      }
      break;
    case 2:
      ans = min(ev(p.subs[0]), ev(p.subs[1]));
      break;
    case 3:
      ans = max(ev(p.subs[0]), ev(p.subs[1]));
      break;
    case 5:
      ans = ev(p.subs[0]) > ev(p.subs[1]) ? 1 : 0;
      break;
    case 6:
      ans = ev(p.subs[0]) < ev(p.subs[1]) ? 1 : 0;
      break;
    case 7:
      ans = (ev(p.subs[0]) == ev(p.subs[1])) ? 1 : 0;
      break;
  }
  return ans;
}

int main() {
  string s;
  packet res;
  cin >> s;
  string bins;
  FOR(i,s.size()) {
    switch (s[i]) {
      case '0' : bins += "0000"; break;
      case '1' : bins += "0001"; break;
      case '2' : bins += "0010"; break;
      case '3' : bins += "0011"; break;
      case '4' : bins += "0100"; break;
      case '5' : bins += "0101"; break;
      case '6' : bins += "0110"; break;
      case '7' : bins += "0111"; break;
      case '8' : bins += "1000"; break;
      case '9' : bins += "1001"; break;
      case 'A' : bins += "1010"; break;
      case 'B' : bins += "1011"; break;
      case 'C' : bins += "1100"; break;
      case 'D' : bins += "1101"; break;
      case 'E' : bins += "1110"; break;
      case 'F' : bins += "1111"; break;
    }
  }
  cout << bins << endl;
  int slen = bins.size(), i = 0;
  while (i < slen) {
    res = readpackets(bins, i);
    i = res.sindex;
    ans += sumversion(res);
    break;
  }


  PRINTL(ev(res));
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
