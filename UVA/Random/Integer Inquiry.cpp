#include <iostream>
#include <string>
using namespace std;

#define size(A) ((int)A.size())
string AddTwoStrings(string&, string&);
void MakeLengthsEqual(string&, string&);

int main()
{
	string number;
	string result;

	while (cin >> number && number != "0")
	{
		MakeLengthsEqual(result, number);
		result = AddTwoStrings(result, number);
	}
	cout << result << endl;

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