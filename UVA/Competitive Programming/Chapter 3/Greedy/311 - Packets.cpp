#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** args) {
	for (int a1, a2, a3, a4, a5, a6; cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6; ) {
		if (!a1 && !a2 && !a3 && !a4 && !a5 && !a6)
			break;

		int result = a6;

		result += a5;
		a1 -= 11 * a5;

		result += a4;
		a2 -= 5 * a4;

		const int mod3 = a3 % 4;
		result += a3 / 4;
		if (mod3) {
			++result;
			a2 -= (7 - mod3 * 2);
			a1 -= (7 - mod3 + 1);
		}

		if (a2 > 0) {
			const int mod2 = a2 % 9;
			result += a2 / 9;
			if (mod2) ++result;
			a1 -= (36 - mod2 * 4);
		} else if (a2 < 0) {
			a1 -= (-a2 * 4);
		}

		if (a1 > 0) {
			result += a1 / 36;
			if (a1 % 36) ++result;
		}

		cout << result << endl;
	}
	return 0;
}
