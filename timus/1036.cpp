// Uses: dynamic programming, bignum arithmetic

// Let d[N][K] be the number of N-digit sequences that sum up to K
// The recurrence relation:
// d[N + 1][K] = d[N][K] + d[N][K - 1] + d[N][K - 2] ... d[N][K - 9], K - 9 >= 0
//
// Obviously d[1][K] = 1 if 0<=K<=9, and 0 otherwise
// Answer then would be (d[N][K] ^ 2) since there are two halves of a ticket
// and any half can be one of d[N][K] sequences
//
// K = S / 2, where S is second number in input. If S is odd answer is 0
//
// Since d[i][] depends only on d[i-1][], we can use only 2 arrays with K elements
// Also, answers can be very big so we must use bignum arithmetic

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int BASE = 1000000000;
class LongNum : public vector<int> {
  public:
    LongNum() {}

    void operator=(int x) {
      clear();
      do {
        push_back(x % BASE);
        x /= BASE;
      } while (x);
    }

    void add(LongNum& a) {
      int carry = 0, ml = max(size(), a.size());
      for (int i = 0; i < ml || carry; i++) {
        if (i == size()) push_back(0);
        (*this)[i] = (i < size() ? (*this)[i] : 0) + (i < a.size() ? a[i] : 0) + carry;
        carry = ((*this)[i] >= BASE) ? 1 : 0;
        if (carry) (*this)[i] -= BASE;
      }
    }

    LongNum square() {
      LongNum result;
      result.resize(size() * 2);
      for (int i = 0; i < size(); i++)
        for (int j = 0, carry = 0; j < size() || carry; j++) {
          long long cur = result[i + j] + (*this)[i] * 1ll * (j < size() ? (*this)[j] : 0) + carry;
          result[i + j] = int(cur % BASE);
          carry = int(cur / BASE);
        }
      while (result.size() > 1 && result.back() == 0) result.pop_back();
      return result;
    }

    void print() {
      if (empty()) cout << 0;
      else {
        printf("%d", back());
        for (int i = (int)size() - 2; i >= 0; i--) {
          printf("%09d", (*this)[i]);
        }
      }
    }
};

int main(int argc, char const *argv[])
{
  int n, k;
  cin >> n >> k;
  if (k % 2 == 0) {
    int i, j, r;
    LongNum d[2][501];
    k /= 2;
    for (i = 0; i <= k; i++) d[0][i] = (i < 10);
    int cur = 1;
    for (i = 1; i < n; i++, cur = !cur) {
      d[cur][0] = 1;
      for (j = 1; j <= k; j++) {
        d[cur][j] = 0;
        for (r = 0; r <= min(9, j); r++) d[cur][j].add(d[1 - cur][j - r]);
      }
    }
    d[1 - cur][k].square().print();
  } else cout << 0;
  cout << endl;
  return 0;
}
