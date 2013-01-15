#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  int n, e = 0, l = 0, m = 0;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    if (s[0] == 'E') e++;
    else if (s[0] == 'M') m++;
    else l++;
  }
  if (e > l && e > m) cout << "Emperor Penguin";
  else if (l > e && l > m) cout << "Little Penguin";
  else cout << "Macaroni Penguin";
  cout << endl;
  return 0;
}
