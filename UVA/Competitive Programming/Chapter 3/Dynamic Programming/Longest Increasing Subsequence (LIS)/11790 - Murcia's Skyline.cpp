#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 10000 + 5

int const oo = 1 << 30;

vint W, H;

void fast_int(register int *n) {
	register char c;
	*n = 0;
	while (!isdigit(c = getc(stdin)));
	do {
		(*n) = (*n) * 10 + (c - '0');
	} while (isdigit(c = getc(stdin)));
}

inline void get_max(int &a, int b) {
	if (a < b) a = b;
}

int lis(void) {
	int n = SIZE(H);
	int big = 0;
	vint S(n, 0);
	REP(i, n) {
		S[i] = W[i];
		REP(j, i)
			if (H[i] > H[j])
				get_max(S[i], S[j] + W[i]);
		get_max(big, S[i]);
	}
	return big;
}

int lds(void) {
	int n = SIZE(H);
	int big = 0;
	vint S(n, 0);
	REP(i, n) {
		S[i] = W[i];
		REP(j, i)
			if (H[j] > H[i])
				get_max(S[i], S[j] + W[i]);
		get_max(big, S[i]);
	}
	return big;
}

int main() {
	int TC; fast_int(&TC);
	for (int n, c = 1; TC--; c++) {
		fast_int(&n);
		W = vint(n);
		H = vint(n);
		REP(i, n) fast_int(&H[i]);
		REP(i, n) fast_int(&W[i]);
		int inc = lis();
		int dec = lds();
		printf("Case %d. ", c);
		if (inc >= dec)
			printf("Increasing (%d). Decreasing (%d).\n", inc, dec);
		else
			printf("Decreasing (%d). Increasing (%d).\n", dec, inc);
	}
	return 0;
}