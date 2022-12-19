#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int N = 5;
int boards[1000][N][N], bc = 0;
bool m[1000][N][N];

bool mark(int b, int num) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (boards[b][r][c] == num) {
        m[b][r][c] = true;

        bool all = true;
        for (int i = 0; i < N; i++) {
          if (!m[b][i][c]) {
            all = false;
            break;
          }
        }

        if (all) {
          return true;
        }

        all = true;
        for (int i = 0; i < N; i++) {
          if (!m[b][r][i]) {
            all = false;
            break;
          }
        }

        if (all) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  string s;
  int x;
  vector<int> nums;
  memset(m, 0, sizeof(m));

  while (cin >> x) {
    nums.push_back(x);
    if (cin.peek() == ',') {
      cin.ignore();
    } else if (cin.peek() == '\n') {
      break;
    }
  }

  while (cin >> x) {
    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
      if (r == 0 && c == 0) boards[bc][r][c] = x; else cin >> boards[bc][r][c];
    }
    bc++;
  }


  for (int i = 0; i < nums.size(); i++) {
    for (int b = 0; b < bc; b++) {
      if (mark(b, nums[i])) {
        int sum = 0;
        for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) sum += m[b][r][c] ? 0 : boards[b][r][c];
        cout << sum << "*" << nums[i] << " = " << sum * nums[i] << endl;
        return 0;
      }
    }
  }

  cout << "not found?" << endl;
  return 0;
}

