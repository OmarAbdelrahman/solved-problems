// BEGIN CUT HERE

// END CUT HERE

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
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int64;
#define MAX 52

int dp[MAX][MAX];
vector<int> cuts;

int solve(int s,int e)
{
	int& ret=dp[s][e];
	if (ret!=-1) return ret;
	if (e-s==1) return ret=0;
	ret=1<<29;
	for (int mid=s+1;mid<e;mid++)
		ret=min(ret,cuts[e]-cuts[s]+solve(s,mid)+solve(mid,e));
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int length;
	while (cin>>length && length)
	{
		int nCuts; cin>>nCuts;
		cuts.push_back(0);
		for (int a=0;a<nCuts;a++)
		{
			int cut; cin>>cut;
			cuts.push_back(cut);
		}
		cuts.push_back(length);
		memset(dp,-1,sizeof(dp));
		cout<<"The minimum cutting is "<<solve(0,cuts.size()-1)<<"."<<endl;
		cuts.clear();
	}
	return 0;
}