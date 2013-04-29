#include <iostream>
#include <cctype>

using namespace std;

char buf[10000];
int bn = 0;

void fixAndPrint() {
  bool first = true;
  for (int i = 0; i < bn; i++) {
    if (isupper(buf[i])) {
      if (first) {
        first = false;
      } else {
        buf[i] = tolower(buf[i]);
      }
    }
    cout << buf[i];
  }
  bn = 0;
}

int main(int argc, char const *argv[])
{
  char c;
  std::cin >> std::noskipws;
  while (cin >> c) {
    buf[bn++] = c;
    if (c == '.' || c == '!' || c == '?') {
      fixAndPrint();
    }
  }
  fixAndPrint();
  return 0;
}
