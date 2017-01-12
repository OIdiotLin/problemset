#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAXN 1100
#define INF 1<<16
#define eps 1e-7
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

struct Square{
	int x,y,l;
};
Square p[MAXN];
bool insight[MAXN];
int N,Ans;

inline bool F_equal(double a,double b){
	return fabs(a-b)<eps;
}

bool cover(double k,Square s1,int tx,int ty,double Min)
{
	double x,y;
	if(s1.x==tx)
	{
		y=k*s1.x;
		if(F_equal(y,s1.y) || F_equal(y,ty) || y<ty && y>s1.y)
		{
			if(s1.x<Min)
			{
				Min=s1.x;
				return true;
			}
		}
	}
	else
	{
		x=s1.y/k;
		if(F_equal(x,tx))
			return false;
		else if(F_equal(x,s1.x) || s1.x<x && tx>x)
			if(x<Min)
			{
				Min=x;
				return true;
			}
	}
	return false;
}

void judge(int x,int y)
{
	double k=(double)y/(double)x,Min=INF;
	int cnt=0;
	for(int i=1;i<=N;i++)
		if(p[i].x<Min)
			if(!cover(k,p[i],p[i].x,p[i].y+p[i].l,Min))
				if(cover(k,p[i],p[i].x+p[i].l,p[i].y,Min))
					cnt=i;
				else;
			else
				cnt=i;
	if(cnt)
		insight[cnt]=true;
	
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("juxing.in","r",stdin);
	freopen("juxing.out","w",stdout);
	#endif
	memset(insight,false,sizeof (insight));
	Ans=0;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>p[i].x>>p[i].y>>p[i].l;
}

void work()
{
	for(int i=1;i<=N;i++)
	{
		judge(p[i].x+p[i].l,p[i].y);
		if(!insight[i])
			judge(p[i].x,p[i].y+p[i].l); 
	}
	for(int i=1;i<=N;i++)
		if(insight[i])
			Ans++;
}

int main()
{
	init();
	work();
	cout<<Ans<<endl;
	return 0;
}

