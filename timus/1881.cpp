#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int h, w, n, cur = 0, lines = 1;
  cin >> h >> w >> n;
  while (n--) {
    string s;
    cin >> s;
    cur += s.length();
    if (cur > w) {
      cur = s.length() + 1;
      ++lines;
    } else {
      cur += 1;
    }
  }
  cout << lines / h + ((lines % h) ? 1 : 0) << endl;
  return 0;
}
