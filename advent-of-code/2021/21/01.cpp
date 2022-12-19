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

int main() {
  int p[2];
  scanf("Player 1 starting position: %d\n", p);
  scanf("Player 1 starting position: %d", p + 1);

  p[0] = 4;
  p[1] = 5;

  cout << p[0] << " " << p[1] << endl;

  long long sc[2] = {0,0};
  long long dice = 1;
  long long rolls = 0;
  long long i = 0;

  int vv = 10;
  while (true) {
    long long t = dice;
    dice++; rolls++;
    if (dice > 100) dice = 1;
    t += dice;
    dice++; rolls++;
    if (dice > 100) dice = 1;
    t += dice;
    dice++; rolls++;
    if (dice > 100) dice = 1;

    p[i] = (p[i] + t) % 10;
    //if (!p[i]) p[i]++;
    //if (p[i] > 10) p[i] = 1;

    sc[i] += (p[i] + 1);

    //cout << "turn " << turn << ",dice "<< dice<<endl;
    cout << "Player " << i << " rolls " << t << ",  inc " << sc[i] << endl;

    if (sc[i] >= 1000) break;

    i = !i;

    //if (!vv--) break;
  }

  i = !i;

  PRINTL(sc[i] * rolls);
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
