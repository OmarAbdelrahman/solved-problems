/*
ID: 1010
PROG: runround
LANG: C++
*/

#include "iostream"
#include "cstdio"
#include "deque"
#include "vector"
#include "string.h"
#include "numeric"
#include "algorithm"
using namespace std;

int number;
int data[21];
int freq[10];

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	scanf("%d", &number);
	for (int answer = number + 1;; ++answer) {
		int sz = 0;
		int zz = answer;
		bool zero = false;
		memset(freq, 0, sizeof freq);
		while (zz) {
			int temp = zz % 10;
			zero = ((data[sz++] = temp) == 0);
			freq[temp]++;
			zero = zero || freq[temp] > 1;
			if (zero) break;
			zz /= 10;
		}
		if (zero) continue;
		int final = data[sz - 1], now = 0;
		int i = sz - 1, j;
		memset(freq, 0, sizeof freq);
		bool ok = true;
		while (now != final) {
			freq[data[i]]++;
			if (freq[data[i]] > 1) {
				ok = false;
				break;
			}
			j = data[i];
			for (; j > 0; --j, i = (i - 1 + sz) % sz);
			now = data[i];
		}
		for (i = 0; i < sz; ++i)
			if (!freq[data[i]]) {
				ok = false;
				break;
			}
		if (ok) {
			cout << answer << endl;
			return 0;
		}
	}
	return 0;
}