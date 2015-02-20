/*
ID: 1010
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define sz(a) ((int)a.size())
#define get_bit(x, i) ((x >> i) & 1)

int N, B, D;
vector<int> S;

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	scanf("%d%d%d", &N, &B, &D);
	S.push_back(0);
	while (sz(S) != N) {
		int t = S[sz(S) - 1];
		for (int a = t + 1; a < 1 << B; ++a) {
			bool ok = true;
			for (int b = sz(S) - 1; b >= 0; --b) {
				int cnt = 0;
				for (int i = 0; i < B; ++i)
					if (get_bit(a, i) ^ get_bit(S[b], i))
						++cnt;
				if (cnt < D) {
					ok = false;
					break;
				}
			}
			if (ok) {
				S.push_back(a);
				break;
			}
		}
	}
	for (int i = 0; i < sz(S); ++i)
		if (!((i + 1) % 10) || i == sz(S) - 1)
			printf("%d\n", S[i]);
		else printf("%d ", S[i]);
	return 0;
}