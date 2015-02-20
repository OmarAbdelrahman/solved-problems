#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

bool can(int people, int coco)
{
	int turn;
	for (turn = 0; turn < people && coco % people == 1; ++turn)
		coco -= (coco / people + 1);
    return turn == people && coco % people == 0;
}

int main()
{
	for (int coconuts; scanf("%d", &coconuts) && coconuts >= 0;)
	{
		bool found = false;
		int people = sqrt(coconuts * 1.0) + 1;
		for (; people >= 2; --people)
		{
			if (can(people, coconuts))
			{
				found = true;
				break;
			}
		}
		if (found)
			printf("%d coconuts, %d people and 1 monkey\n", coconuts, people);
		else
			printf("%d coconuts, no solution\n", coconuts);
	}
	return 0;
}