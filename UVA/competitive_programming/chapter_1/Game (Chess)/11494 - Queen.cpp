#include <iostream>
#include <cstdio>
using namespace std;

template<class T> inline T abs(T x) {
	return x < 0 ? -x : x;
}

int main() {
	for (int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);) {
		if (!a && !b && !c && !d) break;
		int d1 = abs(a - c);
		int d2 = abs(b - d);
		if (a == c && b == d) puts("0");
		else if (a == c || b == d) puts("1");
		else if (d1 == d2) puts("1");
		else if (d1 % 2 == d2 % 2) puts("2");
		else puts("2");
	}
	return 0;
}
