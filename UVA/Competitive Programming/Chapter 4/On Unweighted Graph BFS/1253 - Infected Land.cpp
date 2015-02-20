#include <bits/stdc++.h>
using namespace std;

struct io {
	template<class T>
	static inline T next() {
		T x; std::cin >> x;
		return x;
	}
};

const int dx[] = { -1, 1, -1, 1, 0, 0, 1, -1 };
const int dy[] = { 1, -1, -1, 1, -1, 1, 0, 0 };

struct state {
	int x, y;
	int c;
	int grid;

	state() { }

	state(int x, int y, int c, int g)
		: x(x), y(y), c(c), grid(g) { }
};

inline bool ok(const int x, const int y, const int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

inline int index(const int i, const int j, const int n) {
	return i * n + j;
}

template<typename Fun>
void for_each_adjacent(const int i, const int j, const int n, Fun f) {
	for (int d = 0; d < 8; ++d) {
		const int nx = i + dx[d];
		const int ny = j + dy[d];
		if (ok(nx, ny, n)) f(nx, ny);
	}
}

int process(const int x, const int y, const int n, const int old_grid) {
	int grid = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == x && j == y)
				continue;

			int count = 0;
			const int bit = index(i, j, n);
			for_each_adjacent(i, j, n, [&](const int nx, const int ny) {
				if ((old_grid & (1 << index(nx, ny, n))) || (nx == x && ny == y))
					++count;
			});
			if (count == 3)
				grid |= (1 << bit);
			else if (count == 2 && (old_grid & (1 << bit)))
				grid |= (1 << bit);
		}
	return grid;
}

int solve(const int sx, const int sy, const int src, const int trg, const int n) {
	set<tuple<int, int, int>> visited;
	visited.insert(make_tuple(sx, sy, src));

	queue<state> q;
	for (q.push(state(sx, sy, 0, src)); !q.empty(); q.pop()) {
		const state s = q.front();
		if (s.grid == trg)
			return s.c;
		for_each_adjacent(s.x, s.y, n, [&](const int x, const int y) {
			if (s.grid & (1 << index(x, y, n)))
				return;
			const int grid = process(x, y, n, s.grid);
			const tuple<int, int, int> next = make_tuple(x, y, grid);
			if (visited.find(next) == visited.end()) {
				visited.insert(next);
				q.push(state(x, y, s.c + 1, grid));
			}
		});
	}
	return -1;
}

int main(int argc, char** args) {
	for (int n; cin >> n && n; ) {
		int grid = 0;
		int x, y;
		for (int i = 0; i < n; ++i) {
			const string s = io::next<string>();
			for (int j = 0; j < n; ++j) {
				if (s[j] == '@')
					tie(x, y) = make_pair(i, j);
				else if (s[j] == '#')
					grid |= (1 << index(i, j, n));
			}
		}
		cout << solve(x, y, grid, 0, n) << endl;
	}
	return 0;
}
