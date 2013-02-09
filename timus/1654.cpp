#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
  vector<char> s;
  char c;
  while (cin >> c) {
    if (s.empty() || s.back() != c) s.push_back(c);
    else s.pop_back();
  }
  copy(s.begin(), s.end(), ostream_iterator<char>(cout));
  return 0;
}
