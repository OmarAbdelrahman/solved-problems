/*
ID: 1010
PROG: frac1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

int N;

int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	scanf("%d", &N);
	set<double> S;
	map<double, pair<int, int> > M;
	for (int i = 0; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j) {
			double n = (i * 1.) / (j * 1.);
			if (S.find(n) == S.end()) {
				S.insert(n);
				M[n] = make_pair(i, j);
			}
		}
	for (map<double, pair<int, int> >::iterator it = M.begin(); it != M.end(); it++)
		printf("%d/%d\n", it->second.first, it->second.second);
	printf("1/1\n");
	return 0;
}