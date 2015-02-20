/*
ID: 1010
PROG: cowtour
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

#define sz(a) ((int)a.size())
#define maxT 151
#define e(x1, x2, y1, y2) hypot(x1 - x2, y1 - y2)

int nodes;
int x[maxT];
int y[maxT];
double warshal[maxT][maxT];
double distances[maxT];

template<class T> inline void getMax(T& a, T b) { if (b > a) a = b; }
template<class T> inline void getMin(T& a, T b) { if (b < a) a = b; }

int main() {
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	cin >> nodes;
	for (int i = 0; i < nodes; ++i) {
		int a, b; cin >> a >> b;
		x[i] = a, y[i] = b;
	}
	for (int i = 0; i < nodes; ++i)
		for (int j = 0; j < nodes; ++j) {
			char ch; cin >> ch;
			if (ch - '0') {
				warshal[i][j] = e(x[i], x[j], y[i], y[j]);
			} else {
				warshal[i][j] = HUGE_VALF;
			}
			if (j == i) warshal[i][j] = 0.;
		}
	for (int k = 0; k < nodes; ++k)
		for (int i = 0; i < nodes; ++i)
			for (int j = 0; j < nodes; ++j) {
				getMin(warshal[i][j], warshal[i][k] + warshal[k][j]);
			}
	for (int i = 0; i < nodes; ++i)
		for (int j = 0; j < nodes; ++j)
			if (warshal[i][j] != HUGE_VALF) {
				getMax(distances[i], warshal[i][j]);
			}
	double res = HUGE_VALF;
	for (int i = 0; i < nodes; ++i)
		for (int j = 0; j < nodes; ++j)
			if (warshal[i][j] == HUGE_VALF) {
				getMin(res, e(x[i], x[j], y[i], y[j]) + distances[i] + distances[j]);
			}
	for (int i = 0; i < nodes; ++i) getMax(res, distances[i]);
	printf("%.6lf\n", res);
	return 0;
}
