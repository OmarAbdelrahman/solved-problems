/*
ID: 1010
PROG: barn1
LANG: C++
*/

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
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define mp                            make_pair
#define pb                            push_back
#define np                            next_permutation
#define c(A)                          A.clear()
#define sz(A)                         ((int)A.size())
#define res(A, n)                     A.resize(n)
#define All(A)                        A.begin(), A.end()
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define init(A, B)                    memset(A, B, sizeof(A))
#define VC                            vector
#define PII                           pair <int, int>
#define VI                            VC <int>
#define VS                            VC <string>
#define VVI                           VC <VI>
#define a                             first
#define b                             second
#define VPII                          VC <PII>
#define limit                         31

template <class _Ty> inline _Ty sqr(_Ty n) 
{
	return n * n;
}

template <class _Ty> inline _Ty cube(_Ty n)
{
	return sqr(n) * n;
}

template <class _Ty> void Disp(_Ty n)
{
	cout << n << endl;
}

template <class _Ty> 
struct Queue: public queue <_Ty> 
{
	_Ty Dequeue()
	{
		_Ty tmp = queue <_Ty>::front();
		queue <_Ty>::pop();
		return tmp;
	}
};

int main() 
{
	freopen("in.txt", "r", stdin);

	string temp;
	string sentence;

	while (getline(cin, sentence))
	{
		int f = sentence.find("What is");
		while (f != string::npos)
		{
			if (f != 0 && f != 1) if (sentence[f - 2] != '.' || sentence[f - 2] != '?' || 
									  sentence[f - 1] != '.' || sentence[f - 1] != '?')
			{
				f = sentence.find("What is");
				if (f == string::npos) break;
			}
			temp = "";
			int i;
			for (i = f; i < sentence.size(); i++)
			{
				if (sentence[i] == '?' || sentence[i] == '.')
				{
					temp += sentence[i];
					break;
				}
				temp += sentence[i];
			}

			if (sentence[i] == '.')
			{
				sentence.erase(sentence.begin() + f, sentence.begin() + i);
				f = sentence.find("What is");
				continue;
			}
			sentence.erase(sentence.begin() + f, sentence.begin() + i);

			f = sentence.find("What is");
			temp.erase(temp.begin(), temp.begin() + 5);

			if (temp[temp.size() - 1] != '?')
				continue;

			temp.replace(temp.size() - 1, 1, ".");
			cout << "Forty-two " << temp << endl;
		}
	}

	return 0;
}