#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;

typedef long long int64;

int main() {
	char line[10001];
	int kases; scanf("%d", &kases);
	for (int c = 0; c < kases; ++c) {
		int characters; scanf("%d", &characters);
		int64 val[500];
		memset(val, 0, sizeof(val));
		for (int i = 0; i < characters; ++i) {
			char ch; cin >> ch;
			int num; cin >> num;
			val[ch + 200] = num;
		}
		int lines; scanf("%d\n", &lines);
		double total = 0;
		for (int i = 0; i < lines; ++i) {
			gets(line);
			for (int j = 0; j < strlen(line); ++j)
				total += val[line[j] + 200];
		}
		printf("%.2lf$\n", total / 100);
	}
	return 0;
}

/* Anas
int main() {
	char line[10001];
	int kases; scanf("%d", &kases);
	for (int c = 0; c < kases; ++c) {
		int characters; scanf("%d", &characters);
		char paid[150];
		int64 val[150];
		for (int i = 0; i < characters; ++i) {
			cin >> paid[i] >> val[i];
		}
		int lines; scanf("%d\n", &lines);
		double total = 0;
		for (int i = 0; i < lines; ++i) {
			gets(line);
			int size = strlen(line);
			for (int index = 0; index < characters; ++index) {
				for (int j = 0; j < size; ++j)
					if (paid[index] == line[j]) total += val[index];
			}
		}
		printf("%.2lf$\n", total / 100);
	}
	return 0;
}
*/