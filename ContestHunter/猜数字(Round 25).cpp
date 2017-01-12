#include <iostream>
#include <cstring>
#define MAXN 200050
using namespace std;

int Box[MAXN];
int N;

void init()
{
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>Box[i];
}

int work(int Box[])
{
	int ans=0;
	for(int i=2;i<=N-1;i++)
	{
		if(Box[i]>Box[i-1] && Box[i]==Box[i+1])//start
			ans++;
		else if(Box[i]==Box[i-1] && Box[i]<Box[i+1])//end
			ans++;
	}
	return ans;
}

int main()
{
	init();
	cout<<work(Box)<<endl;
	return 0;
}
