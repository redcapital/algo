// Uses: dynamic programming
//
// Let d[i] be maximum amount of events you can attend starting from i-th minute.
//
// Then for every i=30000 to 1
//
// 1) If we don't have event startin on i-th minute then
// d[i] = d[i + 1]
// Meaning: if we can attend some events on i-th minute, we can attennd them from (i-1)-th minute too
//
// 2) If we do have event starting on i-th minute with length LEN, then we can 
// either attend that or not. If we attend, we continue on (i + LEN + 1) minute.
// So the best outcome is:
//
// d[i] = max(
//   d[i + 1],            // do not attend
//   1 + d[i + LEN + 1]   // attend
// )

#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 100000;

int len[30001] = { 0 };
int d[30002] = { 0 };

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    int clen = e - s;
    if (len[s] == 0 || len[s] > clen) {
      len[s] = clen;
    }
  }
  for (int i = 30000; i >= 1; i--) {
    d[i] = d[i + 1];
    if (len[i]) {
      d[i] = max(d[i], 1 + d[i + len[i] + 1]);
    }
  }
  cout << d[1] << endl;
  return 0;
}
