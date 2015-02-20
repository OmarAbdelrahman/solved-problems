#include <iostream>
#include <string>
using namespace std;

#define size(A) ((int)A.size())
string AddTwoStrings(string&, string&);
void MakeLengthsEqual(string&, string&);

int main()
{
	string Fibonaaci[5001];
	Fibonaaci[0] = "0", Fibonaaci[1] = "1";

	for (int i = 2; i < 5001; i++)
	{
		if (size(Fibonaaci[i-1]) == size(Fibonaaci[i-2]))
			Fibonaaci[i] = AddTwoStrings(Fibonaaci[i-1], Fibonaaci[i-2]);
		else {
			MakeLengthsEqual(Fibonaaci[i-1], Fibonaaci[i-2]);
			Fibonaaci[i] = AddTwoStrings(Fibonaaci[i-1], Fibonaaci[i-2]);
		}
	}

	int indexNumber;
	while (cin >> indexNumber) {
		if (indexNumber == 0) {
			puts("0");
			continue;
		}
		if (Fibonaaci[indexNumber][0] == '0')
			Fibonaaci[indexNumber].erase(0, 1);
		cout << Fibonaaci[indexNumber] << endl;
	}

	return 0;
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

string AddTwoStrings(string &firstNumber, string &secondNumber)
{
	char remainderCarry = '0';
	string resultNumber = firstNumber;

	for (int i = size(firstNumber) - 1; i >= 0; i--)
	{
		resultNumber[i] = ((remainderCarry - '0') + (firstNumber[i] - '0') + (secondNumber[i] - '0') + '0');
		
		if (i != 0) {
			if (resultNumber[i] > '9') {
				resultNumber[i] -= 10;
				remainderCarry = '1';
			}
			else
				remainderCarry = '0';
		} else {
			if (resultNumber[i] > '9') {
				resultNumber[i] -= 10;
				resultNumber.insert(0, 1, '1');
			}
		}
	}
	return resultNumber;
}