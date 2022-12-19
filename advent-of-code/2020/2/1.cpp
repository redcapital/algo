#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int lo, hi, valid = 0;
  char c;
  char buf[1024];
  while (!feof(stdin)) {
    scanf("%d-%d %c: %s", &lo, &hi, &c, buf);
    int len = strlen(buf), cnt = 0;
    for (int i = 0; i < len; i++) {
      if (buf[i] == c) {
        cnt++;
      }
    }
    if (cnt >= lo && cnt <= hi) {
      valid++;
    }
  }
  cout << valid << endl;
  return 0;
}

