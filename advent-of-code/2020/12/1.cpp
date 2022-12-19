#include <iostream>
#include <cmath>

using namespace std;

int main() {
  char c;
  int num;
  int x = 0, y = 0, dir = 0;
  while (cin >> c >> num) {
    switch (c) {
      case 'N':
        y += num;
        break;
      case 'S':
        y -= num;
        break;
      case 'E':
        x += num;
        break;
      case 'W':
        x -= num;
        break;
      case 'L':
        dir = (dir + num + 360) % 360;
        break;
      case 'R':
        dir = (dir - num + 360) % 360;
        break;
      case 'F':
        switch (dir) {
          case 0:
            x += num;
            break;
          case 90:
            y += num;
            break;
          case 180:
            x -= num;
            break;
          case 270:
            y -= num;
            break;
        }
        break;
    }
  }

  cout << abs(x) + abs(y) << endl;
  return 0;
}
