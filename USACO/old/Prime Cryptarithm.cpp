/*
ID: 1010
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int a, int b, int c, int d, int e, vector<int>& v) {
	int one = a * 100 + b * 10 + c;
	int two = d * 10 + e;
	if (one * e > 999 || one * d > 999 || one * two > 9999)
		return 0;
#define all(a) a.begin(), a.end()
	int partial_one = one * e;
	while (partial_one) {
		if (find(all(v), partial_one % 10) == v.end())
			return 0;
		partial_one /= 10;
	}
	int partial_two = one * d;
	while (partial_two) {
		if (find(all(v), partial_two % 10) == v.end())
			return 0;
		partial_two /= 10;
	}
	int product = one * two;
	while (product) {
		if (find(all(v), product % 10) == v.end())
			return 0;
		product /= 10;
	}
	return 1;
}

int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	int n; cin >> n;
	vector<int> nums(n);
	int const sz = n;
	for (int i = 0; i < sz; ++i) {
		cin >> n;
		nums[i] = n;
	}
	if (sz < 5) {
		cout << 0 << endl;
		return 0;
	}
	int counter = 0;
	for (int a = 0; a < sz; ++a)
		for (int b = 0; b < sz; ++b)
			for (int c = 0; c < sz; ++c)
				for (int d = 0; d < sz; ++d)
					for (int e = 0; e < sz; ++e)
						counter += solve(nums[a], nums[b], nums[c], nums[d], nums[e], nums);
	cout << counter << endl;
	return 0;
}