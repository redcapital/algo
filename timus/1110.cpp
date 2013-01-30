#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, m, y;
  cin >> n >> m >> y;
  bool found = false;
  for (int i = 1; i < m; i++) {
    int x = i;
    for (int j = 1; j < n; j++) {
      x = (x * i) % m;
    }


    if (x == y) {
      found = true;
      cout << i << " ";
    }
  }

  if (!found) cout << "-1";
  cout << endl;
  return 0;
}
