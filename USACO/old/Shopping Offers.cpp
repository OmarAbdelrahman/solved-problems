/*
ID: 1010
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
using namespace std;

#define MAX 1000

struct Offer {
	int price, amount[5];
	Offer() {
		memset(amount, 0, sizeof(amount));
	}
};

struct Item {
	int amount, price;
	Item() {}
};

Offer offers[100];
Item goods[5];
map<int, int> code;

int solve(int n) {
	int res[6][6][6][6][6];
	memset(res, 0, sizeof(res));
	for (int a = 0; a <= goods[0].amount; ++a)
		for (int b = 0; b <= goods[1].amount; ++b)
			for (int c = 0; c <= goods[2].amount; ++c)
				for (int d = 0; d <= goods[3].amount; ++d)
					for (int e = 0; e <= goods[4].amount; ++e) {
						int& ret = res[a][b][c][d][e];
						ret = a * goods[0].price + b * goods[1].price + c * goods[2].price + d * goods[3].price + e * goods[4].price;
						for (int j = 0; j < n; ++j)
							if (offers[j].amount[0] <= a && offers[j].amount[1] <= b && offers[j].amount[2] <= c && offers[j].amount[3] <= d && offers[j].amount[4] <= e) {
								ret = min(ret, res[a - offers[j].amount[0]][b - offers[j].amount[1]][c - offers[j].amount[2]][d - offers[j].amount[3]][e - offers[j].amount[4]] + offers[j].price);
							}
					}
	return res[goods[0].amount][goods[1].amount][goods[2].amount][goods[3].amount][goods[4].amount];
}

int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	int cnt = 0;
	int special; cin >> special;
	for (int i = 0; i < special; ++i) {
		int n; cin >> n;
		for (int j = 0; j < n; ++j) {
			int c, k; cin >> c >> k;
			if (!code.count(c)) code[c] = cnt++;
			offers[i].amount[code[c]] = k;
		}
		cin >> offers[i].price;
	}
	int required; cin >> required;
	for (int i = 0; i < required; ++i) {
		int c, k, p; cin >> c >> k >> p;
		if (!code.count(c)) code[c] = cnt++;
		goods[code[c]].amount = k;
		goods[code[c]].price = p;
	}
	cout << solve(special) << endl;
	return 0;
}