#include <stdio.h>
int f(int a,int b)
{
	int t; 
	if(a>b)
	{ 
		t=a;
		a=b;
		b=t; 
	} 
	for(t=a;t%a||t%b;t+=a); 
	return t;
}
int main()
{
	int a[20]; 
	int i,k; 
	int n; 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
	{
		scanf("%d",&a[i]); 
	} 
	k=1; 
	for(i=0;i<n;i++) 
	{ 
		k=f(k,a[i]); 
	} 
	printf("%d",k); 
	return 0; 
}
