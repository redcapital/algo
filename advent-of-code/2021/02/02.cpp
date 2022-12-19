#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, aim = 0, hp = 0, dp = 0;
  string c;
  while (cin >> c >> n) {
    switch (c[0]) {
      case 'f':
        hp += n;
        dp += aim * n;
        break;
      case 'd':
        aim += n;
        break;
      case 'u':
        aim -= n;
        break;
    }
  }
  cout << hp * dp << endl;
  return 0;
}

