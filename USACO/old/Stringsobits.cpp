/*
ID: 1010
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
#include <string.h>
#include <iomanip>
#include <limits.h>
using namespace std;

typedef long long _int;
#define MAX 32

int N,L;
_int dp[MAX][MAX],I;

void solve()
{
	for (int i=0;i<MAX;++i) dp[i][0]=dp[i][i]=dp[0][i]=1;
	for (int i=1;i<MAX;++i) for (int j=1;j<MAX;++j)
		dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
}

string _main()
{
	cin>>N>>L>>I;
	solve();
	string res="";
	for (int i=N-1;i>=0;--i)
		if (dp[i][L]<I)
		{
			res+="1";
			I-=dp[i][L--];
		}
		else res+="0";
	return res;
}

int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	cout<<_main()<<endl;
	return 0;
}