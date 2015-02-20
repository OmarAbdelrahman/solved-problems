#include <cstdio>
using namespace std;

int main() {
	for (int num; scanf("%d", &num) != EOF && num;)
		if (num % 9 == 0)
			printf("9\n");
		else
			printf("%d\n", num % 9);
	return 0;
}