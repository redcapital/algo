#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
  int r;
  char c;
  scanf("%d%c", &r, &c);
  if (r < 3) {
    if (c == 'A' || c == 'D') puts("window");
    else puts("aisle");
  } else if (r < 21) {
    if (c == 'A' || c == 'F') puts("window");
    else puts("aisle");
  } else {
    if (c == 'A' || c == 'K') puts("window");
    else if (c == 'C' || c == 'D' || c == 'G' || c == 'H') puts("aisle");
    else puts("neither");
  }
  return 0;
}
