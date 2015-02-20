#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string def = "DEFICIENT";
const string abn = "ABUNDANT";
const string per = "PERFECT";

int main()
{
	freopen("n.txt", "r", stdin);
	int sum;
	int number;

	for (int j = 0; cin >> number; j++)
	{
		sum = 0;

		if (!number) {
			puts("END OF OUTPUT");
			return 0;
		}

		if (!j) puts("PERFECTION OUTPUT");

		for (int i = 1; i < number; i++)
			if (!(number % i))
				sum += i;

		if (sum == number)
			cout << setw(5) << setiosflags(ios::right) << number << "  " << per << endl;
		else if (sum < number)
			cout << setw(5) << setiosflags(ios::right) << number << "  " << def << endl;
		else
			cout << setw(5) << setiosflags(ios::right) << number << "  " << abn << endl;
	}

	return 0;
}