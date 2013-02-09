// For a given width (W) and height (H), the answer f(W, H) is:
// 0, if (H == 1), otherwise
// 1, if (W == 1), otherwise
// 2, if (H == 2), otherwise
// 3, if (W == 2), otherwise
// 4 + f(W - 2, H - 2), because robot makes full move around rectangle reducing its dimensions by 2
//
// So the robot makes min(W / 2, H / 2) full moves (each has 4 turns) and then
// we will have one of the trivial cases above.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  long long w, h, res;
  cin >> h >> w;
  if (w < h) {
    res = (w / 2) * 4;
    if (w % 2) ++res; // w == 1 case
    else --res; // w == 2 case
  } else {
    res = (h / 2) * 4;
    if (h % 2 == 0) res -= 2; // h == 2 case
  }
  cout << res << endl;
  return 0;
}
