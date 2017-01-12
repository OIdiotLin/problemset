#include<stdio.h>
int main()
{
	double n,s=0,sa=0,a,b;
	scanf("%lf",&n);
	while(n!=0)
	{
		scanf("%f%f",&a,&b);
		s+=a*b;
		sa+=a;
		n--;
	}
	printf("%.2lf",(s/sa));
	return 0;
}
