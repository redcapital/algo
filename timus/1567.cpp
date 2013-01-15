#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int ans = 0;
  string s;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ans += ((s[i] - 'a') % 3) + 1;
    } else if (s[i] == '.' || s[i] == ' ') {
      ans += 1;
    } else if (s[i] == ',') {
      ans += 2;
    } else {
      ans += 3;
    }
  }
  cout << ans << endl;
  return 0;
}
