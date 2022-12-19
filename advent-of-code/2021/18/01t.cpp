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

struct num;

typedef struct cnum {
  struct cnum* left;
  struct cnum* right;
  num* root;
  int lv, rv;
} cnum;

typedef struct num {
  cnum* n;
  vector<int> vals;

  int storeval(int val) {
    vals.push_back(val);
    return vals.size() - 1;
  }
} num;

/*
typedef struct num {
  struct num* par;
  struct num* left;
  struct num* right;
  int lv, rv;
} num;
*/

cnum* parsecnum(const string& s, num* root) {
  cnum* res = (cnum*) malloc(sizeof(cnum));
  res->root = root;
  res->lv=-999999;
  res->rv=-999999;

  int len = s.size();
  int st = 0;
  int comma = 0;
  FOS(i,1,len) {
    if (s[i]==',' && st==0) {
      comma = i;
      break;
    }
    if (s[i] == '[') {
      st++;
    } else if (s[i] == ']') {
      st--;
    }
  }
  // 01234567
  // [10,244]
  string tmp(s.substr(1, comma-1));
  if (tmp[0] == '[') {
    res->left = parsecnum(tmp, root);
  } else {
    res->lv = res->root->storeval(atoi(tmp.c_str()));
  }
  tmp = s.substr(comma+1, len-comma-2);
  if (tmp[0] == '[') {
    res->right = parsecnum(tmp, root);
  } else {
    res->rv = res->root->storeval(atoi(tmp.c_str()));
  }
  return res;
}

num* parse(const string& s) {
  num* res = (num*) malloc(sizeof(num));
  res->n = parsecnum(s, res);
  return res;
}

num* getnested(num* n, int d=0) {
  if (d>=4) {
    if (n->lv != -999999 && n->rv != -999999) {
      return n;
    }
  }
  if (n->lv == -999999) {
    return getnested(n->left, d+1);
  }
  if (n->rv == -999999) {
    return getnested(n->right, d+1);
  }
  return NULL;
}

void explode(num* n) {
  num* par = n->par;
  if (n == par->right) {
    if (par->lv == -999999) {
      cerr << "non reg par " <<endl;
    }
    par->lv += n->lv;
    par->rv = 0;


  } else {
  }
}

num* reduce(num* n) {
  while (true) {
    num* nested=getnested(n);
    if (nested!=NULL) {
      explode(num);
    }
  }
  return n;
}

num* add(num* a, num* b) {
  num* res = (num*)malloc(sizeof(num));
  res->left = a;
  res->right = b;
  return res;
}

int main() {
  string s;
  num* res;
  num* tmp;
  int i = 0;
  while (getline(cin, s)) {
    tmp = parse(s);
    if (!i) {
      res = tmp;
    } else {
      res = reduce(add(res, tmp));
    }
    i++;
  }

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
