#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>

#define                   c(A)							  A.clear()
#define                size(A)					    ((int)A.size())
#define              res(A, n)							A.resize(n)
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define      DFor(i, Limit, v)     for (int i = Limit; i >= v; i--)
#define                    MAX									 31
#define                zero(A)				memset(A, 0, sizeof(A))
#define            negative(A)			   memset(A, -1, sizeof(A))
#define						VC								 vector
#define					   PII						pair <int, int>
#define                     VI						       VC <int>
#define                     VS					        VC <string>
#define                    VVI								VC <VI>
#define						 X								  first
#define                      Y								 second
#define                   VPII							   VC <PII>
#define					 DB(a)	   cerr << #a << ": " << a << endl;

typedef           unsigned int								  uint;
typedef          long long int   						   longint;
typedef unsigned long long int 						      ulongint;
typedef            long double							longdouble;

using namespace std;

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

ulongint f(ulongint n) {
	for (ulongint i = n - 1; i > 1; i--)
		n *= i;
	return n;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n < 0) {
			if (!(n % 2))
				puts("Underflow!");
			else
				puts("Overflow!");
		} else if (n < 8) {
			puts("Underflow!");
		} else if (n > 13) {
			puts("Overflow!");
		} else {
			cout << f((long)n) << endl;
		}
	}
	return 0;
}