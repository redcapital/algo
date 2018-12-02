#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n, good = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 1) {
      if ((x - 3) % 4 == 0) good++;
    }
  }
  if (good % 2 == 0) {
    cout << "Stannis";
  } else {
    cout << "Daenerys";
  }
  cout << endl;
  return 0;
}
