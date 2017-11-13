#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
	int cases; scanf("%d", &cases);
	int size, n, degree, farmers;
	while (cases--) {
		scanf("%d", &farmers);
		int64 res = 0;
		for (int i = 0; i < farmers; ++i) {
			scanf("%d%d%d", &size, &n, &degree);
			res += (int64)size * (int64)degree;
		}
		printf("%ld\n", res);
	}
	return 0;
}