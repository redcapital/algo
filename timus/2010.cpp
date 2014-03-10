#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, x, y;
  cin >> n >> x >> y;

  int t = 0;
  if (x > 1) {
    t++;
    t += (y > 1) + (y < n);
  }
  if (x < n) {
    t++;
    t += (y > 1) + (y < n);
  }
  t += (y > 1) + (y < n);
  cout << "King: " << t << endl;

  t = 0;
  if (x > 1) {
    t += (y > 2) + (y < n - 1);
  }
  if (x > 2) {
    t += (y > 1) + (y < n);
  }
  if (x < n) {
    t += (y > 2) + (y < n - 1);
  }
  if (x < n - 1) {
    t += (y > 1) + (y < n);
  }
  cout << "Knight: " << t << endl;

  t = min(x - 1, y - 1) + min(x - 1, n - y) + min(n - x, y - 1) + min(n - x, n - y);
  cout << "Bishop: " << t << endl;

  int bishop = t;

  t = n + n - 2;
  cout << "Rook: " << t << endl;

  cout << "Queen: " << bishop + t << endl;

  return 0;
}
