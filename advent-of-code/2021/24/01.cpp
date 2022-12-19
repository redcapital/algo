#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
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

const int ADD = 0;
const int INP = 1;
const int MUL = 2;
const int MOD = 3;
const int DIV = 4;
const int EQL = 5;

struct Inst {
  int type;
  char op1=0;
  char op2=0;
  int op2v=0;
};

int ans = 0;
vector<Inst> ins;

int w, x, y, z;



int main() {
  string s;
  while (true) {
    Inst i;
    string type, op;
    if (!(cin >> type)) break;
    cin >> op;
    i.op1 = op[0];
    if (type == "inp") {
      i.type = INP;
      continue;
    }
    cin >> op;
    if (op[0] == 'w' || op[0] == 'x' || op[0] == 'y' || op[0] == 'z') {
      i.op2 = op[0];
    } else {
      i.op2v = stoi(op);
    }
    if (type == "add") {
      i.type = ADD;
    } else if (type == "mul") {
      i.type = MUL;
    } else if (type == "mod") {
      i.type = MOD;
    } else if (type == "div") {
      i.type = DIV;
    } else if (type == "eql") {
      i.type = EQL;
    }

    ins.push_back(i);
  }

  expand(

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
