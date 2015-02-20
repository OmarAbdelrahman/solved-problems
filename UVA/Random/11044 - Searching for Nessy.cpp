#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m, c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", ((int)(n / 3) * (int)(m / 3)));
	}
	return 0;
}