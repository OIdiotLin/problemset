#include <stdio.h>
#define FILE

int n,s,i,j,Earn=0,sum=0;
int tfast,tslow,wfast,wslow;
int t[5000],w[5000];

int main()
{
	#ifdef FILE
	freopen("horsea.in","r",stdin);
	freopen("horsea.out","w",stdout);
	#endif

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(t[j]<t[j+1])
			{
				s=t[j];
				t[j]=t[j+1];
				t[j+1]=s;
			}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(w[j]<w[j+1])
			{
				s=w[j];
				w[j]=w[j+1];
				w[j+1]=s;
			}
	tfast=0;
	tslow=n-1;
	wfast=0;
	wslow=n-1;
	for(i=0;i<n;i++)
	{
		if(t[tfast]==w[wfast])
		{
			if(t[tslow]>w[wslow])
			{
				Earn++;
				tslow--;
				wslow--;
			}
			else if(t[tslow]<w[wslow])
			{
				Earn--;
				tslow--;
				wfast++;
			}
			else if(t[tslow]==w[wslow])
			{
				if(t[tslow]<w[wfast])
				{
					Earn--;
					tslow--;
					wfast++;
				}
				else if(t[tslow]==w[wfast])
					break;
			}
		}
		else if(t[tfast]>w[wfast])
		{
			Earn++;
			tfast++;
			wfast++;
		}
		else
		{
			Earn--;
			tslow--;
			wfast++;
		}
	}
	printf("%d\n",Earn);
	return 0;
}
