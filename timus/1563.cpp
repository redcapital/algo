#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, ans = 0;
  set<string> s;
  string t;
  cin >> n;
  getline(cin, t);
  while (n--) {
    getline(cin, t);
    if (s.count(t)) ++ans; else s.insert(t);
  }
  cout << ans << endl;
  return 0;
}
