#include <iostream>
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


/*
stack num 0 1 2 3

st dep
0
1
2
3
*/

long long ans = -1, curans=0;
map<ull, bool> seen;
char cor[4] = {'A','B','C','D'};
int hpos[4] = {2, 4, 6, 8};
int cost[4] = {1, 10, 100, 1000};
string h(11, '.');
int stlen;
string st[4];


bool ver(bool movin=false) {
  int cnt=0;
  FOR(i,11) if (h[i]!='.') cnt++;
  FOR(i,4) FOR(j,4) if (st[i][j]!='.') cnt++;
  if (cnt == 16) return true;
  if (movin) {
    cout << "bad count after movin " << endl;
  } else {
    cout << "bad count after moveout " << endl;
  }
  return false;
}

void printst() {
  return;
  cout << "#" << h << "#" << endl;
  FOR(i,4) {
    string tt;
    FOR(j,4) {
      tt += st[j][i];
      tt += "#";
    }
    cout << "  #" << tt << "##" << endl;
  }
  cout << endl;
}

ull digit(char c) {
  switch (c) {
    case '.':
      return 0;
    case 'A':
      return 1;
    case 'B':
      return 2;
    case 'C':
      return 3;
    case 'D':
      return 4;
  }
  exit(1);
}

void rec() {
  //string key(h);
  //key += '$';
  //key += st;
  //auto seen_ans = seen[key];
  //if (seen_ans && seen_ans >= curans) {
    //return;
    //cout << "seen this shit " << endl;
    //cout << "#" << h << "#" << endl;
    //FOR(i,4) {
      //string tt;
      //FOR(j,4) {
        //tt += st[j*4+i];
        //tt += "#";
      //}
      //cout << "  #" << tt << "##" << endl;
    //}
    //return;
  //}
  //seen[key] = curans;
  //cout << rcc++<<endl;
  //printst();
  //ull key = 0;
  //ull base = 1;
  //FOR(i,11) {
    //key += base * digit(h[i]);
    //base *= 5;
  //}
  //FOR(i,4) FOR(j,4) {
    //key += base * digit(st[i][j]);
    //base *= 5;
  //}
  //auto seen_ans = seen[key];
  //if (!seen_ans) {
    //seen[key] = curans;
  //} else if (curans < seen_ans) {
    //seen[key] = curans;
  //} else {
    //return;
  //}
  bool alldone = true;
  FOR(i,4) {
    bool same=true;
    int cap = 0;
    FOR(j, 4) {
      if (st[i][j]!='.') {
        cap++;
        if (st[i][j] != cor[i]) {
          same=false;
        }
      }
    }
    if (cap != 4 || !same) {
      alldone=false;
    }
    if (cap && !same) {
      //cout << "try to move out top from col " << i << endl;
      // try move out top
      //cout << "try move out " << endl;
      //cout << h << endl;
      //cout << st << endl;
      FOR(j,4) {
        if (st[i][j] != '.') {
          char t = st[i][j];
          for (int sign = -1; sign <= 1; sign += 2) {
            for (int c = 1; ; c++) {
              int p = hpos[i] + c * sign;
              if (p < 0 || p > 10) break;
              if (h[p] != '.') break;
              if (p == 2 || p == 4 || p == 6 || p == 8) continue;

              h[p] = t;
              st[i][j] = '.';
              //if (!ver()) {
                //printst();
                //exit(0);
              //}
              curans += cost[i] * (j + 1 + c);
              rec();
              h[p] = '.';
              st[i][j] = t;
              curans -= cost[i] * (j + 1 + c);
            }
          }
          break;
        }
      }
    }

    // try move in from hall
    if (cap < 4 && same) {
      //cout << "try move in " << endl;
      //cout << h << endl;
      //cout << st << endl;
      for (int sign = -1; sign <= 1; sign += 2) {
        for (int c = 1; ; c++) {
          int p = hpos[i] + c * sign;
          if (p < 0 || p > 10) break;
          if (h[p] != '.' && h[p] != cor[i]) break;
          if (h[p] == '.') continue;

          h[p] = '.';
          st[i][3 - cap] = cor[i];
          curans += cost[i] * (4 - cap + c);
          //if (!ver(true)) {
            //cout << "Moved in " << cor[i] << " from " << p << endl;
            //cout << h << endl;
            //cout << cap << " " << same << endl;
            //printst();
            //exit(0);
          //}
          rec();
          h[p] = cor[i];
          st[i][3 - cap] = '.';
          curans -= cost[i] * (4 - cap + c);
        }
      }
    }
  }
  if (alldone) {
    //cout << "alldone " << st << endl;
    if (ans < 0) {
      cout << "found " << curans << endl;
      ans = curans;
    } else {
      if (curans < ans) {
        cout << "found " << curans << endl;
        ans = curans;
      }
    }
  }
}

int main() {
  string s;

  while (getline(cin, s)) {
    if (s[3] >= 'A' && s[3] <= 'D') {
      st[0] += s[3];
      st[1] += s[5];
      st[2] += s[7];
      st[3] += s[9];
      stlen++;
    }
  }

  FOR(i,4) {
    FOR(j,4) {
      cout << st[j][i] << " ";
    }
    cout << endl;
  }

  rec();

  PRINTL(ans);
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
