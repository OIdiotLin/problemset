#include <iostream>
#include <cstring>
#define MAXN 500
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
inline int P(int a){return a*a*a;}

using namespace std;

int N,M,t,now;
int Nut[MAXN];

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("1078.in","r",stdin);
	//freopen("1078.out","w",stdout);
	#endif
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		Nut[i]=i;
	now=1;
}

void pick()
{
	for(int i=1;i<=M;i++)
	{
		now+=(P(i)%5)+1;
		if(now>N)
			now=(P(i)%5)+2;
		t=Nut[now];
		for(int j=now;j<N;j++)
			Nut[j]=Nut[j+1];
		N--;
	}
}

void work()
{
	init();
	pick();
	cout<<t<<endl;
}

int main()
{
	work();
	return 0;
}

