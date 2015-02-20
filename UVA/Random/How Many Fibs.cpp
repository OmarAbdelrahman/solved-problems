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

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define limit 5001

void FillFibonnaci();
int Compare(string&, string&);
void MakeLengthsEqual(string&, string&);
string Add(string, string), f[limit];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	FillFibonnaci();
	string start, end;

	while (cin >> start >> end)
	{
		if (start == "0" && end == "0")
			break;

		int counter = 0;
		for (int i = 0; i < limit; i++)
			if (Compare(start, f[i]) == -1 || f[i] == start)
				if (Compare(end, f[i]) == 1 || f[i] == end)
					++counter;

		cout << counter << endl;
	}

	return 0;
}

void FillFibonnaci()
{
	f[0] = "1", f[1] = "2";
	for (int i = 2; i < limit; i++)
		f[i] = Add(f[i - 1], f[i - 2]);
}

int Compare(string& a, string& b)
{
	if (a.size() < b.size())
		return -1;
	else if (a.size() > b.size())
		return 1;
	else for (int i = 0; i < a.size(); i++)
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	return 0;
}

void MakeLengthsEqual(string &first, string &second)
{
	short length;
	if (first.size() > second.size())
	{
		length = first.size() - second.size();
		second.insert(0, length, '0');
	}
	else if (first.size() < second.size())
	{
		length = second.size() - first.size();
		first.insert(0, length, '0');
	}
	else return;
}

string Add(string firstNumber, string secondNumber)
{
	string resultNumber = (firstNumber.size() > secondNumber.size()) ? firstNumber : secondNumber;

	MakeLengthsEqual(firstNumber, secondNumber);

	char carry = '0';
	for (int i = firstNumber.size() - 1; i >= 0; i--)
	{
		resultNumber[i] = ((carry - '0') + (firstNumber[i] - '0') + (secondNumber[i] - '0')) + '0';
		if (i != 0)
		{
			if (resultNumber[i] > '9')
			{
				resultNumber[i] -= 10;
				carry = '1';
			}
			else carry = '0';
		}
	}

	if (resultNumber[0] > '9')
	{
		resultNumber[0] -= 10;
		resultNumber.insert(0, 1, '1');
	}

	return resultNumber;
}