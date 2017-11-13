#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int64;
int const MAX = 10000 + 5;

int input[MAX];

int main() {
	for (int n; scanf("%d", &n) && n;) {
		int total = 0;
		bool negative = false;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &input[i]);
			total += input[i];
			negative |= input[i] < 0;
		}
		if (total & 1 || (n == 1 && input[1] > 0) || negative) {
			puts("Not possible");
			continue;
		}
		sort(input + 1, input + n + 1, greater<int>());
		bool ok = true;
		for (int k = 1; k <= n; ++k) {
			int64 res = 0, cur_sum = 0;
			for (int i = 1; i <= k; ++i)
				cur_sum += input[i];
			for (int i = k + 1; i <= n; ++i)
				res += min(input[i], k);
			ok &= (cur_sum <= (k * (k - 1) + res));
		}
		if (ok)
			puts("Possible");
		else
			puts("Not possible");
	}
	return 0;
}