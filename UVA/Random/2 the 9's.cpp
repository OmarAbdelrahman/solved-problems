#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define size(A) ((int)A.size())

int g_counter;

bool nineMultiple(string &p_number, int &p_sum, int index = 0)
{
	if (index == size(p_number))
	{
		if (p_sum % 9) return false;
		if (p_sum == 9) return true;
		p_number = "";
		while (p_sum)
		{
			p_number += ((p_sum % 10) + '0');
			p_sum /= 10;
		}
		g_counter++;
		reverse(p_number.begin(), p_number.end());
		return nineMultiple(p_number, p_sum);
	}
	p_sum += (p_number[index] - '0');
	return nineMultiple(p_number, p_sum, index + 1);
}

int main()
{
	int sum = 0;
	string _number;
	string _temp;
	while (cin >> _number && _number != "0")
	{
		sum = 0;
		g_counter = 1;
		_temp = _number;
		if (nineMultiple(_number, sum)) 
			cout << _temp << " is a multiple of 9 and has 9-degree " << g_counter << "." << endl;
		else 
			cout << _temp << " is not a multiple of 9." << endl;
	}
	return 0;
}