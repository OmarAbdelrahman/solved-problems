/*
ID: 1010
PROG: clocks
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int const sz = 3;
int const MOD = 12;
vector<int> seq(1000);

void initialize_map(map<int, string>& m) {
	m[0] = "0134", m[1] = "012";
	m[2] = "1245", m[3] = "036";
	m[4] = "13457";
	m[5] = "258", m[6] = "3467";
	m[7] = "678", m[8] = "4578";
}

bool check(vector<int>& times, vector<int> clock, map<int, string>& m) {
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		int const n = times[it->first];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < (int)it->second.size(); ++j) {
				clock[it->second[j] - '0'] += 3;
				if (clock[it->second[j] - '0'] > 12)
					clock[it->second[j] - '0'] %= MOD;
			}
	}
	return clock == vector<int>(sz * sz, 12);
}

void solve(vector<int>& times, vector<int>& clock, map<int, string>& m, int level = 0) {
	if (level == 9) {
		if (check(times, clock, m)) {
			vector<int> tmp;
			for (int i = 0; i < (int)times.size(); ++i)
				while (times[i]) {
					tmp.push_back(i + 1);
					--times[i];
				}
			if (tmp.size() < seq.size()) seq = tmp;
		}
	} else for (int i = 0; i < sz + 1; ++i) {
		times[level] = i;
		solve(times, clock, m, level + 1);
	}
}

int main() {
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	vector<int> clocks(sz * sz);
	for (int i = 0; i < sz * sz; ++i)
		cin >> clocks[i];
	map<int, string> m;
	initialize_map(m);
	vector<int> times(sz * sz, 0);
	solve(times, clocks, m);
	cout << seq[0];
	for (int i = 1; i < (int)seq.size(); ++i)
		cout << " " << seq[i];
	cout << endl;
	return 0;
}