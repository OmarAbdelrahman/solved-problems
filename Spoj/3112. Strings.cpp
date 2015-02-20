/*
ID: 1010
PROG: cowtour
LANG: C++
*/

#include <iostream>
using namespace std;

typedef long long _int;
#define sz(a) ((int)a.size())
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define for_each(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define all(c) c.begin(), c.end()
#define max_t 7

char a[max_t];
char b[max_t];
char c[max_t];

int solve(int len, int dep) {
	int ans = 0;
	if (len == dep) {
		c[len] = '\0';
		if ((strcmp(a, c) < 0 || strlen(a) < dep) && (strcmp(c, b) < 0 || dep < strlen(b)))
			return ans + 1;
		return ans;
	}
	for (char ch = 'A'; ch <= 'J'; ++ch) {
		if (len == 0 || abs(c[len - 1] - ch) > 1) {
			c[len] = ch;
			ans += solve(len + 1, dep);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (scanf("%s%s", a, b) != EOF) {
		fill(c, c + max_t, '\0');
		int res = 0;
		for (int i = strlen(a); i <= strlen(b); ++i)
			res += solve(0, i);
		printf("%d\n", res);
	}
	return 0;
}