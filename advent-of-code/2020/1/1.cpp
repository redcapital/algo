#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> s;
  int n;
  while (cin >> n) {
    s.insert(n);
    int rem = 2020 - n;
    if (s.count(rem)) {
      cout << n * rem << endl;
      break;
    }
  }
  return 0;
}

