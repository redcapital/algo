#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define VI vector<int>
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORE(i,n) for(int i=0; i<=n; i++)
#define FOS(i,s,n) for(int i=s; i<n; i++)
#define FOSE(i,s,n) for(int i=s; i<=n; i++)
#define PRINTL(s) cout<<(s)<<endl
#define ALL(v) v.begin(),v.end()
#define CLEAR(v) memset(v,0,sizeof(v))

typedef long long ll;
typedef unsigned long long ull;

const int dd[4][2] = {
  { -1,  0 },
  {  0,  1 },
  {  1,  0 },
  {  0, -1 },
};


long long ans = 0;

// Instead of storing worry level as integer,
// store list of its remainders when divided by all possible divisors.

int mc;

struct Worry {
	map<int, int> rems;

	void add(int num) {
		for (auto &i: rems) {
			i.second = (i.second + num) % i.first;
		}
	}

	void mul(int num) {
		for (auto &i: rems) {
			i.second = (i.second * num) % i.first;
		}
	}

	void selfmul() {
		for (auto &i: rems) {
			i.second = (i.second * i.second) % i.first;
		}
	}

	bool isdivisible(int d) {
		if (rems.count(d) == 0) {
			cout << "WTF no key " << d << endl;
		}
		return rems[d] == 0;
	}

	void printout() {
		for (auto i:rems) {
			cout << " % " << i.first << " = " << i.second << endl;
		}
	}
};

struct Monkey {
	vector<int> items;
	vector<Worry> witems;
	char op;
	int num;
	bool self;
	int d;
	int t_true, t_false;
	int inspect_count = 0;

	void calcworry(Worry& witem) {
		switch (op) {
			case '+':
				witem.add(num);
				break;
			case '*':
				if (self) {
					witem.selfmul();
				} else {
					witem.mul(num);
				}
				break;
		}
	}

	bool operator<(const Monkey& b) {
		return inspect_count > b.inspect_count;
	}
} m[100];

void monkeygo(int idx) {
	int sz = m[idx].witems.size();
	for (auto i: m[idx].witems) {
		m[idx].calcworry(i);
		int target = i.isdivisible(m[idx].d) ? m[idx].t_true : m[idx].t_false;
		m[target].witems.push_back(i);
	}
	m[idx].inspect_count += sz;
	m[idx].witems.clear();
}

void fillworries(int idx) {
	for(auto j: m[idx].items) {
		Worry w;
		FOR(i,mc) {
			w.rems[m[i].d] = j % m[i].d;
		}
		m[idx].witems.push_back(w);
	}
}


int main() {
  string s;
  mc = 0;
  while (getline(cin, s)) {
	  if (s.empty()) {
		  mc++;
		  continue;
	  }
	  if (s[2] == 'S') {
		  int p = s.find(':');
		  while (p != string::npos) {
			  int num;
			  p += 2;
			  if (p < s.size()) {
				  int com = s.find(',', p);
				  if (com == string::npos) {
					  num = atoi(s.substr(p).c_str());
				  } else {
					  num = atoi(s.substr(p, com - p).c_str());
				  }
				  m[mc].items.push_back(num);
				  p = com;
			  } else {
				  break;
			  }
		  }
	  } else if (s[2] == 'O') {
		  if (s[25] == 'o') {
			  m[mc].self = true;
			  sscanf(s.c_str(), "  Operation: new = old %c", &m[mc].op);
		  } else {
			  m[mc].self = false;
			  sscanf(s.c_str(), "  Operation: new = old %c %d", &m[mc].op, &m[mc].num);
		  }
	  } else if (s[2] == 'T') {
		  sscanf(s.c_str(), "  Test: divisible by %d", &m[mc].d);
	  } else if (s[4] == 'I' && s[7] == 't') {
		  sscanf(s.c_str(), "    If true: throw to monkey %d", &m[mc].t_true);
	  } else if (s[4] == 'I' && s[7] == 'f') {
		  sscanf(s.c_str(), "    If false: throw to monkey %d", &m[mc].t_false);
	  }
  }
  mc++;

  FOR(i,mc) {
	  fillworries(i);
  }

  FOR(i,10000) {
	  FOR(j,mc) {
		  monkeygo(j);
	  }
  }

  FOR(i,mc) {
	  //cout << "Monkey " << i << endl;
	  //cout << "Items: ";
	  //for (auto ii: m[i].items) cout << ii << ", ";
	  //cout << endl;
	  //cout << "OP: " << m[i].op << ", is self: " << m[i].self << ", num: " << m[i].num << endl;
	  //cout << "Div by: " << m[i].d << endl;
	  //cout << "True go: " << m[i].t_true << endl;
	  //cout << "False go: " << m[i].t_false << endl;
	  //PRINTL(m[i].inspect_count);
  }
  sort(m, m + mc);
  ans = (long long)m[0].inspect_count * (long long)m[1].inspect_count;

  PRINTL(ans);
  return 0;
}

/*

// comma separated
int x;
vector<int> a;
while (cin >> x) {
  a.push_back(x);
  if (cin.peek() == ',') cin.ignore();
}

// line by line
string s;
while (getline(cin, s)) {

}
*/
