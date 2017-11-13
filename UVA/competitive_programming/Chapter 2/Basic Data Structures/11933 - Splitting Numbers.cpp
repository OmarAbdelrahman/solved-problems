#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	for (int n, a = 0; cin >> n && n; a = 0) {
		bool A = true;
		for (int i = 0; i < 32; ++i)
			if (n & (1 << i)) {
				if (A)
					a |= 1 << i;
				A = !A;
			}
		cout << a << " " << n - a << endl;
	}
	return 0;
}
