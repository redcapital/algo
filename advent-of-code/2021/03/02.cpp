#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> search(const vector<string>& v, int idx, bool most) {
  int ones = 0, zeroes = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i][idx] == '1') {
      ones++;
    } else {
      zeroes++;
    }
  }
  char lookFor;
  if (most) {
    lookFor = ones >= zeroes ? '1' : '0';
  } else {
    lookFor = ones < zeroes ? '1' : '0';
  }
  vector<string> res;
  for (int i = 0; i < v.size(); i++) {
    if (v[i][idx] == lookFor) {
      res.push_back(v[i]);
    }
  }

  if (res.size() > 1) {
    return search(res, idx + 1, most);
  }
  return res;
}

int main() {
  string c;
  vector<string> input;
  while (cin >> c) {
    input.push_back(c);
  }

  vector<string> oxygen(search(input, 0, true));

  vector<string> co2(search(input, 0, false));

  int len = oxygen[0].size();
  int oxygenNum = 0, co2Num = 0;
  for (int i = 0; i < len; i++) {
    if (oxygen[0][i] == '1') {
      oxygenNum |= 1 << (len - i - 1);
    }
    if (co2[0][i] == '1') {
      co2Num |= 1 << (len - i - 1);
    }
  }

  cout << oxygenNum * co2Num << endl;

  return 0;
}

