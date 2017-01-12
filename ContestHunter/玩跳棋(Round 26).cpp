#include <iostream>
#include <cstdio>
#include <algorithm>
#define SpeedUp ios::sync_with_stdio(false)

using namespace std;
int a,b;

void init()
{
	SpeedUp;
	cin>>a>>b;
	if(a && a<b)
		swap(a,b);
}

void judge(int a,int b)
{
	if(a==0)
		{cout<<b<<endl;return;}
	if(b==0)
		{cout<<"N/A"<<endl;return ;}
	if(a<0 || b<0)
	{
		if(a!=b)
			{cout<<"N/A"<<endl;return ;}
		else
			{cout<<b<<endl;return ;}
	}
	while(a)
	{
		if(a<b)
			swap(a,b);
			a%=b;
	}
	cout<<b<<endl;
}

int main()
{
	//while(1)
	//{
	init();
	judge(a,b);
	//}
	return 0;
}
