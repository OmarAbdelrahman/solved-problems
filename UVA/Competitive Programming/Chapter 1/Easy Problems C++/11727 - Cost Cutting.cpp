#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; ++c) {
		int arr[3];
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr + 3);
		printf("Case %d: %d\n", c, arr[1]);
	}
	return 0;
}