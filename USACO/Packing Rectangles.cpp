/*
ID: 1010
PROG: packrec
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;

bool vis[4] = {0};
set<pair<int, pair<int, int> > > a;
vector<pair<int, int> > g(4), rect(4);

void _1() {
	int w = g[0].first + g[1].first + g[2].first + g[3].first;
	int h = max(max(g[0].second, g[1].second), max(g[2].second, g[3].second));
	if (w > h) swap(w, h);
	a.insert(make_pair(w * h, make_pair(w, h)));
}

void _2() {
	int h = g[0].first + max(max(g[1].second, g[2].second), g[3].second);
	int w = max(g[0].second, g[1].first + g[2].first + g[3].first);
	if (w > h) swap(w, h);
	a.insert(make_pair(w * h, make_pair(w, h)));
}

void _3() {
	int h = max(g[3].second, max(g[1].second, g[2].second) + g[0].first);
	int w = g[3].first + max(g[0].second, g[1].first + g[2].first);
	if (w > h) swap(w, h);
	a.insert(make_pair(w * h, make_pair(w, h)));
}

void _5() {
	int h = max(g[1].second + g[2].second, max(g[0].second, g[3].second));
	int w = g[0].first + g[3].first + max(g[1].first, g[2].first);
	if (w > h) swap(w, h);
	a.insert(make_pair(w * h, make_pair(w, h)));
}

void _6() {
	int h = max(g[0].second + g[2].second, g[1].second + g[3].second), w;
	if (g[0].second == g[1].second) {
		w = max(g[0].first + g[1].first, g[2].first + g[3].first);
	} else if (g[0].second < g[1].second) {
		if (g[1].first >= g[3].first) {
			w = max(g[0].first + g[1].first, g[2].first + g[1].first);
		} else {
			if (g[0].second + g[2].second <= g[1].second)
				w = max(g[0].first + g[1].first, max(g[2].first + g[1].first, g[3].first));
			else
				w = max(g[0].first + g[1].first, g[2].first + g[3].first);
		}
	} else {
		if (g[0].first >= g[2].first) {
			w = max(g[0].first + g[1].first, g[0].first + g[3].first);
		} else {
			if (g[1].second + g[3].second <= g[0].second)
				w = max(g[0].first + g[1].first, max(g[0].first + g[3].first, g[2].first));
			else
				w = max(g[0].first + g[1].first, g[2].first + g[3].first);
		}
	}
	if (w > h) swap(w, h);
	a.insert(make_pair(w * h, make_pair(w, h)));
}

pair<int, int> rotate(pair<int, int> rect) {
	return make_pair(rect.second, rect.first);
}

void permute(int level = 0) {
	if (level == 4) {
		for (int w = 0; w < 2; ++w, g[0] = rotate(g[0]))
			for (int x = 0; x < 2; ++x, g[1] = rotate(g[1]))
				for (int y = 0; y < 2; ++y, g[2] = rotate(g[2]))
					for (int z = 0; z < 2; ++z, g[3] = rotate(g[3]))
						_1(), _2(), _3(), _5(), _6();
	}
	else for (int i = 0; i < 4; ++i)
		if (!vis[i]) {
			g[level] = rect[i];
			vis[i] = 1;
			permute(level + 1);
			vis[i] = 0;
		}
}

int main() {
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	for (int i = 0; i < 4; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		g[i] = rect[i] = make_pair(a, b);
	}
	permute();
	int mini = a.begin()->first;
	printf("%d\n", mini);
	for (set<pair<int, pair<int, int> > >::iterator it = a.begin(); it != a.end(); it++)
		if (it->second.first * it->second.second == mini)
			printf("%d %d\n", it->second.first, it->second.second);
		else break;
	return 0;
}