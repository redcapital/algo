#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

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

const ll BASE = 4000000;
const ll MAXNUM = BASE * BASE;

struct segment {
	ll start, len;

	bool operator<(const segment& b) {
		if (start < b.start) return true;
		if (start > b.start) return false;
		return len < b.len;
	}
};

// - for all sensors, find the vertical lines that are covered by it
// - store those lines as intervals (start, length), where 
//     start = x * 4*10^6 + y, i.e. compress coordinates into a single 64bit number
//     length = length of that line in manhattan units
// - we need to merge overlapping intervals to find a gap between them that corresponds to the point we are searching
// - sort the intervals by (start, length) and merge them one by one until you find the gap
// - verify gap lies within the (0, 16*10^12) interval which corresponds to the search space
//     otherwise, continue merge process starting with this interval

int main() {
  vector<segment> segs;
  string s;
  while (getline(cin, s)) {
	  int sx,sy,bx,by;
	  sscanf(s.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &sx, &sy, &bx, &by);
	  int rad = abs(sx-bx) + abs(sy-by);
	  for (int x = sx - rad; x <= sx + rad; x++) {
		  int rem = rad - abs(x - sx);
		  int y = sy - rem;
		  segment seg;
		  seg.start = (ll)x * (ll)BASE + (ll)y;
		  seg.len = (ll)rem * 2 + (ll)1;
		  segs.push_back(seg);
	  }
  }
  sort(ALL(segs));
  ll is = segs[0].start, ie = segs[0].start + segs[0].len;
  for (const auto& seg: segs) {
	  if (seg.start <= ie) {
		  // intersect
		  ie = max(ie, seg.start + seg.len);
	  } else {
		  // gap
		  ll gs = ie;
		  ll ge = seg.start;
		  if ((gs >= 0 && gs <= MAXNUM) || (ge >= 0 && ge <= MAXNUM)) {
			  ll v = max(gs, (ll)0);
			  ll x = v / BASE;
			  ll y = v % BASE;
			  cout << x << ", " << y << ", " << v << endl;
			  return 0;
		  }

		  is = seg.start;
		  ie = seg.start + seg.len;
	  }
  }

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
