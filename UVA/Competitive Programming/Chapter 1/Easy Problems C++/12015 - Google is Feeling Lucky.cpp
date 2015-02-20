#include <cstdio>
#include <string>
#include <limits.h>
#include <iostream>
using namespace std;

int main() {
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; ++c) {
		string name[11];
		int value[11];
		int biggest = INT_MIN;
		for (int i = 0; i < 10; ++i) {
			cin >> name[i] >> value[i];
			biggest = max(biggest, value[i]);
		}
		printf("Case #%d:\n", c);
		for (int i = 0; i < 10; ++i)
			if (value[i] == biggest)
				printf("%s\n", name[i].c_str());
	}
	return 0;
}