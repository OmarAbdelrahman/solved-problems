#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define all(A) A.begin(), A.end()
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string s;
	while (getline(cin, s)) {
		string t;
		for (string::size_type i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) {
				t += s[i];
			} else if (s[i] == ' ') {
				if (!t.empty()) cout << t[0];
				t = "";
			}
		}
		if (!t.empty()) cout << t[0];
		cout << endl;
	}
	return 0;
}