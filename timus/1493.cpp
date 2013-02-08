#include <iostream>

using namespace std;

bool t(int x) {
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 3; i++, x /= 10) s1 += x % 10;
  for (int i = 0; i < 3; i++, x /= 10) s2 += x % 10;
  return s1 == s2;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  if (t(n + 1) || t(n - 1)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
