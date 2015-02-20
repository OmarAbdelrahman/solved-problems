/*
ID: 1010
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define sz(a) ((int)a.size())

struct state_t {
	state_t() {}
	state_t(int _a, int _b, int _c)
		: a(_a), b(_b), c(_c) {}
	bool operator < (const state_t s) const {
		if (this->a == s.a)
			return this->b < s.b;
		return this->a < s.a;
	}
	int a, b, c;
};

int w, h;
pair<int, int> goals[2];
string* board;
bool vis[202][50];
int const oo = 0x3f3f3f3f;

template<class T> inline void get_min(T& a, T b) {
	if (b < a) a = b;
}

template<class T> inline void get_max(T& a, T b) {
	if (b > a) a = b;
}

inline bool ok(int x, int y) {
	return board[x][y] == ' ';
}

inline bool in(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

void bfs(pair<int, int> s, map<pair<int, int>, int>& m) {
	queue<state_t> q;
	q.push(state_t(s.first, s.second, 1));
	memset(vis, false, sizeof(vis));
	while (!q.empty()) {
		state_t nw = q.front(); q.pop();
		if (vis[nw.a][nw.b]) continue;
		vis[nw.a][nw.b] = true;
		get_min(m[make_pair(nw.a, nw.b)], nw.c);
		for (int dx = -1; dx <= 1; ++dx) 
			for (int dy = -1; dy <= 1; ++dy)
				if ((dx == 0) ^ (dy == 0)) {
					int _x = nw.a + dx, _y = nw.b + dy;
					if (in(_x, _y)) if (ok(_x, _y)) {
						_x += dx, _y += dy;
						if (in(_x, _y) && !vis[_x][_y])
							q.push(state_t(_x, _y, nw.c + 1));
					}
				}
	}
}

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	cin >> w >> h;
	w *= 2, ++w;
	h *= 2, ++h;
	int index = 0;
	board = new string[h];
	cin.ignore();
	for (int i = 0; i < h; ++i) {
		getline(cin, board[i]);
		if (i == 0 || i == h - 1) {
			for (int j = 0; j < w; ++j) 
				if (board[i][j] == ' ')
					goals[index++] = make_pair(i == 0 ? i + 1 : i - 1, j);
		}
	}
	for (int i = 0; i < h; ++i) {
		if (board[i][0] == ' ') 
			goals[index++] = make_pair(i, 1);
		if (board[i][w - 1] == ' ') 
			goals[index++] = make_pair(i, w - 2);
	}
	map<pair<int, int>, int> m;
	for (int i = 1; i < h; i += 2) 
		for (int j = 1; j < w; j += 2)
			m[make_pair(i, j)] = oo;
	for (int i = 0; i < index; ++i) bfs(goals[i], m);
	int answer = -1;
	for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); it++)
		get_max(answer, it->second);
	cout << answer << endl;
	return 0;
}