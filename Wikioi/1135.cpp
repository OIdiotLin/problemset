#include <stdio.h>
const int K=60;
int n,k,p,c,v,s,f;
int a[K],b[K],u[K];

int main()
{
    scanf("%d %d %d",&n,&k,&p);
    for(int i=1; i<=n; i++)
	{
        scanf("%d %d",&c,&v);
        if(v <= p) f=i;
        if(f >= u[c]) b[c]=a[c];
        s += b[c];
        a[c]++;
        u[c]=i;
    }
    printf("%d\n",s);
    return 0;
}
