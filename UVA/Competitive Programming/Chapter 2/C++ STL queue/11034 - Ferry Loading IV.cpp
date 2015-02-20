#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

void removeUntil(int length, queue<int> &q)
{
	int cur = 0;
	while (!q.empty())
	{
		if (cur + q.front() > length)
			break;
		cur += q.front();
		q.pop();
	}
}

int solve(int length, queue<int> &L, queue<int> &R)
{
	int res = 0;
	bool left = true;
	for (; !L.empty() && !R.empty(); res++)
	{
		if (left)
		{
			removeUntil(length, L);
			left = false;
		}
		else
		{
			removeUntil(length, R);
			left = true;
		}
	}
	for (; !L.empty(); res++)
	{
		if (left)
		{
			removeUntil(length, L);
			left = false;
		}
		else
			left = true;
	}
	for (; !R.empty(); res++)
	{
		if (left)
			left = false;
		else
		{
			removeUntil(length, R);
			left = true;
		}
	}
	return res;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	while (T-- != 0)
	{
		int centimeters, cars;
		cin >> centimeters >> cars;
		centimeters *= 100;
		queue<int> L, R;
		for (int i = 0; i < cars; i++)
		{
			int length; cin >> length;
			string direction; cin >> direction;
			if (direction[0] == 'l')
				L.push(length);
			else
				R.push(length);
		}
		cout << solve(centimeters, L, R) << endl;
	}
	return 0;
}
