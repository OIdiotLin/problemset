#include<stdio.h>
#include<math.h>
int main()
{
	int n,p,i,j,k;
	char s[100][100];
	char c[16][100]={"Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
	while(scanf("%d",&n))
	{
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		if(n>16)
			p=ceil(n/16)+1;
		for(i=0,j=0,k=0;j<16*p;i++,j++,k++)
		{
			if(i==n) i=0;
			if(j==16) k=0;
			printf("%s: %s\n",s[i],c[k]);
		}
	}
	return 0;
}
