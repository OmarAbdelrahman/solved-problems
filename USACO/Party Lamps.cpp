/*
ID: 1010
PROG: lamps
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<numeric>
#include<string.h>
using namespace std;

#define equ(i) ((3 * i) + 1)
#define sz(a) ((int)a.size())

struct lamps_t {
	int lamp[110];
};

int n, c;
int C[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
lamps_t state[16];
map<int, bool> value;

lamps_t toggle(lamps_t a, int b) {
	lamps_t c = a;
	if (b == 1)
		for (int i = 0; i < n; ++i)
			c.lamp[i] = !c.lamp[i];
	else if (b == 2)
		for (int i = 0; i < n; i += 2)
			c.lamp[i] = !c.lamp[i];
	else if (b == 3)
		for (int i = 1; i < n; i += 2)
			c.lamp[i] = !c.lamp[i];
	else if (b == 4)
		for (int i = 0; i < n; i += 3)
			c.lamp[i] = !c.lamp[i];
	return c;
}

int bigger(lamps_t a, lamps_t b) {
	for (int i = 0; i < n; ++i)
		if (a.lamp[i] < b.lamp[i])
			return -1;
		else if (a.lamp[i] > b.lamp[i])
			return 1;
	return 0;
}

void check(lamps_t a, bool& ok) {
	for (map<int, bool>::iterator it = value.begin(); it != value.end(); it++)
		if (a.lamp[it->first] != it->second)
			return;
	ok = true;
	for (int i = 0; i < n; ++i)
		cout << a.lamp[i];
	cout << endl;
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	cin >> n >> c;
	int temp, i, j;
	while (cin >> temp && temp != -1)
		value[temp - 1] = true;
	while (cin >> temp && temp != -1)
		value[temp - 1] = false;
	fill(state[0].lamp, state[0].lamp + 110, 1);
	state[1] = toggle(state[0], 1);
	for (i = 2; i < 4; ++i) state[i] = toggle(state[i - 2], 2);
	for (i = 4; i < 8; ++i) state[i] = toggle(state[i - 4], 3);
	for (i = 8; i < 16; ++i) state[i] = toggle(state[i - 8], 4);
	for (i = 0; i < 16; ++i) for (j = i + 1; j < 16; ++j)
		if (bigger(state[i], state[j]) == 1)
			swap(state[i], state[j]), swap(C[i], C[j]);
	bool ok = false;
	for (i = 0; i < 16; ++i)
		if (C[i] <= c && ((c - C[i]) % 2 == 0))
			check(state[i], ok);
	if (!ok) printf("IMPOSSIBLE\n");
	return 0;
}