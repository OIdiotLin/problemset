#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
double h,s,v,l,k,n; 
int answer=0;
int main()
{
	freopen ("freefaller.in","r",stdin);
	freopen ("freefaller.out","w",stdout);
	cin>>h>>s>>v>>l>>k>>n;
	double t,y,y2;
	t=sqrt(0.2*(h-k));
	y=s-v*t;
	y2=y+l;
	t=sqrt(0.2*(h));
	y=s-v*t;
	for (int i=0;i<n;i++)
	{
		if (i>=y-0.00001&&i<=y2+0.00001)
		{
			answer++;
		}
	}
	printf("%d",answer);
	return 0;
}
