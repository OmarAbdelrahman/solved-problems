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

int const MAX = 105;
int const INF = 0x3f3f3f3f;

struct info {
	int src, start;
	int end, trg;
	info() {}
	info(int src, int start, int end, int trg) {
		this->src = src;
		this->start = start;
		this->end = end;
		this->trg = trg;
	}
};

int infoSize;
info information[MAX];
map<int, int> val;
int key[MAX];
int cost[MAX][MAX];

bool source(int src) {
	for (int i = 0; i < infoSize; ++i)
		if (src == information[i].src) return true;
	return false;
}

int get(int t, int src) {
	if (!source(src)) return src;
	int n = val.size();
	for (int i = 0; i <= n; ++i)
		fill(cost[i], cost[i] + (n + 1), INF);
	for (int i = 0; i < infoSize; ++i)
		if (t >= information[i].start && t <= information[i].end)
			cost[val[information[i].src]][val[information[i].trg]] = 1;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
	src = val[src];
	if (cost[src][src] != INF)
		return 9999;
	int big = -1;
	int index = -1;
	for (int i = 1; i <= n; ++i) {
		int value = cost[src][val[key[i]]];
		if (value != INF && value > big) {
			big = value;
			index = i;
		}
	}
	if (index == -1) return key[src];
	return key[index];
}

int main() {
	int T; scanf("%d", &T);
	puts("CALL FORWARDING OUTPUT");
	for (int c = 1; T--; ++c) {
		val = map<int, int>();
		infoSize = 0;
		int value = 1;
		for (int s; scanf("%d", &s) && s != 0;) {
			information[infoSize].src = s;
			scanf("%d%d%d", &information[infoSize].start, &information[infoSize].end, &information[infoSize].trg);
			information[infoSize].end += information[infoSize].start; 
			if (val[information[infoSize].src] == 0) {
				val[information[infoSize].src] = value;
				key[value] = information[infoSize].src;
				++value;
			}
			if (val[information[infoSize].trg] == 0) {
				val[information[infoSize].trg] = value;
				key[value] = information[infoSize].trg;
				++value;
			}
			++infoSize;
		}
		printf("SYSTEM %d\n",c);
		for (int t, e; scanf("%d", &t) && t != 9000;) {
			scanf("%d", &e);
			printf("AT %04d CALL TO %04d RINGS %04d\n", t, e, get(t, e));
		}
	}
	puts("END OF OUTPUT");
	return 0;
}