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

int const MODULO = 101;

int h(string& key) {
	int result = 0;
	for (int i = 0; i < key.length(); ++i) {
		result += (key[i] * (i + 1));
		result %= MODULO;
	}
	return (result * 19) % MODULO;
}

int hash(string& key) {
	return h(key) % MODULO;
}

string result[MODULO];

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int n; scanf("%d", &n);
		fill(result, result + MODULO, "");
		map<string, int> position;
		for (int i = 0; i < n; ++i) {
			string inst; cin >> inst;
			if (inst[0] == 'A') {
				inst = inst.substr(4);
				if (position.find(inst) != position.end())
					continue;
				for (int j = 0; j < 20; ++j) {
					int next = ::hash(inst) + j * j + 23 * j;
					next %= MODULO;
					if (result[next] == "") {
						result[next] = inst;
						position[inst] = next;
						break;
					}
				}
			} else {
				inst = inst.substr(4);
				if (position.find(inst) != position.end()) {
					result[position[inst]] = "";
					position.erase(inst);
				}
			}
		}
		int count = 0;
		for (int i = 0; i < MODULO; ++i)
			count += result[i] != "";
		printf("%d\n", count);
		for (int i = 0; i < MODULO; ++i)
			if (result[i] != "")
				printf("%d:%s\n", i, result[i].c_str());
	}
	return 0;
}