#include <iostream>
#include <cstdio>
using namespace std;

char ch;
int n, m;

int rook() {
	return min(n, m);
}

int knight() {
	return ((m * n) >> 1) + int((m * n) % 2);
}

int queen() {
	return rook();
}

int king() {
	if (n & 1) n++;
	if (m & 1) m++;
	return (n >> 1) * (m >> 1);
}

int main() {
	int c; scanf("%d", &c);
	while (c--) {
		cin >> ch >> n >> m;
		switch (ch) {
			case 'r': printf("%d", rook()); break;
			case 'k': printf("%d", knight()); break;
			case 'Q': printf("%d", queen()); break;
			case 'K': printf("%d", king()); break;
		}
		printf("\n");
	}
	return 0;
}
