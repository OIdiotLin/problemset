#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define MAXN 40005
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

struct Point{
	int x,y;
};

Point P[MAXN];
double slope[MAXN];
int N,Ans,cnt;
bool flag=false;

bool equal(double a,double b){return fabs(a-b)<=1e-8;}
int cmp(const void *a,const void *b){return *(double *)a-*(double *)b>0 ? 1 : -1;}

void Cal_Slope(Point A,Point B)
{
	if(A.x!=B.x)
		slope[cnt++]=((double)A.y-(double)B.y)/((double)A.x-(double)B.x);
	else
		flag=true;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>P[i].x>>P[i].y;
		for(int j=0;j<i;j++)
			Cal_Slope(P[i],P[j]);
	}
	qsort(slope,cnt,sizeof(double),cmp);
}

void work()
{
	for(int i=1;i<cnt;i++)
		if(!equal(slope[i],slope[i-1]))
			Ans++;
	if(flag)
		Ans++;
	cout<<Ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}

