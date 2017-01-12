#include <stdio.h>

int main()
{
	freopen("lunch.in","r",stdin);
	freopen("lunch.out","w",stdout);
	
    int a[100001],h[100001];
    int i,n,j;
	scanf("%d",&n);
	if(n==0)
    { 
		printf("0\n");
		return 0;
    }
    int w;
    for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
    h[1]=a[1];
    w=1;
    for(i=2;i<=n;i++)
    {
		if(a[i]!=0)
			if(a[i]<h[w])
			{
				w++;
				h[w]=a[i];
			}
			else
			{
				j=w;
				while(j>=1 && h[j]<=a[i])
					j--;
          		if(a[i]>h[j+1])
					h[j+1]=a[i];
		}
    }
    printf("%d\n",w);
    return 0;
}
