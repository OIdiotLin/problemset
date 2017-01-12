#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAXN
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
	return (b==0)? a: gcd(b,a%b);
}

LL Ans,N;
LL r;

LL Cal(LL i)
{
	LL S=0,tmp;
	for(int j=1;j*j<i;j++)
	{
		tmp=(int)sqrt((double)(i-j*j));
		if(tmp<=j)
			break;
		if(tmp*tmp+j*j==i && gcd(j,tmp)==1 && ((tmp*tmp-j*j)&1))
			S++;
	}
	return S;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("cir.in","r",stdin);
	freopen("cir.out","w",stdout);
	#endif
	cin>>r;
	Ans=0;
}

void work()
{
	init();
	for(int i=1;i*i<=r;i++)
	{
		if(r%i)
			continue;
		Ans+=2*Cal(i);
		if(i*i==r)
			break;
		Ans+=2*Cal(r/i);
	}
	cout<<4+Ans*4<<endl;
}

int main()
{
	work();
	return 0;
}

