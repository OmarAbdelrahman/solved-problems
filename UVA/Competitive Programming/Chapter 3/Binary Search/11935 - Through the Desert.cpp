#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define EPSILON 1e-9
#define LENGTH(s) ((int)s.length())
#define MAX 55

string event[MAX];
int kilo[MAX];
int consumption[MAX];

bool can(double n, int size, int cur_consumption) {
	double litres = n;
	int leaks = 0, i, cur_kil = 0;
	for (i = 0; i < size; ++i) {
		double dist = kilo[i] - cur_kil;
		litres -= (dist * leaks);
		litres -= (dist / 100.0) * cur_consumption;
		if (litres < 0) return false;
		if (event[i] == "Leak") {
			++leaks;
		} else if (event[i] == "Mechanic") {
			leaks = 0;
		} else if (event[i] == "Gas") {
			litres = n;
		} else if (event[i] == "Fuel") {
			cur_consumption = consumption[i];
		}
		cur_kil = kilo[i];
	}
	return true;
}

int main() {
	string input;
	for (int i, size, initial; getline(cin, input);) {
		if (input == "0 Fuel consumption 0") break;
		stringstream ss(input);
		string t1, t2, t3; ss >> t1 >> t2 >> t3 >> initial;
		bool ok = true;
		for (size = 0; getline(cin, input);) {
			if (input.substr(LENGTH(input) - 4) == "Goal")
				ok = false;
			stringstream sin(input);
			sin >> kilo[size] >> event[size];
			if (event[size][0] == 'F') {
				string temp; sin >> temp >> consumption[size];
			}
			++size;
			if (!ok) break;
		}
		double lo = 0.0, hi = 10000.0, mid = 0.0, res = 0.0;
		for (i = 0; i < 50; ++i) {
			mid = (lo + hi) / 2;
			if (can(mid, size, initial)) {
				res = mid;
				hi = mid;
			} else {
				lo = mid;
			}
		}
		printf("%.3lf\n", res);
	}
	return 0;
}