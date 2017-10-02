/*
ID: 1010
PROG: butter
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

typedef vector<pair<int,int> > List;
typedef vector<List> AdjacentList;
int const INF=0x3f3f3f3f;

int N,P,C;
AdjacentList g;
map<int,int> ncows;

struct node
{
	node() {}
	node(int i,int c)
		: indx(i),cost(c) {}
	int indx,cost;
};

class compare
{
public:
	bool operator() (const node& n1, const node& n2) const
	{
		return n1.cost>n2.cost;
	}
};

template<class T> inline void getMin(T& a,T b)
{
	if (b<a) a=b;
}

int solve(int src)
{
	vector<int> dist(g.size(),INF);
	vector<bool> vis(g.size(),false);
	priority_queue<node,vector<node>,compare> q;
	q.push(node(src,0));
	dist[src]=0;
	while (!q.empty())
	{
		int indx=q.top().indx;
		int cost=q.top().cost;
		q.pop();
		if (vis[indx]) continue;
		vis[indx]=true;
		for (vector<pair<int,int> >::iterator it=g[indx].begin();it!=g[indx].end();it++)
		{
			int newc=cost+it->second;
			if (newc<dist[it->first])
			{
				dist[it->first]=newc;
				q.push(node(it->first,newc));
			}
		}
	}
	int sum=0;
	for (int j=0;j<dist.size();++j) if (dist[j]!=INF)
		sum+=dist[j]*ncows[j];
	return sum;
}

int _main()
{
	cin>>N>>P>>C;
	for (int i=0;i<N;++i)
	{
		int n;cin>>n;
		ncows[n-1]++;
	}
	g=AdjacentList(P);
	for (int i=0;i<C;++i)
	{
		int a,b,c;cin>>a>>b>>c;
		g[a-1].push_back(make_pair(b-1,c));
		g[b-1].push_back(make_pair(a-1,c));
	}
	int res=INF;
	for (int i=0;i<P;++i) getMin(res,solve(i));
	return res;
}

int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	cout<<_main()<<endl;
	return 0;
}