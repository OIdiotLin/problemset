/*#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN 370
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

const int Month[12]={0,31,60,91,121,152,182,213,244,274,305,335};


bool Day[MAXN];
int Ans,N;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("heaven.in","r",stdin);
	freopen("heaven.out","w",stdout);
	#endif
	cin>>N;
	if(N==0)
	{
		cout<<86400<<endl;
		exit(0);
	}
	memset(Day,false,sizeof(Day));
	Ans=-INF;
}

void work()
{
	int m,d,h=0;
	for(int i=1;i<=N;i++)
	{
		cin>>m>>d;
		d+=Month[m-1];
		Day[d]=true;
	}
//	#ifdef Debug
	
	for(int i=1;i<=MAXN;i++)
	{
		if(Day[i])
			h=0;
		else{
			h++;
			Ans=max(Ans,h);
		}
	}
	cout<<(int)((double)(Ans)/366.0*24*3600+0.5)<<endl;
}

int main()
{
	init();
	work();
	return 0;
}*/
#include <stdio.h>
int main() {
	freopen("heaven.in","r",stdin);
	freopen("heaven.out","w",stdout);
	int months[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int month[366],day[366],count[366]={0};//
	int N,i,j;
	int max=count[0],t;
	double result;
	void bubble(int a[],int b[],int n);
	scanf("%d",&N);
	if(N==0) {//ERROR
		printf("86400\n");
		return 0;
	}
	for(i=0;i<N;i++) scanf("%d%d",&month[i],&day[i]);
	bubble(month,day,N);
	for(i=0;i<N;i++) {
		for(j=0;j<month[i]-1;j++) {
			count[i]+=months[j];
		}
		for(j=1;j<=day[i];j++)
			count[i]++;
		count[i]-=(i+1);
	}
	for(i=1;i<N;i++) {
		t=count[i]-count[i-1];
		if(t>max) max=t;
	}
	t=366-count[N-1]-N;//ERROR
	if(t>max) max=t;
	result=1.0*max/366*24*3600;//ERROR
	printf("%.0lf\n",result); 
	return 0;
}

void bubble(int a[],int b[],int n) {
	int i,j,t;
	for(i=1;i<n;i++) 
		for(j=0;j<n-i;j++) 
			if(a[j]>a[j+1]||a[j]==a[j+1]&&b[j]>b[j+1]) {
				t=a[j];a[j]=a[j+1];a[j+1]=t;
				t=b[j];b[j]=b[j+1];b[j+1]=t;
			}
}
