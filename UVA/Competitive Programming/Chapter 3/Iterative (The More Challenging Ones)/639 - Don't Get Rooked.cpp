#include <cstdio>
using namespace std;

#define MAX 5

int size;
int vis[MAX][MAX];
char s[MAX];

void get_max(int& a, int b) {
	if (a < b) a = b;
}

void place(int x, int y, int val) {
	int p;
	for (p = x; p < size && vis[p][y] != -1; ++p)
		vis[p][y] += val;
	for (p = x - 1; p >= 0 && vis[p][y] != -1; --p)
		vis[p][y] += val;
	for (p = y + 1; p < size && vis[x][p] != -1; ++p)
		vis[x][p] += val;
	for (p = y - 1; p >= 0 && vis[x][p] != -1; --p)
		vis[x][p] += val;
}

int solve() {
	int i, j, big = 0;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			if (vis[i][j] == 0) {
				place(i, j, +1);
				get_max(big, solve() + 1);
				place(i, j, -1);
			}
	return big;
}

int main() {
	for (int i, j; scanf("%d", &size) && size;) {
		for (i = 0; i < size; ++i) {
			scanf("%s", s);
			for (j = 0; j < size; ++j)
				vis[i][j] = s[j] == 'X' ? -1 : 0;
		}
		printf("%d\n", solve());
	}
	return 0;
}