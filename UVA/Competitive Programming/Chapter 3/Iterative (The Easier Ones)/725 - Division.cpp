#include <cstdio>
#include <string.h>
using namespace std;

bool vis[10];

bool ok(int n) {
	if (n <= 9999 && vis[0])
		return false;
	else if (n <= 9999)
		vis[0] = true;
	while (n) {
		int x = n % 10;
		if (vis[x]) return false;
		vis[x] = true;
		n /= 10;
	}
	return true;
}

void visit_taken(int n) {
	if (n <= 9999)
		vis[0] = true;
	while (n) {
		vis[n % 10] = true;
		n /= 10;
	}
}

int main() {
	bool first = true;
	for (int n, num; scanf("%d", &n) && n;) {
		if (!first) puts("");
		bool found = false;
		int length = 98765 / n;
		for (num = 1234; num <= length; ++num) {
			memset(vis, false, sizeof(vis));
			if (ok(num)) {
				visit_taken(num);
				int a = num * n;
				if (ok(a)) {
					printf("%05d / %05d = %d\n", a, num, n);
					found = true;
				}
			}
		}
		if (!found) printf("There are no solutions for %d.\n", n);
		first = false;
	}
	return 0;
}