#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, ans = 2;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    ans++;
    if (s.find('+') != string::npos) ans++;
  }
  cout << 100 * (ans == 13 ? 14 : ans) << endl;
  return 0;
}
