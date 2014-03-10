#include <iostream>
#include <string>
#include <map>

using namespace std;

struct user {
  bool logged;
  string pass;
  user() {}
  user(const string& _pass) : pass(_pass), logged(false) {}
};

int main(int argc, char const *argv[])
{
  int n;
  map<string, user> users;
  cin >> n;
  while (n--) {
    string op, name, pass;
    cin >> op >> name;
    if (op == "register") {
      cin >> pass;
      if (users.count(name) == 1) cout << "fail: user already exists" << endl;
      else {
        users[name] = user(pass);
        cout << "success: new user added" << endl;
      }
    } else if (op =="login") {
      cin >> pass;
      if (users.count(name) == 0) cout << "fail: no such user" << endl;
      else if (users[name].pass != pass) cout << "fail: incorrect password" << endl;
      else if (users[name].logged) cout << "fail: already logged in" << endl;
      else {
        users[name].logged = true;
        cout << "success: user logged in" << endl;
      }
    } else {
      if (users.count(name) == 0) cout << "fail: no such user" << endl;
      else if (!users[name].logged) cout << "fail: already logged out" << endl;
      else {
        users[name].logged = false;
        cout << "success: user logged out" << endl;
      }
    }
  }
  return 0;
}
