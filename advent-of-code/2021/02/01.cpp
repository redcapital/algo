#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, hp = 0, dp = 0;
  string c;
  while (cin >> c >> n) {
    switch (c[0]) {
      case 'f':
        hp += n;
        break;
      case 'd':
        dp += n;
        break;
      case 'u':
        dp -= n;
        break;
    }
  }
  cout << hp * dp << endl;
  return 0;
}

