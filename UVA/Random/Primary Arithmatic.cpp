#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define size(A) ((int)A.size())

void MakeLengthsEqual(string&, string&);
void FillStrings(string&, string&, unsigned int, unsigned int);

int main()
{
	unsigned int firstNumber;
	unsigned int secondNumber;

	for ( ; cin >> firstNumber >> secondNumber; )
	{
		if (firstNumber == 0 && secondNumber == 0)
			return 0;

		string numberOne;
		string numberTwo;

		FillStrings(numberOne, numberTwo, firstNumber, secondNumber);
		MakeLengthsEqual(numberOne, numberTwo);

		int countCarry = 0;
		char remainderCarry = '0';
		for (int i = size(numberOne) - 1; i >= 0; i--)
		{
			char temp = ((remainderCarry - '0') + (numberOne[i] - '0') + (numberTwo[i] - '0')) + '0';

			if (temp > '9') {
				remainderCarry = '1';
				countCarry++;
			} else {
				remainderCarry = '0';
			}
		}

		if (!countCarry)
			puts("No carry operation.");
		else if (countCarry == 1)
			puts("1 carry operation.");
		else
			printf("%d carry operations.\n", countCarry);
	}
	return 0;
}

void FillStrings(string &one, string &two, unsigned int first, unsigned int second)
{
	while (first >= 10)
	{
		short temp = first % 10;
		first -= temp;
		first /= 10;
		one.push_back(temp + '0');
	}
	one.push_back((first % 10) + '0');
	reverse(one.begin(), one.end());

	while (second >= 10)
	{
		short temp = second % 10;
		second -= temp;
		second /= 10;
		two.push_back(temp + '0');
	}
	two.push_back((second % 10) + '0');
	reverse(two.begin(), two.end());
}

void MakeLengthsEqual(string &first, string &second)
{
	short length;
	if (size(first) > size(second)) {
		length = size(first) - size(second);
		second.insert(0, length, '0');
	}
	else if (size(first) < size(second)) {
		length = size(second) - size(first);
		first.insert(0, length, '0');
	}
	else return;
}