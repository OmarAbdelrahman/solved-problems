#include <bits/stdc++.h>
using namespace std;

int dp[61][61][61];
vector<int> p = { 1, 3, 9 };

class MutaliskEasy {
public:
    int solve(int a, int b, int c) {
        a = max(a, 0);
        b = max(b, 0);
        c = max(c, 0);
        if (a == 0 && b == 0 && c == 0) {
            return 0;
        }
        int& result = dp[a][b][c];
        if (result != -1) {
            return result;
        }
        result = numeric_limits<int>::max() >> 1;
        do {
            result = min(result, solve(a - p[0], b - p[1], c - p[2]) + 1);
        } while (next_permutation(p.begin(), p.end()));
        return result;
    }

	int minimalAttacks(vector<int> x) {
		const int n = x.size();
        if (n == 1) {
            return x[0] / 9 + (int) (x[0] % 9 != 0);
        } else if (n == 2) {
            int result = numeric_limits<int>::max();
            for (int a = 0; a <= 20; ++a) {
                for (int b = 0; b <= 20; ++b) {
                    if (a * 9 + b * 3 >= x[0] && a * 3 + b * 9 >= x[1]) {
                        result = min(result, a + b);
                    }
                }
            }
            return result;
        }
        memset(dp, -1, sizeof dp);
        return solve(x[0], x[1], x[2]);
	}
};

