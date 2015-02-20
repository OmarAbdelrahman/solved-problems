#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long Int;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	Int number;
	while (scanf("%lld", &number) != EOF) {
		bool stan = true, olie = false;
		Int start = 1;
		while (start < number) {
			if (stan) {
				start *= 9;
			} else {
				start *= 2;
			}
			if (start >= number) break;
			swap(stan, olie);
		}
		if (stan) {
			puts("Stan wins.");
		} else {
			puts("Ollie wins.");
		}
	}
	return 0;
}
