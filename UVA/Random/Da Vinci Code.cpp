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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define                    MAX									 30

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

LongInt Fibonnaci[49];
vector < pair <LongInt, char> > orders;

void InitializeFibonnaci() {
	for (int i = 2; i <= 48; i++)
		Fibonnaci[i] = Fibonnaci[i - 1] + Fibonnaci[i - 2];
}

bool BS(LongInt key)
{
	int middle, low = 0;
	int high = size(orders) - 1;

	while (low <= high) 
	{
		middle = (low + high) / 2;
		if (key < orders[middle].first) 
			high = middle - 1;
		else if (key > orders[middle].first) 
			low = middle + 1;
		else return true;
	}
	return false;
}

int main()
{
	Fibonnaci[0] = 1, Fibonnaci[1] = 2;
	InitializeFibonnaci();

	int numberofCases;
	int numberofFibos;
	vector <LongInt> fibNumbers;
	string sentence;
	string toprint;

	scanf("%d", &numberofCases);
	while (numberofCases--) {
		scanf("%d", &numberofFibos);
		fibNumbers.resize(numberofFibos);

		For (i, 0, size(fibNumbers))
			cin >> fibNumbers[i];
		cin.ignore();

		getline(cin, sentence);
		For (i, 0, size(sentence)) 
			if (!isupper(sentence[i])) 
				sentence.erase(i--, 1);

		if (size(sentence) > size(fibNumbers))
			sentence.resize(size(fibNumbers));

		For (i, 0, size(sentence))
			orders.push_back(make_pair(fibNumbers[i], sentence[i]));

		sort(All(orders));
		for (int i = 0, j = 0; j < size(orders); i++)
			BS(Fibonnaci[i]) ? toprint += orders[j++].second : toprint += ' ';

		while (size(toprint) != 0 && toprint[size(toprint) - 1] == ' ') 
			toprint.erase(toprint[size(toprint) - 1], 1);
		cout << toprint << endl;

		toprint.clear(), orders.clear();
	}
	return 0;
}