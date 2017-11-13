#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int kases; cin >> kases;
	while (kases--) {
		int S, A, F; cin >> S >> A >> F;
		vector<int> street(F), avenue(F);
		for (int i = 0; i < F; ++i) cin >> street[i] >> avenue[i];
		sort(street.begin(), street.end());
		sort(avenue.begin(), avenue.end());
		int mid = (F & 1) ? F >> 1 : (F - 1) >> 1;
		printf("(Street: %d, Avenue: %d)\n", street[mid], avenue[mid]);
	}
	return 0;
}
