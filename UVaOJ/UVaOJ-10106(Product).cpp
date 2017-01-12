/*
	Name: Product
	Copyright: UVaOJ-10106
	Author: LHD
	Date: 23/11/13 09:21
	Description: 多组两个大数相乘。在高精度乘法上加个while 即可 
*/

#include <stdio.h>
#include <string.h>
#define MAXN 550
int Ans[MAXN+1]={0};
void X(char *MultiplierA,char *MultiplierB)
{
	int len1,len2;
	int i,j,A,B,k;
	int count=0;
	len1=strlen(MultiplierA);
	len2=strlen(MultiplierB);
	for (i=len1-1;i>=0;i--)
	{
		k=MAXN;
		k-=count++;
		A=MultiplierA[i]-'0';
		for (j=len2-1;j>=0;j--)
        {
			B=MultiplierB[j]-'0';
			Ans[k--]+=A*B;
        }
        for (j=MAXN;j>k;j--)
           if (Ans[j]>9)
           {
               Ans[j-1]+=Ans[j]/10;
               Ans[j]%=10;
           }
    }
    return;
}
int main()
{
    int i;
    char a[MAXN],b[MAXN];
    while(scanf("%s%s",a,b)!=EOF)
    {
        if (!strcmp(a,"0")||!strcmp(b,"0"))
        {
            printf("0\n");continue;
        }
        memset(Ans,0,sizeof(Ans));			//初始化Ans数组 
        X(a,b);
        for (i=0; i<=MAXN; i++)  if (Ans[i]) break;
        for (; i<=MAXN; i++)  printf("%d",Ans[i]);
        printf("\n");
    }
    return 0;
}
