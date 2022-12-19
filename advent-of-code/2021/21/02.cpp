#include <iostream>
#include <map>
#include <queue>
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

struct gstate {
  int i;
  map<int, long long> num[10];
};

typedef unsigned long long ull;

ull cnts[10];

bool cached[11][11][40][40];
pair<ull,ull> cache[11][11][40][40];

pair<ull,ull> wins(int p1, int p2, int s1, int s2) {
  if (cached[p1][p2][s1][s2]) {
    return cache[p1][p2][s1][s2];
  }
  pair<ull,ull> res(0, 0);
  if (s1 > 20) {
    res = make_pair(1, 0);
  } else if (s2 > 20) {
    res = make_pair(0, 1);
  } else {
    FOSE(dicet,3,9) {
      int tpos = (p1 + dicet) % 10;
      ull tscore = s1 + tpos + 1;
      auto subwins = wins(p2, tpos, s2, tscore);
      res.first += subwins.second * cnts[dicet];
      res.second += subwins.first * cnts[dicet];
    }
  }
  cached[p1][p2][s1][s2] = true;
  cache[p1][p2][s1][s2] = res;
  return res;
}

int main() {
  int p[2];
  scanf("Player 1 starting position: %d\n", p);
  scanf("Player 2 starting position: %d", p + 1);

  CLEAR(cnts);
  CLEAR(cached);
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      for (int k = 1; k < 4; k++) {
      //cout << i << " + " << j << " + " << k << " = " << i + j + k << endl;
        cnts[i+j+k]++;
      }
    }
  }

    //FOSE(dicet,3,9) {
      //cout << dicet << "," << cnts[dicet] << " ";
    //}
    //cout<<endl;

  auto res = wins(p[0] - 1, p[1] - 1, 0, 0);

  //3 cnt = 1
  //4 cnt = 3
  //5 cnt = 6
  //6 cnt = 7
  //7 cnt = 6
  //8 cnt = 3
  //9 cnt = 1

  PRINTL((res.first > res.second ? res.first : res.second));

  //cout <<  ((univ[0] > univ[1]) ? univ[0] : univ[1]) << endl;

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
