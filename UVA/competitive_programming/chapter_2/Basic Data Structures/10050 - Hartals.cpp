#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

#define MAX 3655

bool day[MAX];

int main() {
	int c; cin >> c;
	while (c--) {
		memset(day, false, sizeof(day));
		int days; cin >> days;
		int parties; cin >> parties;
		for (int i = 0; i < parties; ++i) {
			int h; cin >> h;
			for (int j = h; j <= days; j += h)
				if (j % 7 != 6 && j % 7 != 0)
					day[j] = true;
		}
		int res = 0;
		for (int i = 1; i <= days; ++i)
			res += day[i];
		cout << res << endl;
	}
	return 0;
}