#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int N = 200;

int main(int argc, char const *argv[])
{
  int n;
  string a[N + 1];
  cin >> n;
  a[1] = "sin(1";
  string paren(")");
  for (int i = 2; i <= n; i++) {
    char sign = (i & 1) ? '+' : '-';
    ostringstream ss(a[i - 1] + sign + "sin(", ios_base::ate);
    ss << i;
    a[i] = ss.str();
    a[i - 1] += paren;
    paren += ')';
  }
  a[n] += paren;

  ostringstream res;
  for (int i = n; i > 0; i--) {
    res << a[n - i + 1] << '+' << i;
    if (i > 1) res << ')';
  }

  cout << string(n - 1, '(') + res.str() << endl;
  return 0;
}
