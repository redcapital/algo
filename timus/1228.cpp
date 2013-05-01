// Managed to solve with first hackish attempt but all I can say is WTF
// (I'm too lazy to explain ^^ )
// The code can be much shorter I guess, again I'm too lazy to write it

#include <iostream>

using namespace std;

int n, s, d[20], sum, ans[20];

bool gen(int ind) {
  if (ind == 0) {
    //cerr << "sum is " << sum << endl;
    if ((s - sum - 1) % d[0] == 0) {
      ans[0] = (s - sum - 1) / d[0];
      return true;
    }
    return false;
  }
  for (int i = d[ind - 1] - sum - 1; i > 0; i--) {
    if (i % d[ind] == 0) {
      //cerr << "trying " << i << " for [" << ind << "]" << endl;
      sum += i;
      ans[ind] = i / d[ind];
      if (gen(ind - 1)) return true;
      sum -= i;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> d[i];
  sum = 0;
  gen(n - 1);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
