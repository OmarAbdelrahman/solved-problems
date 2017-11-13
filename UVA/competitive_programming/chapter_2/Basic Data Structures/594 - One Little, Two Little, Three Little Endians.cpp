#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

int main() {
	for (int n; cin >> n;) {
		bitset<32> number(n), res;
		for (int i = 0; i < 8; ++i)
			res[8 * 3 + i] = number[i];
		for (int i = 8, j = 0; i < 8 * 2; ++i, ++j)
			res[8 * 2 + j] = number[i];
		for (int i = 8 * 2, j = 0; i < 8 * 3; ++i, ++j)
			res[8 + j] = number[i];
		for (int i = 8 * 3, j = 0; i < 8 * 4; ++i, ++j)
			res[j] = number[i];
		long long ans = 0;
		for (int i = 0; i < 32; ++i)
			if (res[i]) ans += (1 << i);
		cout << n << " converts to " << ans << endl;
	}
	return 0;
}
