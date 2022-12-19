#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;

typedef short int CardValue;
typedef list<CardValue> Deck;
typedef pair<Deck, Deck> GameState;

Deck d[2];

// Returns true if player 1 wins
bool play_game(Deck& d1, Deck& d2) {
  set<GameState> states;
  while (true) {
    GameState gs(d1, d2);
    if (states.count(gs) > 0) {
      return true;
    }
    states.insert(gs);

    bool w1;
    auto x1 = *d1.begin();
    auto x2 = *d2.begin();
    d1.pop_front();
    d2.pop_front();

    if (d1.size() >= x1 && d2.size() >= x2) {
      Deck sd1(d1);
      Deck sd2(d2);
      for (int c = x1; c < d1.size(); c++) sd1.pop_back();
      for (int c = x2; c < d2.size(); c++) sd2.pop_back();
      w1 = play_game(sd1, sd2);
    } else {
      w1 = (x1 > x2);
    }

    if (w1) {
      d1.push_back(x1);
      d1.push_back(x2);
      if (d2.empty()) {
        return true;
      }
    } else {
      d2.push_back(x2);
      d2.push_back(x1);
      if (d1.empty()) {
        return false;
      }
    }
  }
}

int main() {
  string s;
  int curp;
  while (getline(cin, s)) {
    if (s.empty()) continue;
    if (s[0] == 'P') {
      sscanf(s.c_str(), "Player %d", &curp);
      curp--;
    } else {
      int tmp;
      sscanf(s.c_str(), "%d", &tmp);
      d[curp].push_back(tmp);
    }
  }

  curp = play_game(d[0], d[1]) ? 0 : 1;

  int ans = 0, mul = 1;
  for (auto it = d[curp].rbegin(); it != d[curp].rend(); it++, mul++) {
    ans += *it * mul;
  }

  cout << "Ans: " << ans << endl;

  return 0;
}

