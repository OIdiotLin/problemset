#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 10010
#define INF 1<<28
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;

int A[MAXN],f[MAXN];
int N,M;

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	#endif
	memset(f,0,sizeof(f));
	memset(A,0,sizeof(A));
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	cin>>M;
}

void Dp()
{
	f[N]=1;
	for(int i=N-1;i>=0;i--)
	{
		f[i]=1;
		for(int j=i+1;j<=N;j++)
		{
			if(A[i]<A[j] && f[i]<f[j]+1)
				f[i]=f[j]+1;
		}
	}
}

void work()
{
	int Len,t;
	int pres;
	cin>>Len;
	for(int i=1;i<=N;i++)
	{
		if(f[i]<Len)
			continue;
		t=i;
		pres=A[i];
		for(int j=1;j<=Len;j++)
		{
			cout<<A[t]<<" ";
			while(1)
			{
				t++;
				if((A[t]<=pres || f[t]<Len-j) && t<N)
					continue;
				break;
			}
			pres=A[t];
		}
		cout<<endl;
		return;
	}
	cout<<"Impossible"<<endl;
}

int main()
{
	init();
	Dp();
	for(int i=1;i<=M;i++)
		work();
	return 0;
}

