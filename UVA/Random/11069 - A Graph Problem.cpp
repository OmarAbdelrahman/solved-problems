//#include <cstdio>
//#include <bitset>
//using namespace std;
//
//int table[80];
//
//int solve(int n) {
//	if (n < 1) return 0;
//	if (n < 3) return 1;
//	if (table[n] != -1) {
//		return table[n];
//	}
//	return table[n] = solve(n - 2) + solve(n - 3);
//}
//
//int main() {
//	int n;
//	memset(table, -1, sizeof table);
//	while (scanf("%d", &n) != EOF) {
//		printf("%d\n", solve(n) + solve(n - 1));
//	}
//	return 0;
//}
