#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int n;
  int seq[4] = { 16, 6, 68, 88 };
  cin >> n;
  if (n <= 4) {
    for (int i = 0; i < n; i++) printf("%02d ", seq[i]);
  } else {
    cout << "Glupenky Pierre";
  }
  cout << endl;
  return 0;
}
