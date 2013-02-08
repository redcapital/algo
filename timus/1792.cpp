#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[7];
  for (int i = 0; i < 7; i++) cin >> a[i];
  for (int i = -1; i < 7; i++) {
    if (i >= 0) a[i] = !a[i];
    if (
      a[4] == a[1] ^ a[2] ^ a[3] &&
      a[5] == a[0] ^ a[2] ^ a[3] &&
      a[6] == a[0] ^ a[1] ^ a[3]
    ) break;
    if (i >= 0) a[i] = !a[i];
  }

  for (int i = 0; i < 7; i++) cout << a[i] << " ";
  return 0;
}
