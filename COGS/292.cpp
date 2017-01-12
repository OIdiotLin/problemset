#include <iostream>
#include <cstdio>
#include <cmath>
#define FILE

using namespace std;

int main()
{
	#ifdef FILE
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	#endif
	double v,v0,x;
	scanf("%lf%lf",&v,&v0);
	x=v/v0/2;
	if(x-floor(x)==0.5)
	{
		printf("0\n");
	}
	else printf("%d\n",(int)x);

	return 0;	
}
