#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX 2000 + 5

int lis_len[MAX], lds_len[MAX];

inline void get_max(int &a, int b) {
	if (a < b) a = b;
}

void lds(int data[], int size) {
	int i, LDS = 1, res[MAX], *it;
	for (res[0] = data[0], i = 1; i < size; i++) {
		it = upper_bound(res, res + LDS, data[i], greater<int>());
		lds_len[i] = (int)(it - res) + 1;
		get_max(LDS, (int)(it - res) + 1);
		*it = data[i];
	}
}

void lis(int data[], int size) {
	int i, LIS = 1, res[MAX], *it;
	for (res[0] = data[0], i = 1; i < size; i++) {
		it = lower_bound(res, res + LIS, data[i]);
		lis_len[i] = (int)(it - res) + 1;
		get_max(LIS, (int)(it - res) + 1);
		*it = data[i];
	}
}

int main() {
	int TC; scanf("%d", &TC);
	int car[MAX];
	for (int n, i; TC--;) {
		scanf("%d", &n);
		if (!n) { puts("0"); continue; }
		for (i = 0; i < n; i++)
			scanf("%d", &car[n - i - 1]);
		lis(car, n);
		lds(car, n);
		int res = 1;
		for (i = 0; i < n; i++)
			get_max(res, lis_len[i] + lds_len[i] - 1);
		printf("%d\n", res);
	}
	return 0;
}