#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int input[10000 + 5];

int main() {
	int cases; scanf("%d", &cases);
	for (int n; cases--;) {
		scanf("%d", &n);
		int total = 0;
		bool negative = false;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &input[i]);
			total += input[i];
			negative |= input[i] < 0;
		}
		if (total & 1 || (n == 1 && input[1] > 0) || negative) {
			puts("No");
			continue;
		}
		sort(input + 1, input + n + 1, greater<int>());
		bool ok = true;
		for (int k = 1; k <= n; ++k) {
			int res = 0, cur_sum = 0;
			for (int i = 1; i <= k; ++i)
				cur_sum += input[i];
			for (int i = k + 1; i <= n; ++i)
				res += input[i] < k ? input[i] : k;
			ok &= (cur_sum <= (k * (k - 1) + res));
		}
		if (ok)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}