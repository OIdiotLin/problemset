/*
ID: MagicLin
LANG: C
PROG: beads
*/
#include <stdio.h>
#include <string.h>
#define FILE
int mod(int x,int n)
{
	while(x<=0)
		x+=n;
	return x%n;
}

int Max(int a,int b)
{
	if (a>b) 
		return a;
	else
		return b;
}

int Work(char* neck,int n)
{
    int i,k,Red_L[400],Red_R[400],Blue_L[400],Blue_R[400],ans=0;
    for(k=0;k<n;++k)
		if(neck[k]=='b')
			break;
    if(neck[k]!='b')
		return n;
		
    Red_L[k]=0;
	Red_R[k]=0;
    i=mod(k+1,n);
    
	while(i!=k) 
	{
		Red_L[i]=(neck[i]!='b') ? (Red_L[mod(i-1,n)]+1) : 0;
		i=mod(i+1,n);
	}
    i=mod(k-1,n);
	while(i!=k)
	{
		Red_R[i]=(neck[i]!='b') ? (Red_R[mod(i+1,n)]+1) : 0;
		i=mod(i-1,n);
	}
    for(k=0;k<n;++k)
		if(neck[k]=='r')
			break;
    if(neck[k]!='r')
		return n;
		
    Blue_L[k]=0;
	Blue_R[k]=0;
    i=mod(k+1,n);
	while(i!=k)
	{
		Blue_L[i]=(neck[i]!='r') ? (Blue_L[mod(i-1,n)]+1) : 0;
		i=mod(i+1,n);
	}
    i=mod(k-1,n);
	while(i!=k)
	{
		Blue_R[i]=(neck[i]!='r') ? (Blue_R[mod(i+1,n)]+1) : 0;
		i=mod(i-1,n);
	}	
    for(i=0;i<n;++i)
		ans=Max(ans,Max(Red_L[i],Blue_L[i])+Max(Red_R[i+1],Blue_R[i+1]));
    return ans>n?n:ans;
}

int main()
{   
    int n;
    char necklace[400];
    #ifdef FILE
    freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	#endif
    scanf("%d\n%s",&n,necklace);
    printf("%d\n",Work(necklace,n));
    return 0;
}

