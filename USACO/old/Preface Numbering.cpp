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

#define max_t 3500
#define sz(a) ((int)a.size())

int n;
string numerals("IVXLCDM");
map<int, string> M;
map<char, int> A;

void intialize() {
	M[1] = "I", M[5] = "V";
	M[10] = "X", M[50] = "L";
	M[100] = "C", M[500] = "D";
	M[1000] = "M";
	for (int i = 2; i <= 3; ++i) {
		M[i] = M[i - 1] + "I";
		M[i * 10] = M[(i - 1) * 10] + "X";
		M[i * 100] = M[(i - 1) * 100] + "C";
		M[i * 1000] = M[(i - 1) * 1000] + "M";
	}
	for (int i = 0; i < 3; ++i) {
		int v = (int)pow(10., i);
		M[4 * v] = M[v] + M[5 * v];
		M[9 * v] = M[v] + M[v * 10];
		for (int j = 6; j <= 8; ++j)
			M[j * v] = M[5 * v] + M[(j - 5) * v];
	}
	for (int i = 10; i < 100; i += 10)
		for (int j = 1; j < 10; ++j)
			M[i + j] = M[i] + M[j];
	for (int i = 100; i < 1000; i += 100)
		for (int j = 1; j < 100; ++j)
			M[i + j] = M[i] + M[j];
	for (int i = 1000; i < 3000; i += 1000)
		for (int j = 1; j < 1000; ++j)
			M[i + j] = M[i] + M[j];
	for (int i = 3000; i < 3500; i += 500)
		for (int j = 1; j < 500; ++j)
			M[i + j] = M[i] + M[j];
}

int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
	scanf("%d", &n);
	intialize();
	for (map<int, string>::iterator it = M.begin(); it != M.end(); it++) {
		if (it->first > n) break;
		for (int i = 0; i < sz(it->second); ++i)
			A[it->second[i]]++;
	}
	for (int i = 0; i < sz(numerals); ++i) {
		int a = A[numerals[i]];
		if (a) printf("%c %d\n", numerals[i], a);
	}
	return 0;
}