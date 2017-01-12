#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN 15000
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
#define INF 1<<30
using namespace std;

typedef long long LL;
inline int cmp(const void *a,const void *b){return *(long long *)a-*(long long *)b;}
LL N,K,C;
LL S[MAXN],f[MAXN];

LL Reward(int i,int j){
	return (S[i]-S[j+1])*(S[i]-S[j+1])+C;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("dividea.in","r",stdin);
	freopen("dividea.out","w",stdout);
	#endif
	memset(S,0,sizeof(S));
	memset(f,0,sizeof(f));
	cin>>N>>K>>C;
	for(int i=1;i<=N;i++)
	{
		f[i]=INF;
		cin>>S[i];
	}
	qsort(S+1,N,sizeof(LL),cmp);
}

void Dp()
{
	f[1]=C;
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<=i-K;j++)
		{
			f[i]=min(f[i],f[j]+Reward(i,j));
			
		}
			
	}
		
}

void work()
{
	init();
	Dp();
	cout<<f[N]<<endl;
}

int main()
{
	work();
	return 0;
}

