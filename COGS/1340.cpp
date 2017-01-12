#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 350
#define LHD 10000
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int N,M;
int i,j;
int Num[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("bzoj_2729.in","r",stdin);
	freopen("bzoj_2729.out","w",stdout);
	#endif
	cin>>N>>M;
	Num[0]=1;
}

void Mul()
{
	Num[1]*=i;
	for(j=2;j<=Num[0];j++)
	{
		Num[j]*=i;
		if(Num[j-1]>=LHD)
		{
			Num[j]+=Num[j-1]/LHD;
			Num[j-1]%=LHD;
		}
	}
	while(Num[Num[0]]>=LHD)
	{
		Num[0]++;
		Num[Num[0]]=Num[Num[0]-1]/LHD;
		Num[Num[0]-1]%=LHD;
	}
}

void work()
{
	init();
	if(M>N+3)
	{
		cout<<0<<endl;
		return;
	}
	Num[1]=(N+2)*(N+3)-2*(N-M+3);
	for(i=2;i<=N+1;i++)
		Mul();
	for(i=N-M+4;i<=N+2;i++)
		Mul();
	cout<<Num[Num[0]];
	for(i=Num[0]-1;i>0;i--)
	{
		if(Num[i]<1000)
			cout<<0;
		if(Num[i]<100)
			cout<<0;
		if(Num[i]<10)
			cout<<0;
		cout<<Num[i];
	}
	cout<<endl;
}

int main()
{
	work();
	return 0;
}

