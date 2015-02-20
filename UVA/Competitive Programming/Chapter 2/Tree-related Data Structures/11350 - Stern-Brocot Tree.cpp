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

typedef unsigned long long int64;

struct io {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}
};

struct integer {
	static int64 gcd(int64 a, int64 b) {
		while (b > 0) {
			int64 t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
};

struct fraction {
	int64 P, Q;

	fraction() : P(0), Q(0) {}

	fraction(int64 P = 0, int64 Q = 1) {
		int64 D = integer::gcd(P, Q);
		P /= D, Q /= D;
		if (Q < 0)
			P = -P, Q = -Q;
		this->P = P;
		this->Q = Q;
	}

	fraction& operator += (const fraction& f) {
		this->P += f.P;
		this->Q += f.Q;
		return *this;
	}

	static fraction get_median(fraction a, fraction b) {
		return fraction(a.P + b.P, a.Q + b.Q);
	}
};

int main(int argc, char **args) {
	for (int TC = io::next<int>(); TC-- > 0;) {
		string steps = io::next<string>();
		fraction left(0, 1);
		fraction right(1, 0);
		fraction middle = fraction::get_median(left, right);
		for (int i = 0; i < steps.length(); ++i) {
			if (steps[i] == 'R') {
				left = middle;
				middle += right;				
			} else {
				right = middle;
				middle += left;
			}
			middle = fraction::get_median(left, right);
		}
		printf("%lld/%lld\n", middle.P, middle.Q);
	}
	return 0;
}