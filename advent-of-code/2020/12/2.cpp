#include <iostream>
#include <cmath>

using namespace std;

int main() {
  char c;
  int num;
  int wx = 10, wy = 1, x = 0, y = 0;
  int tmp;
  while (cin >> c >> num) {
    switch (c) {
      case 'N':
        wy += num;
        break;
      case 'S':
        wy -= num;
        break;
      case 'E':
        wx += num;
        break;
      case 'W':
        wx -= num;
        break;
      case 'L':
      case 'R':
        num %= 360;
        if (num == 180) {
          wx = -wx;
          wy = -wy;
        } else if (num) {
          bool left = (c == 'L' && num == 90) || (c == 'R' && num == 270);
          tmp = wy;
          if (left) {
            wy = wx;
            wx = -tmp;
          } else {
            wy = -wx;
            wx = tmp;
          }
        }
        break;
      case 'F':
        x += wx * num;
        y += wy * num;
        break;
    }
  }

  cout << abs(x) + abs(y) << endl;
  return 0;
}
