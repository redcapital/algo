#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < 10; i++) {
    int t;
    cin >> t;
    b -= t * 20;
  }
  if (b >= a) {
    cout << "No chance.";
  } else {
    cout << "Dirty debug :(";
  }
  return 0;
}
