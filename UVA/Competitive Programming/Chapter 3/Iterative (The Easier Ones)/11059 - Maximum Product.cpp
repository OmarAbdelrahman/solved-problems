#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define Size(A) ((int)A.size())

int main()
{
	int N;
	long long MAX;
	long long product;
	vector<int> vect;
	for (int caseNumber = 1; cin >> N; caseNumber++)
	{
		MAX = 0;
		vect.resize(N);
		for (int i = 0; i < Size(vect); i++)
			cin >> vect[i];
		for (int i = 0; i < Size(vect); i++)
		{
			product = 1;
			for (int j = i; j < Size(vect); j++)
			{
				product *= vect[j];
				MAX = max(MAX, product);
			}
		}
		cout << "Case #" << caseNumber << ": The maximum product is " << MAX << "." << endl << endl;
	}
	return 0;
}