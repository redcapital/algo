// Uses: permutations, stack

// There are only 6! = 720 possible sequences of dice numbers.
// We can generate all these sequences, assign unique numbers to them
// (from 1 to 720 inclusive) and create array a[720][720], where
// a[x][y] will be true iff sequence x can be constructed from sequence y
// (or vice versa) by rotating the dice
//
// To construct a[i][] we can take sequence i, generate all sequences
// which can be reached from i by rotating the dice, and mark a[i][x] = true
// a[i][i] should also be true
//
// After this, we'll read all input and for every sequence we'll:
// - get it's sequence number S
// - find other sequences X from input such that a[S][X] = true
//
// Complexity: preprocessing sequences (processSequences() function)
// takes O(1) because it performs 6! regardless of N
// Looks like two loops inside function main() perform N^2 operations,
// but in fact every sequence will be looked at only once, so overall
// time complexity is O(N)

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int PC = 720;
const int MAXN = 100000;

bool a[PC + 1][PC + 1] = { 0 };

//         0  1  2  3  4  5
//         L  R  T  F  B  K(back)
int seqNum[6][6][6][6][6][6];

struct seq {
  int i[6];
};

seq input[MAXN];
bool f[MAXN] = { 0 };
vector < vector <int> > ans;

void processSequences() {
  int sc = 1, i[6] = { 0, 1, 2, 3, 4, 5 };
  // Assign all sequence numbers first
  do {
    seqNum[i[0]][i[1]][i[2]][i[3]][i[4]][i[5]] = sc++;
  } while (next_permutation(i, i + 6));

  for (int j = 0; j < 6; j++) i[j] = j;
  // Process each sequence
  do {
    bool processed[PC + 1] = { 0 };
    int curnum = seqNum[i[0]][i[1]][i[2]][i[3]][i[4]][i[5]];
    seq cur;
    for (int j = 0; j < 6; j++) cur.i[j] = i[j];
    // Generate all sequences reachable from cur
    stack <seq> s;
    s.push(cur);
    while (!s.empty()) {
      cur = s.top();
      s.pop();
      int num = seqNum[cur.i[0]][cur.i[1]][cur.i[2]][cur.i[3]][cur.i[4]][cur.i[5]];
      if (processed[num]) {
        continue;
      }
      processed[num] = true;
      a[num][curnum] = a[curnum][num] = true;

      // New sequences can be constructed from cur in two ways:
      // Rotating to right: L -> F, F -> R, R -> K, K -> L
      seq child = cur;
      child.i[0] = cur.i[3];
      child.i[3] = cur.i[1];
      child.i[1] = cur.i[5];
      child.i[5] = cur.i[0];
      s.push(child);

      // And rotating to top: B -> F, F -> T, T -> K, K -> B
      child = cur;
      child.i[4] = cur.i[3];
      child.i[3] = cur.i[2];
      child.i[2] = cur.i[5];
      child.i[5] = cur.i[4];
      s.push(child);
    }
  } while (next_permutation(i, i + 6));
}

int main(int argc, char const *argv[])
{
  processSequences();

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> input[i].i[j];
      input[i].i[j] -= 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (!f[i]) {
      vector <int> v;
      f[i] = true;
      v.push_back(i + 1);
      int curnum = seqNum[input[i].i[0]][input[i].i[1]][input[i].i[2]][input[i].i[3]][input[i].i[4]][input[i].i[5]];
      for (int j = 0; j < N; j++) {
        if (!f[j]) {
          int num = seqNum[input[j].i[0]][input[j].i[1]][input[j].i[2]][input[j].i[3]][input[j].i[4]][input[j].i[5]];
          if (a[curnum][num]) {
            f[j] = true;
            v.push_back(j + 1);
          }
        }
      }
      ans.push_back(v);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
