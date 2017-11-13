#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; ++c) {
		int size, data[105];
		scanf("%d", &size);
		for (int i = 0; i < size; ++i)
			scanf("%d", &data[i]);
		printf("Case %d: %d\n", c, *max_element(data, data + size));
	}
	return 0;
}