#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long N,a,b;

void A()
{
	long long  w;
	cin>>w;
	cout<<((w%b)*(a%b))%b/a<<" ";
}

void work()
{
	cin>>N>>a>>b;
	for(int i=1;i<=N;i++)
	{
		A();
	}
	cout<<endl;
}

int main()
{
	work();
	return 0;
}

