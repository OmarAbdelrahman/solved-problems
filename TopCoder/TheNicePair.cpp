#include <bits/stdc++.h>
using namespace std;

class TheNicePair {
public:
	int solve(vector<int> A) {
		const int n = A.size();
		const int m = *max_element(A.begin(), A.end());

		int result = -1;
		for (int v = 2; v <= m; ++v) {
			for (int i = 0; i < n; ++i) {
				int balance = 0;
				for (int j = i; j < n; ++j) {
					if (A[j] % v == 0) {
						++balance;
					} else {
						--balance;
					}
					if (balance >= 0) {
						result = max(result, j - i);
					}
				}
			}
		}
		return result;
	}
};
