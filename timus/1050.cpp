// Uses: parser

#include <cstdio>

using namespace std;

const int N = 250 * 80;

char p[N];
int pos[N], pc, ps;

void processParagraph() {
  int ci = 0;
  bool closing = false;
  for (int i = 0; i < pc; i++) {
    if (ci < ps && i == pos[ci]) {
      if (closing) {
        printf("''");
        closing = false;
      } else if (ci + 1 < ps) {
        printf("``");
        closing = true;
      }
      ++ci;
    } else {
      printf("%c", p[i]);
    }
  }
}

int main(int argc, char const *argv[])
{
  pc = ps = 0;
  while (true) {
    scanf("%c", p + pc);
    if (feof(stdin)) break;
    if (p[pc] == '"' && (!pc || p[pc - 1] != '\\')) {
      // Normal "
      pos[ps++] = pc;
      ++pc;
    } else if (
        (pc > 2 && p[pc - 3] == '\\' && p[pc - 2] == 'p' && p[pc - 1] == 'a' && p[pc] == 'r') ||
        (pc > 0 && p[pc - 1] == '\n' && p[pc] == '\n')
    ) {
      // End of paragraph
      ++pc;
      processParagraph();
      pc = ps = 0;
    } else {
      ++pc;
    }
  }
  if (pc) processParagraph();
  return 0;
}

