#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

int main() {
	int n, bud, hotels, weeks;
	while (scanf("%d%d%d%d", &n, &bud, &hotels, &weeks) != EOF) {
		int res = INT_MAX;
		int price, beds;
		while (hotels--) {
			scanf("%d", &price);
			for (int i = 0; i < weeks; ++i) {
				scanf("%d", &beds);
				if (beds >= n && price * n <= bud)
					res = min(res, price * n);
			}
		}
		if (res != INT_MAX)
			printf("%d\n", res);
		else
			printf("stay home\n");
	}
	return 0;
}