#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	printf("Lumberjacks:\n");
	for (int c = 1; cases--; ++c) {
		vector<int> S(10), A(10), D(10);
		for (int i = 0; i < 10; ++i) {
			int n; scanf("%d", &n);
			S[i] = A[i] = D[i] = n;
		}
		sort(A.begin(), A.end());
		sort(D.begin(), D.end()));
		reverse(D.begin(), D.end());
		if (S == A || S == D)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}
	return 0;
}