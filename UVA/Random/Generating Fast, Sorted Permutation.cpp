#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

#define All(A) A.begin(), A.end()
#define For(i, Limit) for (int i = 0; i < Limit; i++)

int main() {
	string koko;
	int numberOfCases;
	scanf("%d", &numberOfCases);
	For (i, numberOfCases) {
		cin >> koko;
		sort(All(koko));
		do {
			cout << koko << endl;
		} while (next_permutation(All(koko)));
		cout << endl;
	}
	return 0;
}