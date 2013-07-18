// Uses: disjoint-set union, geometry
//
// Let's use DSU. All points are initially in their own sets.
// For every road, union their points into one set because they're reachable
// from each other.
// Then, intersect all points and roads. For every intersection, union
// corresponding points into one set.
//
// If all points belong to one set, answer YES.

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 200;

// DSU
int parent[N];

void make_set(int v) {
  parent[v] = v;
}

int find_set(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) parent[b] = a;
}

// Line intersection functions

struct point {
	ll x, y;
};

struct road {
  int s1, s2;
};

ll area(point a, point b, point c) {
	ll result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if (result == 0) return 0;
  return result > 0 ? 1 : -1;
}

bool intersect_bbox(ll a, ll b, ll c, ll d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a,c) <= min(b,d);
}

bool intersect(point a, point b, point c, point d) {
  return intersect_bbox(a.x, b.x, c.x, d.x)
    && intersect_bbox(a.y, b.y, c.y, d.y)
    && area(a,b,c) * area(a,b,d) <= 0
    && area(c,d,a) * area(c,d,b) <= 0;
}


int main(int argc, char const *argv[])
{
  int n, m;
  cin >> n >> m;
  vector<point> points(n);
  vector<road> roads(m);
  for (int i = 0; i < n; i++) {
    make_set(i);
    cin >> points[i].x >> points[i].y;
  }
  for (int i = 0; i < m; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    roads[i].s1 = n1 - 1;
    roads[i].s2 = n2 - 1;
    union_sets(roads[i].s1, roads[i].s2);
  }

  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
      point a1 = points[roads[i].s1], b1 = points[roads[i].s2];
      point a2 = points[roads[j].s1], b2 = points[roads[j].s2];
      if (intersect(a1, b1, a2, b2)) union_sets(roads[i].s1, roads[j].s1);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      point a1 = points[roads[i].s1], b1 = points[roads[i].s2];
      if (intersect(points[j], points[j], a1, b1)) union_sets(roads[i].s1, j);
    }
  }

  int common = find_set(0);
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (find_set(i) != common) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
