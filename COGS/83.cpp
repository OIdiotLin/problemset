#include <cstdio>
#define FILE
#define MAXN 1010

using namespace std;

int F[MAXN];
int N;

void DP(int n)
{
	F[0]=1;
	F[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i-2;j++)
			F[i]=(F[i]+F[j]*F[i-j-2])%12345;
		F[i]=(F[i]+F[i-1])%12345;
	}
}

int main()
{
	freopen("circlex.in","r",stdin);
	freopen("circlex.out","w",stdout);
	scanf("%d",&N);
	DP(N);
	printf("%d\n",F[N]);
	return 0;
}
