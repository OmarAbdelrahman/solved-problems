#include <cstdio>
#include <string.h>
using namespace std;

bool vis[10];

bool ok(long long n) {
	memset(vis, false, sizeof(vis));
	while (n) {
		if (vis[n % 10]) return false;
		vis[n % 10] = true;
		n /= 10;
	}
	return true;
}

int main() {
	char n[11];
	int cases; scanf("%d", &cases);
	bool first = true;
	long long a, b, c, length;
	while (cases--) {
		if (!first) puts("");
		scanf("%s", n);
		c = 0, length = strlen(n);
		for (b = 0; b < length; ++b)
			c = (c * 10) + (n[b] - '0');
		length = 9876543210 / c;
		for (b = 1; b <= length; ++b) {
			if (ok(b)) {
				a = b * c;
				if (ok(a))
					printf("%lld / %lld = %lld\n", a, b, c);
			}
		}
		first = false;
	}
	return 0;
}