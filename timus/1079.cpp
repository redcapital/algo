#include <iostream>

using namespace std;

const int N = 100000;

int a[N], mx[N] = { 0 };

int main(int argc, char const *argv[])
{
  a[1] = 1;
  mx[1] = 1;
  for (int i = 1; i < N / 2; i++) {
    a[2 * i] = a[i];
    a[2 * i + 1] = a[i] + a[i + 1];
    mx[2 * i] = max(mx[2 * i], max(mx[2 * i - 1], a[i]));
    mx[2 * i + 1] = max(mx[2 * i + 1], max(mx[2 * i], a[2 * i + 1]));
  }

  int n;
  while (cin >> n) {
    if (n == 0) break;
    cout << mx[n] << endl;
  }
  return 0;
}
