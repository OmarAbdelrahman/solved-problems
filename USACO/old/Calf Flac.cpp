/*
ID: 1010
PROG: calfflac
LANG: C++
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pb push_back
#define mp make_pair
typedef long long i64;
const double eps = 1e-12;
const double pi = acos(-1.);
const int oo = 0x3f3f3f3f;
#define sz(A) ((int)A.size())
#define all(A) A.begin(), A.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) FOR(i, 0, n)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

using namespace std;

int main() {
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	string input, str;
	while (getline(cin, str))
		input += str, input += '\n';
	str.clear();
	int index[20001], C = 0;
	for (int i = 0; i < sz(input); i++)
		if (isalpha(input[i]))
			str += tolower(input[i]), index[C++] = i;
	int begin, end, length;
	int left, right, M = -1;
	for (int i = 1; i < sz(str); i++) {
		length = 0, left = i + 1, right = i - 1;
		while (right >= 0 && left < sz(str) && str[left] == str[right])
			left++, right--, length++;
		if (length * 2 + 1 > M)
			M = length * 2 + 1, begin = index[right + 1], end = index[left - 1];
		length = 0, right = i - 1, left = i;
		while (right >= 0 && left < sz(str) && str[left] == str[right])
			left++, right--, length++;
		if (length * 2 > M)
			M = length * 2, begin = index[right + 1], end = index[left - 1];
	}
	printf("%d\n", M);
	for (int i = begin; i <= end; i++)
		printf("%c", input[i]);
	puts("");
	return 0;
}