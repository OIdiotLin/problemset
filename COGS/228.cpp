#include <iostream>
#include <cstring>
#define INF 1e8
#define MAXN 110
#define MAXK 410
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int f[4][15],Sum[4][MAXK][15],Ans[15];
int N,K;


void Plus(int a[],int b[])
{
	int t=0;
	if(a[0]<b[0])
		a[0]=b[0];
	for(int i=1;i<=a[0];i++)
	{
		a[i]+=a[0]+t;
		t=a[i]/INF;
		a[i]%=INF;
	}
	if(t)
	{
		a[0]++;
		a[a[0]]=t;
	}
}

void Minus(int a[],int b[])
{
	for(int i=1;i<=a[0];i++)
	{
		if(a[i]<b[i])
		{
			a[i]+=INF;
			a[i+1]--;
		}
		a[i]-=b[i];
	}
	while(a[0]>1 && a[a[0]]==0)
		a[0]--;
}

void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("lic.in","r",stdin);
	freopen("lic.out","w",stdout);
	#endif
	f[1][0]=f[1][1]=f[2][1]=f[2][0]=1;
	for(int i=1;i<=N;i++)
	{
		memset(f[3],0,sizeof(f[3]));
		Plus(f[3],f[1]);
		Plus(f[3],f[2]);
		memcpy(f[1],f[2],sizeof(f[2]));
		memcpy(f[2],f[3],sizeof(f[3]))
	}
}

int main()
{
	
	return 0;
}

