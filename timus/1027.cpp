// Uses: finite-state machine

// Simple parser with two states: NORMAL and EXPR
// You should implement transitions and check for errors

#include <cstdio>

using namespace std;

// Parser state
const int NORMAL = 0;
const int EXPR = 1;

// Status of parseComment()
const int COMMENT_NOT_PARSED = 0;
const int COMMENT_PARSED = 1;
const int COMMENT_INVALID = 2;

int i = 0, c = 0, state = NORMAL, exprLevel = 0;
char t[10000];

int parseComment() {
  if (t[i] == '(' && i + 1 < c && t[i + 1] == '*') {
    i += 2;
    while (i < c) {
      if (t[i] == '*' && i + 1 < c && t[i + 1] == ')') {
        i += 2;
        return COMMENT_PARSED;
      } else {
        i += 1;
      }
    }
    return COMMENT_INVALID;
  }
  return COMMENT_NOT_PARSED;
}

void answer(bool ok) {
  if (ok) printf("YES\n"); else printf("NO\n");
}

int main(int argc, char const *argv[])
{
  int commentStatus;
  while (!feof(stdin)) { scanf("%c", t + c); ++c; }
  while (i < c) {
    do {
      commentStatus = parseComment();
      if (commentStatus == COMMENT_INVALID) {
        answer(false);
        return 0;
      }
    } while (commentStatus == COMMENT_PARSED);
    if (i >= c) break;

    switch (state) {
      case NORMAL:
        if (t[i] == '(') {
          exprLevel += 1;
          state = EXPR;
          i += 1;
        } else if (t[i] == ')') {
          answer(false);
          return 0;
        } else {
          i += 1;
        }
        break;

      case EXPR:
        if (t[i] == '(') {
          exprLevel += 1;
          i += 1;
        } else if (t[i] == ')') {
          if (exprLevel == 0) {
            answer(false);
            return 0;
          } else {
            exprLevel -= 1;
            if (exprLevel == 0) {
              state = NORMAL;
            }
            i += 1;
          }
        } else {
          if ((t[i] >= '0' && t[i] <= '9') || t[i] == '=' || t[i] == '/'
              || t[i] == '+' || t[i] == '-' || t[i] == '*' || t[i] == '\n'
             ) {
            i += 1;
          } else {
            answer(false);
            return 0;
          }
        }
        break;
    }
  }

  answer(state == NORMAL);
  return 0;
}

