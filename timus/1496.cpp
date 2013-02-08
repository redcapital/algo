#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  map<string, int> m;
  cin >> n;
  while (n--) {
    string t;
    cin >> t;
    if (m.count(t) == 0) {
      m[t] = 1;
    } else if (m[t] == 1) {
      m[t] = 2;
      cout << t << endl;
    }
  }
  return 0;
}
