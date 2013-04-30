#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector< long long> p;

long long getDifference() {
  long long res = abs(p[0] - p[1]);
  for (int i = 0; i < p.size() - 1; i++) {
    for (int j = i + 1; j < p.size(); j++) {
      if (abs(p[i] - p[j]) < res) {
        res = abs(p[i] - p[j]);
      }
    }
  }
  return res;
}

int main(int argc, char const *argv[])
{
  p.resize(3);
  cin >> p[0] >> p[1] >> p[2];
  int ans = 1;
  long long dif;
  while (dif = getDifference()) {
    ++ans;
    p.push_back(dif);
  }
  cout << ans << endl;
  return 0;
}
