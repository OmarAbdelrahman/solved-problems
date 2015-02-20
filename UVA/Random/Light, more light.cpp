#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long N;
	while (cin >> N && N != 0)
	{
		long long result = sqrt((double)N);
		N == result * result ? puts("yes") : puts("no");
	}
	return 0;
}