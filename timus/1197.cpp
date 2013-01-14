#include <iostream>

using namespace std;

#define CHECK(a, b) if (a - 2 >= 0) { if (b - 1 >= 0) ++ans; if (b + 1 < 8) ++ ans; }
#define CHECKP(a, b) if (a + 2 < 8) { if (b - 1 >= 0) ++ans; if (b + 1 < 8) ++ ans; }

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    char c;
    int x, y, ans = 0;
    cin >> c >> y;
    x = c - 'a';
    --y;
    CHECK(x, y);
    CHECKP(x, y);
    CHECK(y, x);
    CHECKP(y, x);
    cout << ans << endl;
  }
  return 0;
}
