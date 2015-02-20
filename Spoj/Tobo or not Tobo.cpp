#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;

#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

using namespace std;

struct State
{
	int cost;
	char board[9];

	State() { }

	State(int cost, char* board)
	{
		this->cost = cost;
		strcpy(this->board, board);
	}
}initial(0, "123456789"), current;

int R;
string input;
char _rotate[9];
hash_map <int, bool> visited;
hash_map <int, int> values;

inline char* A_ClockWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[0] = s[3];
	_rotate[1] = s[0];
	_rotate[3] = s[4];
	_rotate[4] = s[1];

	return _rotate;
}

inline char* B_ClockWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[1] = s[4];
	_rotate[2] = s[1];
	_rotate[4] = s[5];
	_rotate[5] = s[2];

	return _rotate;
}

inline char* C_ClockWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[3] = s[6];
	_rotate[4] = s[3];
	_rotate[7] = s[4];
	_rotate[6] = s[7];

	return _rotate;
}

inline char* D_ClockWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[4] = s[7];
	_rotate[5] = s[4];
	_rotate[7] = s[8];
	_rotate[8] = s[5];

	return _rotate;
}

inline char* A_AntiWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[0] = s[1];
	_rotate[1] = s[4];
	_rotate[3] = s[0];
	_rotate[4] = s[3];

	return _rotate;
}

inline char* B_AntiWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[1] = s[2];
	_rotate[2] = s[5];
	_rotate[4] = s[1];
	_rotate[5] = s[4];

	return _rotate;
}

inline char* C_AntiWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[3] = s[4];
	_rotate[4] = s[7];
	_rotate[6] = s[3];
	_rotate[7] = s[6];

	return _rotate;
}

inline char* D_AntiWise(char s[9])
{
	strcpy(_rotate, s);

	_rotate[4] = s[5];
	_rotate[5] = s[8];
	_rotate[7] = s[4];
	_rotate[8] = s[7];

	return _rotate;
}

void BFS();

int main()
{
	freopen("in.txt", "r", stdin);
	BFS();
	for (int c = 1; cin >> input && input != "0000000000";)
	{
		R = input[0] - '0';
		input.erase(input.begin());
		int b = values[atoi(input.c_str())];
		int out = (b <= R) ? b : -1;
		printf("%d. %d\n", c, out);
		c = c + 1;
	}
	return 0;
}

void BFS()
{
	int number;
	char* number_S;
	queue <State> bfs;
	bfs.push(initial);

	visited[123456789] = true;

	while (!bfs.empty())
	{
		current = bfs.front();
		bfs.pop();

		values[atoi(current.board)] = current.cost;

		if (current.cost > 9)
			return;

		number_S = A_ClockWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = A_AntiWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = B_ClockWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = B_AntiWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = C_ClockWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = C_AntiWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = D_ClockWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}

		number_S = D_AntiWise(current.board);
		number = atoi(number_S);
		if (!visited[number])
		{
			visited[number] = true;
			bfs.push(State(current.cost + 1, number_S));
		}
	}
}