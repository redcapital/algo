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
  map<string, char> m;
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
    m[pair] = c;
    //cout << pair << " " << c << endl;
  }
  for (int i = 0;i<10;i++) {
    int len = temp.size();
    string temp2;
    FOR(j,len-1) {
      auto it=m.find(temp.substr(j, 2));
      //cout<<"pair " << temp.substr(j, 2)<<endl;
      temp2.push_back(temp[j]);
      if (it!=m.end()) {
        temp2.push_back(it->second);
      }
      //temp2.push_back(temp[j+1]);
    }
    temp2.push_back(temp[len-1]);
    temp=temp2;
    //cout<<temp<<endl;
  }
  long long cnt[500];
  CLEAR(cnt);
  FOR(i,temp.size()) {
    cnt[temp[i]]++;
  }
  long long mx = 0, mn = 5000000;
  FOR(i,500) {
    if (cnt[i]) {
      mx=max(cnt[i],mx);
      mn=min(cnt[i],mn);
    }
  }
  cout<<mx-mn<<endl;
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
