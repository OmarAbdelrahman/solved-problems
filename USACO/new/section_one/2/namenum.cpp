/*
ID: omar.se1
LANG: C++11
TASK: namenum
 */

#include <bits/stdc++.h>
using namespace std;

inline int get(const char ch) {
	if (ch == 'Z' || ch == 'Q') {
		return -1;
	}
	if (ch <= 'C') return 2;
	if (ch <= 'F') return 3;
	if (ch <= 'I') return 4;
	if (ch <= 'L') return 5;
	if (ch <= 'O') return 6;
	if (ch <= 'S') return 7;
	if (ch <= 'V') return 8;
	if (ch <= 'Y') return 9;
	throw;
}

int main() {
  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);
  long long n;
  cin >> n;
  ifstream file;
  file.open("dict.txt");
  bool found = false;
  for (string s; file >> s; ) {
  	long long c = 0;
  	for (const char& ch : s) {
  		int v = get(ch);
  		if (v == -1) continue;
  		(c *= 10) += v;
  	}
  	if (n == c) {
  		cout << s << '\n';
  		found = true;
  	}
  }
  if (!found) puts("NONE");
  file.close();
  return 0;
}
