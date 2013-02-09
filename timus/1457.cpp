#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
  double n;
  cin >> n;
  cout.precision(7);
  cout << fixed << accumulate(istream_iterator<double>(cin), istream_iterator<double>(), 0.0) / n << endl;
  return 0;
}
