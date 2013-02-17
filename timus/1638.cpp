// The problem authors make some super-stupid assumptions in my opinion.
// Sample test case shows that first page of a book is on right side of book
// when it is placed on shelf, so placement looks like this:
//
// CPPPC CPPPC CPPPC
//    ^         ^
//    |         |
//   First     Last
//   page      page
//
// ( C means cover, P means pages )
//
// That's why the answer for sample test is 2.
//
// How the hell are we supposed to know this fact? I read quite a lot of books
// and I used to place books in a way opposite to the problem authors'
// (first page on left side), I know it's kind of weird but I don't see
// anything wrong with it. Furthermore, user Bogatyr left this comment:
//
// > In some languages, the "first page" of a book is on the left side of the
// > book when the book is placed on a shelf.   In which case "10 1 1 2" == 22.
//
// Not a big deal, but I HATE when problem authors make such assumptions
// and also don't bother to clarify it in comments.
// If something is obvious to you it doesn't necessarily mean it's obvious to
// EVERYONE. After all, knowing this fact isn't important to solve this
// problem, so why the f*ck don't you explain it in detail?
//
// Almost all comments are related to this confusing fact.

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int p, c, a, b, r = 0;
  cin >> p >> c >> a >> b;
  if (a < b) {
    r = c * 2 + (c * 2 + p) * (b - a - 1);
  } else {
    r = p + (c * 2 + p) * (a - b);
  }
  cout << r << endl;
  return 0;
}
