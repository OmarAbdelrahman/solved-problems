/*
ID: 1010
PROG: concom
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

#define sz(a) ((int)a.size())
#define max_t 102

int triples;
bool conn[max_t][max_t];
int val[max_t][max_t];

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	cin >> triples;
	for (int i = 0; i < triples; ++i) {
		int a, b; cin >> a >> b;
		cin >> val[a - 1][b - 1];
		if (val[a - 1][b - 1] > 50) 
			conn[a - 1][b - 1] = true;
	}
	bool ok = false;
	for (int a = 0; a < max_t; ++a) 
		conn[a][a] = true;
	do {
		ok = false;
		for (int a = 0; a < max_t; ++a) 
			for (int b = 0; b < max_t; ++b) {
				int sum = 0;
				if (!conn[a][b]) {
					sum = 0;
					for (int c = 0; c < max_t; ++c) 
						if (c != b && conn[a][c])
							sum += val[c][b];
				}
				if (sum > 50) conn[a][b] = ok = true;
		}
	} while (ok);
	for (int i = 0; i < max_t; ++i) 
		for (int j = 0; j < max_t; ++j)
			if (conn[i][j] && i != j) 
				cout << i + 1 << " " << j + 1 <<endl;
	return 0;
}