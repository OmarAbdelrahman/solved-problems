#include <cstdio>
using namespace std;

int main() {
	int TC; scanf("%d", &TC);
	int members[21], p_index[21];
	for (int size, m, i; TC--;) {
		scanf("%d", &size);
		int total_votes = 0;
		for (i = 0; i < size; ++i) {
			scanf("%d", &members[i]);
			total_votes += members[i];
			p_index[i] = 0;
		}
		total_votes >>= 1;
		for (m = 0; m < 1 << size; ++m) {
			int sum = 0;
			for (i = 0; i < size; ++i)
				if (m & (1 << i)) sum += members[i];
			if (sum <= total_votes) continue;
			for (i = 0; i < size; ++i)
				if (m & (1 << i)) {
					if (sum - members[i] <= total_votes)
						++p_index[i];
				}
		}
		for (i = 0; i < size; ++i)
			printf("party %d has power index %d\n", i + 1, p_index[i]);
		puts("");
	}
	return 0;
}