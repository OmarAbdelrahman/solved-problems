#include <iostream>
using namespace std;

int main()
{
	short _row, _coloumn;
	while (cin >> _row >> _coloumn) 
	{
		cout << (_coloumn - 1) + ((_row - 1) * _coloumn) << endl;
	}
	return 0;
}