/*
ID: 1010
PROG: msquare
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
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define MAX 8

map<string,bool> vis;
string trg;

struct state
{
	state() {}
	state(string nw,string res,int c)
	{
		this->nw=nw;
		this->res=res;
		this->c=c;
	}
	string nw,res;
	int c;
};

void doA(queue<state>& q,string nw,string res,int c)
{
	reverse(nw.begin(),nw.end());
	if (vis[nw]) return;
	vis[nw]=true;
	q.push(state(nw,res+"A",c+1));
}

void doB(queue<state>& q,string nw,string res,int c)
{
	char temp=nw[3];
	for (int i=3;i>0;i--) nw[i]=nw[i-1];
	nw[0]=temp;
	temp=nw[4];
	for (int i=4;i<MAX-1;i++) nw[i]=nw[i+1];
	nw[7]=temp;
	if (vis[nw]) return;
	vis[nw]=true;
	q.push(state(nw,res+"B",c+1));
}

void doC(queue<state>& q,string nw,string res,int c)
{
	swap(nw[6],nw[1]);
	swap(nw[5],nw[6]);
	swap(nw[2],nw[5]);
	if (vis[nw]) return;
	vis[nw]=true;
	q.push(state(nw,res+"C",c+1));
}

pair<int,string> solve()
{
	queue<state> q;
	q.push(state("12345678","",0));
	vis[q.front().nw]=true;
	while (!q.empty())
	{
		string nw=q.front().nw;
		string res=q.front().res;
		int c=q.front().c;q.pop();
		if (nw==trg) return make_pair(c,res);
		doA(q,nw,res,c);
		doB(q,nw,res,c);
		doC(q,nw,res,c);
	}
	return make_pair(0,"");
}

pair<int,string> _main()
{
	REP(i,MAX) {int n;cin>>n;trg+=(n+'0');}
	return solve();
}

int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	pair<int,string> res=_main();
	cout<<res.first<<endl<<res.second<<endl;
	return 0;
}