#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	long long _number;
	while (cin >> _number && _number >= 0)
	{
		if (_number == 0)
		{
			puts("0");
			continue;
		}
		stack<char> _converted;
		while (_number != 0)
		{
			_converted.push((_number % 3) + '0');
			_number /= 3;
		}
		while (!_converted.empty())
		{
			cout << _converted.top();
			_converted.pop();
		}
		cout << endl;
	}
	return 0;
}