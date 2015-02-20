#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
	int initial, comb[3];
	while (scanf("%d%d%d%d", &initial, &comb[0], &comb[1], &comb[2]) != EOF) {
		if (!initial && !comb[0] && !comb[1] && !comb[2])
			break;
		int64 res = 0;
		res += 40;
		res += 40;
		res += 40;
		if (initial < comb[0])
			res += (initial + 40) - comb[0];
		else
			res += initial - comb[0];
		if (comb[0] < comb[1])
			res += comb[1] - comb[0];
		else
			res += (comb[1] + 40) - comb[0];
		if (comb[1] < comb[2])
			res += (comb[1] + 40) - comb[2];
		else
			res += comb[1] - comb[2];
		printf("%d\n", res * 9);
	}
	return 0;
}