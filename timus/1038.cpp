#include <cstdio>

using namespace std;

bool isUpper(char c) {
  return c >= 'A' && c <= 'Z';
}

int main(int argc, char const *argv[])
{
  static char a[10000], w[10000];
  int al = 0, i, j, wl = 0, ans = 0;
  while (true) {
    scanf("%c", &a[al]);
    if (feof(stdin)) break;
    ++al;
  }
  bool sentence = true;
  for (i = 0; i < al || wl; i++) {
    if (i < al && (isUpper(a[i]) || (a[i] >= 'a' && a[i] <= 'z'))) {
      w[wl++] = a[i];
    } else {
      if (wl) {
        if (sentence && !isUpper(w[0])) ++ans;
        for (j = 1; j < wl; j++) if (isUpper(w[j])) ++ans;
        wl = 0;
        sentence = false;
      }
      sentence = sentence || (i < al && (a[i] == '.' || a[i] == '?' || a[i] == '!'));
    }
  }
  printf("%d\n", ans);
  return 0;
}
