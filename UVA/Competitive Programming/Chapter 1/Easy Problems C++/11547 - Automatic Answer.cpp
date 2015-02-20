#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int LongInt;

int main() {	
	int c, n;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		LongInt N;
		N = n * 567;
		N /= 9;
		N += 7492;
		N *= 235;
		N /= 47;
		N -= 498;
		if (N < 0) N *= -1;
		int t = N % 10;
		N -= t;
		N /= 10;
		cout << N % 10 << endl;
	}
	return 0;
}