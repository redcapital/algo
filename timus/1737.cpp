#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a" << endl << "b" << endl << "c" << endl;
  } else if (n * 6 > 100000) {
    cout << "TOO LONG" << endl;
  } else {
    string pat[6] = { "abc", "acb", "bac", "bca", "cab", "cba" };
    int times = n / 3, rem = n % 3;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < times; j++) {
        cout << pat[i];
      }
      if (rem) {
        cout << pat[i].substr(0, rem);
      }
      cout << endl;
    }
  }
  return 0;
}
