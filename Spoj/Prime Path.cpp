#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define foreach(i, c)                 for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

const int oo = 0x3f3f3f3f;
const double eps = 1e-12;
typedef long long i64;
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;

bool prime[10000];

void GeneratePrimes() 
{
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < sqrtl(10000) + 1; i++)
		if (prime[i]) for (int j = i * i; j < 10000; j += i)
			prime[j] = false;
}

char source[5];
char destination[5];
bool visited[10000];

struct State_t 
{
	int cost;
	char digit[5];
	State_t() {}
	State_t(char* _digit, int _cost)
	{
		strcpy(digit, _digit);
		cost = _cost;
	}
}current, temp;

inline int GetCost()
{
	queue <State_t> fringe;
	fringe.push(State_t(source, 0));
	visited[atoi(source)] = true;

	while (!fringe.empty())
	{
		current = temp = fringe.front();

		if (strcmp(current.digit, destination) == 0)
			return current.cost;

		for (int i = 0; i < 4; i++)
		{
			for (char j = (i > 0) ? '0' : '1'; j <= '9'; j++)
			{
				current.digit[i] = j;
				int number = atoi(current.digit);
				if (prime[number] && !visited[number])
				{
					visited[number] = true;
					fringe.push(State_t(current.digit, current.cost + 1));
				}
			}
			current = temp;
		}

		fringe.pop();
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	GeneratePrimes();

	int numberofCases;
	scanf("%d", &numberofCases);
	
	while (numberofCases--)
	{
		scanf("%s%s", source, destination);
		if (strcmp(source, destination) == 0)
		{
			puts("0"); continue;
		}
		memset(visited, false, sizeof(visited));
		
		int output = GetCost();
		(output == -1) ? puts("Impossible") : printf("%d\n", output);
	}

	return 0;
}