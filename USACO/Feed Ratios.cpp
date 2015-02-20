/*
ID: 1010
PROG: ratios
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

#define MAX 101

struct ratio
{
	ratio() {}
	ratio(int _x,int _y,int _z)
		: x(_x),y(_y),z(_z) {}
	int x,y,z;
}mix[3];

void _main()
{
	int x,y,z;cin>>x>>y>>z;
	for (int i=0;i<3;++i) cin>>mix[i].x>>mix[i].y>>mix[i].z;
	int sum=0x3f3f3f3f,aa,bb,cc,dd;
	aa=bb=cc=dd=-1;
	for (int a=0;a<MAX;++a) for (int b=0;b<MAX;++b) for (int c=0;c<MAX;++c) for (int d=0;d<MAX;++d)
	{
		if (!a && !b && !c && !d) continue;
		ratio now,res(d*x,d*y,d*z);
		now.x=a*mix[0].x+b*mix[1].x+c*mix[2].x;
		now.y=a*mix[0].y+b*mix[1].y+c*mix[2].y;
		now.z=a*mix[0].z+b*mix[1].z+c*mix[2].z;
		if (res.x==now.x && res.y==now.y && res.z==now.z && a+b+c<sum)
		{
			sum=a+b+c;
			aa=a,bb=b,cc=c,dd=d;
		}
	}
	if (sum==0x3f3f3f3f) {cout<<"NONE"<<endl;return;}
	cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<endl;
}

int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	_main();
	return 0;
}