#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, sum = 0;
  bool bad = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    bad = bad || (m == 3);
    sum += m;
  }
  if (bad) {
    cout << "None" << endl;
  } else if (sum == n * 5) {
    cout << "Named" << endl;
  } else if (sum * 10 >= 45 * n) {
    cout << "High" << endl;
  } else {
    cout << "Common" << endl;
  }
  return 0;
}
