#include <bits/stdc++.h>
using namespace std;

class RandomPancakeStackDiv2 {
public:
	double f(const int mask, const int width, const int sum, const int size, const vector<int>& d) {
		if (size == 0) {
			return sum;
		}
		double result = 0.0;
		for (int i = 0; i < d.size(); ++i) {
			if (mask & (1 << i)) {
				continue;
			}
			if (i < width) {
				result += f(mask | (1 << i), i, sum + d[i], size - 1, d) / size;
			} else {
				result += (sum * 1.0 / size);
			}
		}
		return result;
	}

	double expectedDeliciousness(vector<int> d) {
		const int n = d.size();

		double result = 0.0;
		for (int i = 0; i < n; ++i) {
			result += f(1 << i, i, d[i], n - 1, d) / n;
		}
		return result;
	}
};