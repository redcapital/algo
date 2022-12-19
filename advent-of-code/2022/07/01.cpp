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


int ans = 0;
struct Node {
	Node* parent;
	string name;
	int size = 0;
	vector<Node*> children;

	Node* addDir(const string& name) {
		Node* n = new Node;
		n->name = name;
		n->parent = this;
		children.push_back(n);
		return n;
	}

	void addFile(const string& name, int sz) {
		Node* n = new Node;
		n->name = name;
		n->parent = this;
		n->size = sz;
		children.push_back(n);
	}
};

int getsize(Node* n) {
	int sz = 0;
	//cerr << "At dir: " << n->name << endl;
	for (auto c: n->children) {
		if (c->size) {
			sz += c->size;
			//cerr << "  counting file: " << c->name << ", size: " << c->size << endl;
		} else {
			sz += getsize(c);
		}
	}
	if (sz <= 100000) ans += sz;
	return sz;
}

int main() {
  string s;
  Node root;
  root.name = "/";
  Node* current = &root;
  while (getline(cin, s)) {
	  if (s[0] == '$') {
		  if (s[2] == 'l') {
			  current->children.clear();
			  continue;
		  } else {
			  if (s[5] == '/') {
				  current = &root;
			  } else if (s[5] == '.') {
				  current = current->parent;
			  } else {
				  bool found = false;
				  string dir(s.substr(5));
				  for (auto c: current->children) {
					  if (c->name == dir) {
						  current = c;
						  found = true;
						  break;
					  }
				  }
				  if (!found) {
					  current = current->addDir(dir);
				  }
			  }
		  }
	  } else {
		  // listing
		  if (s[0] == 'd') {
			  current->addDir(s.substr(4));
		  } else {
			  int p = s.find(' ');
			  current->addFile(s.substr(p + 1), atoi(s.substr(0, p).c_str()));
		  }
	  }
  }
  getsize(&root);
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
