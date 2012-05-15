// Uses: dynamic programming, bignum arithmetic

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// Class LongNum implements bignum arithmetic. For this problem, we only
// need to implement 2 operations:
// - sum of two long numbers
// - multiplication of long and short numbers

const int base = 1000000000;
class LongNum : public vector<int> {
  public:
    LongNum() {}
    LongNum(int value) {
      operator=(value);
    }

    void operator=(int x) {
      clear();
      do {
        push_back(x % base);
        x /= base;
      } while (x);
    }

    LongNum operator+(LongNum& a) {
      LongNum result;
      int carry = 0, ml = max(size(), a.size());
      for (int i = 0; i < ml || carry; i++) {
        if (i == result.size()) result.push_back(0);
        result[i] = (i < size() ? (*this)[i] : 0) + (i < a.size() ? a[i] : 0) + carry;
        carry = (result[i] >= base) ? 1 : 0;
        if (carry) result[i] -= base;
      }
      return result;
    }

    LongNum operator*(int a) {
      LongNum result;
      int carry = 0;
      for (int i = 0; i < size() || carry; i++) {
        if (i == result.size()) result.push_back(0);
        long long p = carry + (i < size() ? (*this)[i] : 0) * 1ll * a;
        result[i] = int(p % base);
        carry = int(p / base);
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
      cout << endl;
    }
};

int main(int argc, char const *argv[])
{
  int N, K;
  cin >> N >> K;

  vector <LongNum> F(N + 1);
  F[0] = 1;
  F[1] = K - 1;

  for (int i = 2; i <= N; i++) {
    // Main recurrence relation
    F[i] = (F[i - 1] + F[i - 2]) * (K - 1);
  }
  F[N].print();
  return 0;
}

