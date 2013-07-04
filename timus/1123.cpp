#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  cin >> s;
  int odd = s.length() % 2, mid = s.length() / 2, i, j;
  for (i = 0; i < mid; i++) {
    char left = s[mid - i - 1], right = s[mid + i + odd];
    if (right < left) {
      break;
    } else if (left < right) {
      for (j = mid + odd - 1; j >= 0; j--) {
        if (s[j] < '9') {
          s[j]++;
          break;
        }
      }
      for (j = j + 1; j < mid + odd; j++) {
        s[j] = '0';
      }
      break;
    }
  }
  for (i = 0; i < mid; i++) {
    s[s.length() - i - 1] = s[i];
  }
  cout << s << endl;

  return 0;
}
