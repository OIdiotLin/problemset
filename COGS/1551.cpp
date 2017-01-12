#include <iostream>
#include <cstring>
#include <cstdio>
#define INF ((1<<30))
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

long long N,Sum;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("goz.in","r",stdin);
	freopen("goz.out","w",stdout);
	#endif
	cin>>N;
	Sum=0;
}

void Greedy()
{
	bool flag=false;
	long long a,b,Min=INF,Max=-INF;
	while(N--)
	{
		cin>>a>>b;
		if(a>=b)
			Min=0;
		else if(b-a<Min)
			Min=b-a;
		if(a>b)
			Sum+=a;
		else 	
			Sum+=b;
		#ifdef Debug
		cout<<"Round #"<<N+1<<" : Sum = "<<Sum<<endl;
		#endif
	}
	Sum-=Min;
}

int main()
{
	init();
	Greedy();
	cout<<Sum<<endl;
	return 0;
}

