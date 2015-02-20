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

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define sz(A) ((int)A.size())
#define all(A) A.begin(), A.end()
#define FOR(i, v, Limit) for (int i = v; i < Limit; i++)
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

inline bool _plus(string& w)
{
	for(int i=0;i<sz(w);i++)
		if(w[i]=='_')return(true);
	return(false);
}

inline bool java(string& w)
{
	for(int i=0;i<sz(w);i++)
		if(isupper(w[i]))return(true);
	return(false);
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string W;
	while(cin>>W)
	{
		if(W[0]=='_'||W[sz(W)-1]=='_'||isupper(W[0]))
		{
			cout<<"Error!"<<endl;
			continue;
		}
		if(java(W)&&_plus(W))
		{
			cout<<"Error!"<<endl;
			continue;
		}
		else if(_plus(W))
		{
			bool(found)=false;
			for(int i=0;i<sz(W);i++)
				if(W[i]=='_')
					if(i+1<sz(W))
					{
						if(W[i+1]=='_')
						{
							cout<<"Error!"<<endl;
							found=true;
							break;
						}
						W[i+1]=toupper(W[i+1]);
						W.erase(i--,1);
					}
			if(found)continue;
		}
		else if(java(W))
		{
			for(int i=0;i<sz(W);i++)
				if(isupper(W[i]))
				{
					W[i]=tolower(W[i]);
					W.insert(i,"_");
				}
		}
		cout<<W<<endl;
	}
	return 0;
}