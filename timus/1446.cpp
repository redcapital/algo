#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  vector<string> name[4];
  string tn, tf;
  getline(cin, tn);
  while (n--) {
    getline(cin, tn);
    getline(cin, tf);
    int ind;
    if (tf[0] == 'S') ind = 0;
    else if (tf[0] == 'H') ind = 1;
    else if (tf[0] == 'G') ind = 2;
    else ind = 3;
    name[ind].push_back(tn);
  }

  for (int i = 0; i < 4; i++) {
    if (i == 0) cout << "Slytherin";
    else if (i == 1) cout << "Hufflepuff";
    else if (i == 2) cout << "Gryffindor";
    else cout << "Ravenclaw";
    cout << ":" << endl;
    for (int j = 0; j < name[i].size(); j++) {
      cout << name[i][j] << endl;
    }
    cout << endl;
  }
  return 0;
}
