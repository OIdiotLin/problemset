#include <stdio.h>
int main()
{
	int i,t,l,r,ans=0;
	scanf("%d%d",&l,&r);
	for(i=l;i<=r;i++)
	{
		t=i;
		while(t)
		{
			if((t+8)%10==0)
				ans++;
			t/=10;
		}
	}
	printf("%d",ans);
	return 0;
}
