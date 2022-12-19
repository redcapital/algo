#include <iostream>
#include <list>

using namespace std;

const int N = 25;

int main() {
  list<int> a;
  int n;
  while (cin >> n) {
    if (a.size() < N) {
      a.push_back(n);
      continue;
    }
    bool ok = false;
    for (auto i = a.begin(); i != a.end(); i++) {
      for (auto j = next(i); j != a.end(); j++) {
        if (*i + *j == n) {
          ok = true;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    if (ok) {
      a.pop_front();
      a.push_back(n);
    } else {
      cout << n << endl;
      break;
    }
  }
  return 0;
}

