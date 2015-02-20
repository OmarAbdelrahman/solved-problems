#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define REP(i, n) for (int i = 0; i < n; ++i)

int matrix[101][101];

int main() {
	for (int n; cin >> n && n;) {
		REP(i, n) REP(j, n) cin >> matrix[i][j];
		int r = 0, c = 0;
		int odd_row = -1;
		int odd_col = -1;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			REP(j, n) sum += matrix[i][j];
			if (sum & 1) {
				odd_row = i + 1;
				++r;
			}
		}
		for (int j = 0; j < n; ++j) {
			int sum = 0;
			REP(i, n) sum += matrix[i][j];
			if (sum & 1) {
				odd_col = j + 1;
				++c;
			}
		}
		if (!r && !c)
			cout << "OK";
		else if (r == 1 && c == 1)
			cout << "Change bit " << "(" << odd_row << "," << odd_col << ")";
		else
			cout << "Corrupt";
		cout << endl;
	}
	return 0;
}