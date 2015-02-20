#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

typedef unsigned long long ull;

struct state {
	state() {}
	state(ull b, int s)
		: board(b), steps(s) {}
	int steps;
	ull board;
};

int const dx[] = { -1, 1, 0, 0 };
int const dy[] = { 0, 0, -1, 1 };

set<ull> visited_src;
set<ull> visited_trg;

static inline bool ok(int const& n, int const& m) {
	return n >= 0 && n < 8 && m >= 0 && m < 8;
}

static void fill_src(ull const& src) {
	queue<state> q;
	for (q.push(state(src, 0)), visited_src.insert(src); !q.empty(); q.pop()) {
		ull board = q.front().board;
		int steps = q.front().steps;
		if (steps == 4)
			continue;
		for (int i = 0; i < 64; ++i)  if (board & ((ull)1 << i)) {
			int r = i / 8, c = i % 8;
			for (int k = 0; k < 4; ++k) {
				int nx = r + dx[k], ny = c + dy[k];
				if (!ok(nx, ny)) continue;
				int new_pos = nx * 8 + ny;
				if (!(board & ((ull)1 << new_pos))) {
					ull new_board = board ^ ((ull)1 << i) ^ ((ull)1 << new_pos);
					if (visited_src.find(new_board) == visited_src.end()) {
						visited_src.insert(new_board);
						q.push(state(new_board, steps + 1));
					}
				} else {
					int n2x = r + dx[k] * 2, n2y = c + dy[k] * 2;
					if (!ok(n2x, n2y)) continue;
					int new2_pos = n2x * 8 + n2y;
					if (!(board & ((ull)1 << new2_pos))) {
						ull new2_board = board ^ ((ull)1 << i) ^ ((ull)1 << new2_pos);
						if (visited_src.find(new2_board) == visited_src.end()) {
							visited_src.insert(new2_board);
							q.push(state(new2_board, steps + 1));
						}
					}
				}
			}
		}
	}
}

static bool doit(ull const& trg) {
	queue<state> q;
	for (q.push(state(trg, 0)), visited_trg.insert(trg); !q.empty(); q.pop()) {
		ull board = q.front().board;
		int steps = q.front().steps;
		if (steps == 4) {
			if (visited_src.find(board) != visited_src.end())
				return true;
			else
				continue;
		}
		for (int i = 0; i < 64; ++i) if (board & ((ull)1 << i)) {
			int r = i / 8, c = i % 8;
			for (int k = 0; k < 4; ++k) {
				int nx = r + dx[k], ny = c + dy[k];
				if (!ok(nx, ny)) continue;
				int new_pos = nx * 8 + ny;
				if (!(board & ((ull)1 << new_pos))) {
					ull new_board = board ^ ((ull)1 << new_pos) ^ ((ull)1 << i);
					if (visited_trg.find(new_board) == visited_trg.end()) {
						visited_trg.insert(new_board);
						q.push(state(new_board, steps + 1));
					}
				} else {
					int n2x = r + dx[k] * 2, n2y = c + dy[k] * 2;
					if (!ok(n2x, n2y)) continue;
					int new2_pos = n2x * 8 + n2y;
					if (!(board & ((ull)1 << new2_pos))) {
						ull new2_board = board ^ ((ull)1 << i) ^ ((ull)1 << new2_pos);
						if (visited_trg.find(new2_board) == visited_trg.end()) {
							visited_trg.insert(new2_board);
							q.push(state(new2_board, steps + 1));
						}
					}
				}
			}
		}
	}
	return false;
}

int main(int argc, char **args) {
	int TC, a, b; scanf("%d", &TC);
	while (TC-- > 0) {
		visited_src.clear();
		visited_trg.clear();
		ull src = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%d%d", &a, &b);
			--a, --b;
			src |= ((ull)1 << (a * 8 + b));
		}
		fill_src(src);
		ull trg = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%d%d", &a, &b);
			--a, --b;
			trg |= ((ull)1 << (a * 8 + b));
		}
		printf(doit(trg) ? "YES\n" : "NO\n");
	}
	return 0;
}