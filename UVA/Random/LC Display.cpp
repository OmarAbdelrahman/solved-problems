#include <iostream>
#include <string>
using namespace std;

int length;
string number;
const char space = ' ';
const char vertical = '|';
const char horizontal = '-';

void _Space(int);
void _Vertical(int);
void _Horizontal(int);
void DrawFirstLine();
void DrawUpperPart();
void DrawMiddleLine();
void DrawLowerPart();
void DrawLastLine();

int main()
{
	for ( ;cin >> length >> number;)
	{
		if (length == 0 && number == "0") break;

		DrawFirstLine();
		DrawUpperPart();
		DrawMiddleLine();
		DrawLowerPart();
		DrawLastLine();

		cout << endl;
	}
	return 0;
}

void _Space(int num)
{ 
	for (int i = 0; i < num; i++) 
		cout << space; 
}

void _Vertical(int num)
{
	for (int i = 0; i < num; i++)
		cout << vertical;
}

void _Horizontal(int num)
{
	for (int i = 0; i < num; i++)
		cout << horizontal;
}

void DrawFirstLine()
{
	for (int i = 0; i < number.length(); i++)
	{
		if (i) cout << space;

		if (number[i] == '1') _Space(length + 2);
		if (number[i] == '4') _Space(length + 2);

		if (number[i] == '2' || number[i] == '3' || number[i] == '5' || number[i] == '6' ||
			number[i] == '7' || number[i] == '8' || number[i] == '9' || number[i] == '0')
		{
			_Space(1);
			_Horizontal(length);
			_Space(1);
		}

		if (i == number.length() - 1) cout << endl;
	}
}

void DrawUpperPart()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < number.length(); j++)
		{
			if (j) cout << space;

			if (number[j] == '1' || number[j] == '2' || number[j] == '3' || number[j] == '7')
			{
				_Space(length + 1);
				_Vertical(1);
			}
			if (number[j] == '4' || number[j] == '8' || number[j] == '9' || number[j] == '0')
			{
				_Vertical(1);
				_Space(length);
				_Vertical(1);
			}
			if (number[j] == '5' || number[j] == '6')
			{
				_Vertical(1);
				_Space(length + 1);
			}

			if (j == number.length() - 1) cout << endl;
		}
	}
}

void DrawMiddleLine()
{
	for (int i = 0; i < number.length(); i++)
	{
		if (i) cout << space;

		if (number[i] == '1' || number[i] == '7' || number[i] == '0')
			_Space(length + 2);

		if (number[i] == '2' || number[i] == '3' || number[i] == '4' ||
			number[i] == '5' || number[i] == '6' || number[i] == '8' || number[i] == '9')
		{
			_Space(1);
			_Horizontal(length);
			_Space(1);
		}

		if (i == number.length() - 1) cout << endl;
	}
}

void DrawLowerPart()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < number.length(); j++)
		{
			if (j) cout << space;

			if (number[j] == '1' || number[j] == '3' || number[j] == '4' ||
				number[j] == '5' || number[j] == '7' || number[j] == '9')
			{
				_Space(length + 1);
				_Vertical(1);
			}

			if (number[j] == '2')
			{
				_Vertical(1);
				_Space(length + 1);
			}

			if (number[j] == '6' || number[j] == '8' || number[j] == '0')
			{
				_Vertical(1);
				_Space(length);
				_Vertical(1);
			}

			if (j == number.length() - 1) cout << endl;
		}
	}
}

void DrawLastLine()
{
	for (int i = 0; i < number.length(); i++)
	{
		if (i) cout << space;

		if (number[i] == '1' || number[i] == '7' || number[i] == '4')
			_Space(length + 2);

		if (number[i] == '2' || number[i] == '3' || number[i] == '0' ||
			number[i] == '5' || number[i] == '6' || number[i] == '8' || number[i] == '9')
		{
			_Space(1);
			_Horizontal(length);
			_Space(1);
		}

		if (i == number.length() - 1) cout << endl;
	}
}