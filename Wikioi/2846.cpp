#include <iostream>
using namespace std;
int power[1000];
int n,m,i,a,b;
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>power[i];
	}
}

void comp(int a,int b)
{
	if(power[a]>power[b])
		cout<<a;
	else if(power[a]<power[b])
		cout<<b;
	else if(power[a]==power[b])
		cout<<(a>b)?a:b;
	cout<<" win!"<<endl;
}

void match()
{
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		comp(a,b);
	}
}
int main()
{
	init();
	match();
	return 0;
}
