#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  string s, ans;
  cin >> s;
  for (int i = s.length() - 1; i >= 0; i--) {
    int dif = i ? s[i - 1] - 'a' : 5;
    int off = (s[i] - 'a' + 26 - dif) % 26;
    ans += 'a' + off;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
