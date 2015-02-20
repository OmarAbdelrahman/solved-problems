#include <iostream>
#include <string>
using namespace std;

#define size(A) ((int)A.size())

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

string add(string &firstNumber, string &secondNumber)
{
	MakeLengthsEqual(firstNumber, secondNumber);

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

string multiply(string n1, string n2)
{
	if(n1.length() > n2.length()) // 
	n1.swap(n2);

	string res = "0";
	for(int i=n1.length()-1; i>=0; i--)
	{
		string temp = n2;
		int currentDigit = n1[i]-'0';
		int carry = 0;

		for(int j=temp.length()-1; j>=0; j--)
		{
			temp[j] = ((temp[j]-'0')*currentDigit) + carry;

			if(temp[j] > 9)
			{
				carry = (temp[j]/10);
				temp[j] -= (carry*10);
			}
			else
				carry = 0;

			temp[j]+='0'; // back to string mode
		}
		if (carry > 0)
			temp.insert(0, 1, (carry + '0'));
		temp.append((n1.length() - i - 1), '0');
		res = add(res, temp);
	}
	while (res[0] == '0' && res.length() != 1)
		res.erase(0, 1);
	return res;
}

int main()
{
	int number;
	string Factorial[1002];
	Factorial[0] = "1";
	
	string temp = "1";
	string product = "1";
	string one = "1";

	for (int index = 1; index < 1001; index++)
	{
		product = add(product, one);
		temp = multiply(temp, product);
		Factorial[index] = temp;
	}

	int toDisplay;
	while (cin >> number) 
	{
		toDisplay = 0;
		for (int i = 0; i < size(Factorial[number - 1]); i++)
			toDisplay += Factorial[number - 1][i] - '0';
		cout << toDisplay << endl;
	}
	
	return 0;
}