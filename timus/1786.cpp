#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int ans = 1000;
  const char N[] = "Sandro";
  string s;
  cin >> s;
  for (int i = 0; i < s.length() - 5; i++) {
    int cost = 0;
    for (int j = 0; j < 6; j++) {
      if (s[i + j] == N[j]) continue;
      cost += 5;
      // F*cking ASCII codes. Don't forget that 'a' = 97 and 'A' = 65
      // If ASCII code difference is 32 then they represent same letters in
      // different registers.
      bool dc = (s[i + j] >= 'a' && j == 0) || (j > 0 && s[i + j] <= 'Z');
      if (dc && (int)abs(s[i + j] - N[j]) != 32) cost += 5;
    }

    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
