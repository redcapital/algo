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

int gsi = 0;
vector<int> stores[100000];

int storeval(int i, int val) {
  stores[i].push_back(val);
  return stores[i].size() - 1;
}

int getsi() {
  stores[gsi].clear();
  if (gsi == 99999) {
    cout << "FUUUCK" <<endl;
  }
  return gsi++;
}

typedef struct cnum {
  struct cnum* left;
  struct cnum* right;
  struct cnum* par;
  int si;
  int lv, rv;
  int flv=-123, frv=-123;

  //int getlval() { if (flv!=-123) {cout<<"flv ret" <<endl; return flv;}; return lv < 0 ? -1 : st->vals[lv]; }
  //int getrval() { if (frv!=-123) return frv; return rv < 0 ? -1 : this->st->vals[rv]; }
  int getlval() { 
    if (flv==-123) return lv < 0 ? -1 : stores[si][lv];
    return flv;
  }
  int getrval() {
    if (frv == -123) return rv < 0 ? -1 : stores[si][rv];
    return frv;
  }
} cnum;

int conv(const string& s) {
  int len = s.size();
  int res = 0, base = 1;
  for (int i = len - 1; i >= 0; i--) {
    res += base * (s[i] - '0');
    base *= 10;
  }
  //cout << "converted " << s << " to " << res << endl;
  return res;
}

cnum* parsecnum(const string& s, int si) {
  cnum* res = (cnum*) malloc(sizeof(cnum));
  res->si = si;
  res->lv = res->rv = -1;
  res->flv = res->frv = -123;

  int len = s.size();
  int brackets = 0;
  int comma = 0;
  FOS(i,1,len) {
    if (s[i]==',' && brackets==0) {
      comma = i;
      break;
    }
    if (s[i] == '[') {
      brackets++;
    } else if (s[i] == ']') {
      brackets--;
    }
  }
  // 01234567
  // [10,244]
  string tmp(s.substr(1, comma-1));
  //cout << "comma pos " << comma << endl;
  //cout << "left " << tmp << endl;
  if (tmp[0] == '[') {
    res->left = parsecnum(tmp, si);
    res->left->par = res;
  } else {
    res->lv = storeval(si, conv(tmp));
    //cout << "st: ";
    //FOR(j,st->vals.size()) {
      //cout << st->vals[j] << " ";
    //}
    //cout << endl;
    //cout << "stored lv " << st->vals[res->lv] << " at " << res->lv << endl;
  }
  tmp = s.substr(comma+1, len-comma-2);
  //cout << "right " << tmp << endl;
  if (tmp[0] == '[') {
    res->right = parsecnum(tmp, si);
    res->right->par = res;
  } else {
    res->rv = storeval(si,conv(tmp));
    //cout << "stored rv " << res->getrval() << " at " << res->rv << endl;
  }
  return res;
}

cnum* parse(const string& s) {
  int si = getsi();
  //num* res = (num*)malloc(sizeof(num));
  //res->st = st;
  //res->n = parsecnum(s, st);
  //cout << "parse curize " << st->vals.size() << endl;
  return parsecnum(s, si);
}

void print(cnum *n, bool rec=true) {
  cout << "[";
  int lval = n->getlval();
  int rval = n->getrval();
  if (lval < 0) {
    print(n->left);
  } else {
    cout << lval;
  }
  cout << ",";
  if (rval < 0) {
    print(n->right);
  } else {
    cout << rval;
  }
  cout << "]";
  if (!rec) {
    cout << " ";
    for (int i = 0; i < stores[n->si].size(); i++) cout << stores[n->si][i] << " ";
    cout << endl;
  }
}

cnum* walk(cnum* n, int si) {
  cnum* res = (cnum*) malloc(sizeof(cnum));
  res->si = si;
  res->lv = res->rv = -1;
  res->flv = res->frv = -123;

  //cout << "walking ";
  //print(n, false);
  int lval = n->getlval();
  if (lval < 0) {
    res->left = walk(n->left, si);
    res->left->par = res;
  } else {
    res->lv = storeval(si, lval);
  }

  int rval = n->getrval();
  if (rval < 0) {
    res->right = walk(n->right, si);
    res->right->par = res;
  } else {
    res->rv = storeval(si, rval);
  }

  return res;
}

cnum* getnested(cnum* n, int d) {
  //cout << "getnested looking at depth " << d << " ";
  //print(n, false);
  if (d>=4) {
    if (n->lv >= 0 && n->rv >= 0) {
      return n;
    }
  }
  cnum* res;
  if (n->lv < 0) {
    res = getnested(n->left, d+1);
    if (res != NULL) {
      return res;
    }
  }
  if (n->rv < 0) {
    res = getnested(n->right, d+1);
    if (res != NULL) {
      return res;
    }
  }
  return NULL;
}

void explode(cnum* n) {
  cnum* par = n->par;
  int idx = n->lv - 1;
  if (idx >= 0) {
    stores[n->si][idx] += n->getlval();
  }
  idx = n->rv + 1;
  if (idx < stores[n->si].size()) {
    stores[n->si][idx] += n->getrval();
  }
  if (n == par->left) {
    par->flv = 0;
  } else {
    par->frv = 0;
  }
}

bool split(cnum* n) {
  int lval = n->getlval();
  if (lval >= 10) {
    cnum* node = (cnum*)malloc(sizeof(cnum));
    node->flv=lval/2;
    node->frv=lval/2 + ((lval%2)?1:0);
    n->flv = -1;
    n->left = node;
    return true;
  } else if (lval < 0) {
    if (split(n->left)) {
      return true;
    }
  }
  int rval = n->getrval();
  if (rval >= 10) {
    cnum* node = (cnum*)malloc(sizeof(cnum));
    node->flv=rval/2;
    node->frv=rval/2 + ((rval%2)?1:0);
    n->frv = -1;
    n->right = node;
    return true;
  } else if (rval < 0) {
    if (split(n->right)) {
      return true;
    }
  }
  return false;
}

cnum* reduce(cnum* n) {
  cnum* res = n;
  while (true) {
    cnum* nested=getnested(res, 0);
    if (nested!=NULL) {
      cout << "found nested: ";
      print(nested , false);
      //break;
      explode(nested);
      //free(st);
      int si = getsi();
      res = walk(res, si);
      cout << "after exp: ";
      print(res, false);
      continue;
    }
    if (split(res)) {
      int si = getsi();
      res = walk(res, si);
      cout << "after split: ";
      print(res, false);
      continue;
    }
    break;
  }
  return res;
}

cnum* add(cnum* a, cnum* b) {
  cout << "adding a: ";
  print(a, false);
  cout << "adding b: ";
  print(b, false);
  cnum* res = (cnum*) malloc(sizeof(cnum));
  int si = getsi();
  res->si = si;
  res->lv = res->rv = -1;
  res->flv = res->frv = -123;
  res->left = walk(a, si);
  res->right = walk(b, si);
  cout << "adding res: ";
  print(res, false);
  return res;
}

int mag(cnum* n) {
  int lval = n->getlval();
  int rval = n->getrval();
  if (lval < 0) {
    lval = mag(n->left);
  }
  if (rval < 0) {
    rval = mag(n->right);
  }
  return 3 * lval + 2 * rval;
}


int main() {
  string s;
  cnum* res;
  cnum* tmp;
  int i = 0;
  while (getline(cin, s)) {
    tmp = parse(s);
    cout << " line " << i << " is: ";
    print(tmp, false);
    if (!i) {
      res = tmp;
      //print(res, false);
      //res = reduce(res);
      //print(res, false);
    } else {
      res = reduce(add(res, tmp));
    }
    i++;
  }
  print(res, false);

  PRINTL(mag(res));
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
