#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 10000 + 5

int grid[MAX];

int main() {
	int res, sum;
	for (int n; scanf("%d", &n) && n != 0;) {
		REP(i, n) scanf("%d", &grid[i]);
		res = -0x3f3f3f3f;
		sum = 0;
		REP(i, n) {
			sum += grid[i];
			if (sum < 0) sum = 0;
			if (sum > res) res = sum;
		}
		if (res <= 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", res);
	}
	return 0;
}