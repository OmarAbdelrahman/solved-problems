#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

bool taken[61][61][61];

int main() {
	set<int> region;
	for (int i = 0; i <= 20; ++i) {
		region.insert(i);
		region.insert(i * 2);
		region.insert(i * 3);
	}
	region.insert(50);
	vector<int> value(region.begin(), region.end());
	int n = value.size();
	for (int score; scanf("%d", &score);) {
		if (score <= 0) {
			puts("END OF OUTPUT");
			break;
		}
		memset(taken, false, sizeof(taken));
		int comb = 0, perm = 0;
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < n; ++b)
				for (int c = 0; c < n; ++c) {
					int aa = value[a];
					int bb = value[b];
					int cc = value[c];
					if (aa + bb + cc == score) {
						++perm;
						if (!taken[aa][bb][cc]) {
							taken[aa][bb][cc] = taken[aa][cc][bb] = true;
							taken[bb][aa][cc] = taken[bb][cc][aa] = true;
							taken[cc][aa][bb] = taken[cc][bb][aa] = true;
							++comb;
						}
					}
				}
		if (comb == 0 && perm == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perm);
        }
        puts("**********************************************************************");
	}
	return 0;
}