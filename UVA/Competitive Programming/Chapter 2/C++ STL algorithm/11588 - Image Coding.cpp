#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int kases; cin >> kases;
	for (int c = 1; c <= kases; ++c) {
		int row, col, m, n; cin >> row >> col >> m >> n;
		string grid[20];
		map<char, int> values;
		for (int i = 0; i < row; ++i) {
			cin >> grid[i];
			for (int j = 0; j < col; ++j)
				++values[grid[i][j]];
		}
		int big = -1;
		for (map<char, int>::iterator it = values.begin(); it != values.end(); it++)
			big = max(big, it->second);
		int result = 0;
		for (map<char, int>::iterator it = values.begin(); it != values.end(); it++) {
			if (it->second == big)
				result += (it->second * m);
			else
				result += (it->second * n);
		}
		cout << "Case " << c << ": " << result << endl;
	}
	return 0;
}
