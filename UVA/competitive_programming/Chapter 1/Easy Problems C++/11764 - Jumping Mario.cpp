#include <cstdio>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; ++c) {
		int size;
		int data[55];
		scanf("%d", &size);
		for (int i = 0; i < size; ++i)
			scanf("%d", &data[i]);
		int big = 0, small = 0;
		for (int i = 0; i < size - 1; ++i)
			if (data[i + 1] > data[i])
				++big;
			else if (data[i + 1] < data[i])
				++small;
			else
				continue;
		printf("Case %d: %d %d\n", c, big, small);
	}
	return 0;
}