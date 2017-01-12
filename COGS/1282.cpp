#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-4
#define MAXN 1510
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define Debug
using namespace std;
typedef long long LL;

inline LL SQR(LL a){return a*a;}

struct Line{
	double x,y;
	LL dist;
	int x1,y1,x2,y2;
};
int N,cnt;
Line d[(MAXN*MAXN)/2];
LL Ans;
int x[MAXN],y[MAXN];
bool cmp(Line A,Line B)
{
	if(A.dist!=B.dist)			//以距离为第一关键字 
		return A.dist<B.dist;
	if(A.x!=B.x)				//x为第二关键字 
		return A.x<B.x;
	if(A.y!=B.y)				//y为第三关键字 
		return A.y<B.y;
}

bool Equal(Line A,Line B){
	return ((A.dist==B.dist) && (fabs(A.x-B.x)<eps) && (fabs(A.y-B.y)<eps));
}

void init()
{
	
	cnt=0;
	Ans=0;
	SpeedUp;
	#ifdef FILE
	freopen("crectangle.in","r",stdin);
//	freopen("crectangle.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>x[i]>>y[i];
	#ifdef Debug
	cout<<"reading Suc!"<<endl;
	#endif
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
		{
			d[++cnt]=(Line){
				(x[i]+x[j])*1.0/2,
				(y[i]+y[j])*1.0/2,
				SQR(x[i]-x[j])+SQR(y[i]-y[j]),
				x[i],y[i],x[j],y[j]
			};
		}
	sort(d+1,d+cnt+1,cmp);
	#ifdef Debug
	cout<<"Sorted Line:"<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<"Line["<<i<<"]:"<<endl
			<<"\tMidpoint = ("<<d[i].x<<","<<d[i].y<<")"<<endl
			<<"\tNode1 = ("<<d[i].x1<<","<<d[i].y1<<")"<<endl
			<<"\tNode2 = ("<<d[i].x2<<","<<d[i].y2<<")"<<endl
			<<"\tdist = "<<d[i].dist<<endl
			<<"--------------------------------------"<<endl;
	#endif
}

void work()
{
	int LHD=1;
	for(int i=2;i<=cnt+1;i++)
	{
		if(!Equal(d[i],d[i-1]))
		{
			for(int j=LHD;j<i;j++)
				for(int k=j+1;k<i;k++)
				{
					LL v=round(sqrt(
									SQR(d[j].x1-d[k].x1)+SQR(d[j].y1-d[k].y1))
							*sqrt(
									SQR(d[j].x1-d[k].x2)+SQR(d[j].y1-d[k].y2)));
					if(v>Ans)	Ans=v;
					#ifdef Debug
					cout<<"Loop "<<i<<"-"<<j<<"-"<<k<<":"<<"\tAns = "<<Ans<<endl;
					#endif
				}
			LHD=i;
		}
	}
}

int main()
{
	init();
	work();
	cout<<Ans<<endl;
	return 0;
}

