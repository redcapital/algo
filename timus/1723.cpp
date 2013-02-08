// We can output ANY substring. Let's count letters then :)

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int a[26] = { 0 }, mx = 0;
  char c;
  while (cin >> c) {
    c -= 'a';
    if (++a[c] > a[mx]) mx = c;
  }
  cout << (char)(mx + 'a');
  return 0;
}
