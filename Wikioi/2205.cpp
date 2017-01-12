
#include <stdio.h>
#define Maxn 1000
#define Zy 9901
int data[Maxn],f[Maxn][2002];
int n,j,i,ans,x;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&data[i]);
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans=(ans+1)%Zy;
		for(j=i-1;j>=1;j--)
		{
			x=data[i]-data[j];
			ans=(ans+f[j][x])%Zy;
			f[i][x]=(f[i][x]+f[j][x])%Zy;
		}
	}
	printf("%d",ans);
	return 0;
}
