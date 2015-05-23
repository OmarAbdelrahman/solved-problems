#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000010;
int lpf[MAX], pfc[MAX];

int main(int argc, char** argv) {
	for (int i = 2; i < MAX; ++i) {
		if (lpf[i] == 0) {
			for (int j = i + i; j < MAX; j += i) {
				lpf[j] = i;
			}
  	}
	}
	for (int i = 2; i < MAX; ++i) {
		pfc[i] = lpf[i] != 0 ? 1 + pfc[i / lpf[i]] : 1;
	}
	for (int i = 2; i < MAX; ++i) {
		pfc[i] += pfc[i - 1];
	}

	int t; scanf("%d", &t);
	while (t-- > 0) {
		int a, b; scanf("%d %d", &a, &b);
		printf("%d\n", pfc[a] - pfc[b]);
	}
	return 0;
}
