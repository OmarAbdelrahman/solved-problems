#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define MAX 3

bool win(vector<string> G, char ch) {
	int r = 0, c = 0;
	if (G[r][c] == ch && G[r][c + 1] == ch && G[r][c + 2] == ch)
		return true;
	else if (G[r + 1][c] == ch && G[r + 1][c + 1] == ch && G[r + 1][c + 2] == ch)
		return true;
	else if (G[r + 2][c] == ch && G[r + 2][c + 1] == ch && G[r + 2][c + 2] == ch)
		return true;
	else if (G[r][c] == ch && G[r + 1][c] == ch && G[r + 2][c] == ch)
		return true;
	else if (G[r][c + 1] == ch && G[r + 1][c + 1] == ch && G[r + 2][c + 1] == ch)
		return true;
	else if (G[r][c + 2] == ch && G[r + 1][c + 2] == ch && G[r + 2][c + 2] == ch)
		return true;
	else if (G[r][c] == ch && G[r + 1][c + 1] == ch && G[r + 2][c + 2] == ch)
		return true;
	else if (G[r][c + 2] == ch && G[r + 1][c + 1] == ch && G[r + 2][c] == ch)
		return true;
	else return false;
}

string solve(vector<string> G, int x, int o) {
	if (win(G, 'X')) {
		if (x - 1 == o) return "yes";
		else return "no";
	}
	if (win(G, 'O')) {
		if (x == o) return "yes";
		else return "no";
	}
	return x == o + 1 || x == o ? "yes" : "no";
}

int main() {
	int t; cin >> t;
	while (t--) {
		vector<string> grid(MAX);
		for (int a = 0; a < MAX; ++a)
			cin >> grid[a];
		int x = 0, o = 0;
		for (int a = 0; a < MAX; ++a)
			for (int b = 0; b < MAX; ++b) {
				if (grid[a][b] == 'O') ++o;
				if (grid[a][b] == 'X') ++x;
			}
		cout << solve(grid, x, o) << endl;
	}
	return 0;
}