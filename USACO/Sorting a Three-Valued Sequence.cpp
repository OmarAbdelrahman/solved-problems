/*
ID: 1010
PROG: sort3
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, two, tre, one;
vector<int> v;

#define sz(a) ((int)a.size())

inline int solve() {
	int ex = 0;
	for (int i = 0; i < one; ++i)
		if (v[i] == 3) {
			for (int j = tre - 1; j >= one; --j)
				if (v[j] == 1) {
					++ex, swap(v[i], v[j]);
					break;
				}
		} else if (v[i] == 2) {
			for (int j = one; j < tre; ++j)
				if (v[j] == 1) {
					++ex, swap(v[i], v[j]);
					break;
				}
		}
	for (int i = one; i < two; ++i)
		if (v[i] == 3) for (int j = two; j < tre; ++j)
			if (v[j] == 2) {
				++ex, swap(v[i], v[j]);
				break;
			}
	return ex;
}

int main() {
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d", &n);
	v.resize(n);
	one = two = tre = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		if (v[i] == 1) ++one;
		else if (v[i] == 2) ++two;
		else ++tre;
	}
	two += one, tre += two;
	printf("%d\n", solve());
	return 0;
}