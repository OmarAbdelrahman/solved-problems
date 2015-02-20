/*
ID: 1010
PROG: rect1
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define MAXR 1001

struct point_t {
	point_t() {}
	point_t(int _x, int _y)
		: x(_x), y(_y) {}
	int x, y;
};

struct rectangle_t {
	rectangle_t() {}
	rectangle_t(point_t _s, point_t _e, int _c)
		: s(_s), e(_e), c(_c) {}
	point_t s, e;
	int c;
};

int w, h, total;
rectangle_t rectangle[MAXR];
map<int, int> res;

inline int area(point_t& p1, point_t& p2) {
	return abs(p1.x - p2.x) * abs(p1.y - p2.y);
}

void solve(int indx, point_t s, point_t e, int color) {
	while (indx <= total && (s.x > rectangle[indx].e.x || s.y > rectangle[indx].e.y ||
		   e.x < rectangle[indx].s.x || e.y < rectangle[indx].s.y)) 
		indx++;
	if (indx > total) {
		res[color] += area(s, e);
		return;
	}
	if (s.x <= rectangle[indx].s.x) {
		solve(indx + 1, point_t(s.x, s.y), point_t(rectangle[indx].s.x, e.y), color);
		s.x = rectangle[indx].s.x;
	}
	if (s.y <= rectangle[indx].s.y) {
		solve(indx + 1, point_t(s.x, s.y), point_t(e.x, rectangle[indx].s.y), color);
		s.y = rectangle[indx].s.y;
	}
	if (e.x >= rectangle[indx].e.x) {
		solve(indx + 1, point_t(rectangle[indx].e.x, s.y), point_t(e.x, e.y), color);
		e.x = rectangle[indx].e.x;
	}
	if (e.y >= rectangle[indx].e.y) {
		solve(indx + 1, point_t(s.x, rectangle[indx].e.y), point_t(e.x, e.y), color);
		e.y = rectangle[indx].e.y;
	}
}

int main() {
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	cin >> w >> h >> total;
	rectangle[0] = rectangle_t(point_t(0, 0), point_t(w, h), 1);
	for (int i = 1; i <= total; ++i)
		cin >> rectangle[i].s.x >> rectangle[i].s.y >> rectangle[i].e.x >> rectangle[i].e.y >> rectangle[i].c;
	for (int i = total; i >= 0; --i)
		solve(i + 1, rectangle[i].s, rectangle[i].e, rectangle[i].c);
	for (map<int, int>::iterator it = res.begin(); it != res.end(); it++)
		if (it->second) cout << it->first << " " << it->second << endl;
	return 0;
}