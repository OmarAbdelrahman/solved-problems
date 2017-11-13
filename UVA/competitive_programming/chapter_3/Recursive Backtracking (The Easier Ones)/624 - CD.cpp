#include <cstdio>
using namespace std;

#define MAX 22

int len, res;
int duration[MAX];
bool V[MAX], vis[MAX];
int tracks, gap;

void solve(int indx, int sum) {
	if (indx == tracks) {
		if (len - sum >= 0 && len - sum < gap) {
			gap = len - sum;
			for (int i = 0; i < tracks; ++i)
				V[i] = vis[i];
		}
	} else {
		vis[indx] = true;
		solve(indx + 1, sum + duration[indx]);
		vis[indx] = false;
		solve(indx + 1, sum);
	}
}

int main() {
	for (int i, s; scanf("%d", &len) != EOF;) {
		scanf("%d", &tracks);
		for (i = 0; i < tracks; ++i)
			scanf("%d", &duration[i]);
		gap = 0x3f3f3f3f, s = 0;
		solve(0, 0);
		for (i = 0; i < tracks; ++i) if (V[i])
			printf("%d ", duration[i]), s += duration[i];
		printf("sum:%d\n", s);
	}
	return 0;
}