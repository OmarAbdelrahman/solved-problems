#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

inline void get_max(int &a, int b) {
	if (a < b) a = b;
}

int main() {
	vector<int> data, A, pos;
	vector<int>::iterator it;
	for (int n; scanf("%d", &n) != EOF; data.push_back(n));
	A.push_back(data[0]);
	pos = vector<int>(data.size(), 0);
	int i, n = data.size(), LIS = 1;
	for (i = 1; i < n; ++i) {
		it = lower_bound(A.begin(), A.end(), data[i]);
		pos[i] = (int)(it - A.begin());
		get_max(LIS, pos[i]);
		if (it == A.end())
			A.push_back(data[i]);
		else
			*it = data[i];
	}
	for (i = n - 1; i >= 0; --i)
		if (pos[i] == LIS)
			A[LIS--] = data[i];
	printf("%d\n-\n", (int)A.size());
	for (i = 0; i < A.size(); ++i)
		printf("%d\n", A[i]);
	return 0;
}