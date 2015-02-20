/*
ID: 1010
PROG: preface
LANG: C++
*/

#include "iostream"
#include "cstdio"
#include "map"
#include "string"
#include "cmath"
using namespace std;

string numerals("IVXLCDM");
map<int, string> M;
map<string, int> N;

void intialize() {
	M[1] = "I", M[5] = "V";
	N[M[1]] = 1, N[M[5]] = 5;
	M[10] = "X", M[50] = "L";
	N[M[10]] = 10, N[M[50]] = 50;
	M[100] = "C", M[500] = "D";
	N[M[100]] = 100, N[M[500]] = 500;
	M[1000] = "M", N[M[1000]] = 1000;
	for (int i = 2; i <= 3; ++i) {
		M[i] = M[i - 1] + "I";
		N[M[i]] = i;
		M[i * 10] = M[(i - 1) * 10] + "X";
		N[M[i * 10]] = i * 10;
		M[i * 100] = M[(i - 1) * 100] + "C";
		N[M[i * 100]] = i * 100;
		M[i * 1000] = M[(i - 1) * 1000] + "M";
		N[M[i * 1000]] = i * 1000;
	}
	for (int i = 0; i < 3; ++i) {
		int v = (int)pow(10., i);
		M[4 * v] = M[v] + M[5 * v];
		N[M[4 * v]] = 4 * v;
		M[9 * v] = M[v] + M[v * 10];
		N[M[9 * v]] = 9 * v;
		for (int j = 6; j <= 8; ++j) {
			M[j * v] = M[5 * v] + M[(j - 5) * v];
			N[M[j * v]] = j * v;
		}
	}
	for (int i = 10; i < 100; i += 10)
		for (int j = 1; j < 10; ++j) {
			M[i + j] = M[i] + M[j];
			N[M[i + j]] = i + j;
		}
	for (int i = 100; i < 1000; i += 100)
		for (int j = 1; j < 100; ++j) {
			M[i + j] = M[i] + M[j];
			N[M[i + j]] = i + j;
		}
	for (int i = 1000; i <= 4000; i += 1000)
		for (int j = 1; j <= 1000; ++j) {
			M[i + j] = M[i] + M[j];
			N[M[i + j]] = i + j;
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	intialize();
	for (string in; cin >> in;) {
		bool num = true;
		for (int i = 0; i < in.size(); ++i) {
			for (int j = 0; j < numerals.size(); ++j)
				if (in[i] == numerals[j]) {
					num = false;
					break;
				}
			if (!num) break;
		}
		if (!num) {
			cout << N[in] << endl;
		} else {
			int n; sscanf(in.c_str(), "%d", &n);
			cout << M[n] << endl;
		}
	}
	return 0;
}