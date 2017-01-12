#include <iostream>
#include <cmath>
using namespace std;

int a,s;

int work(int x)
{
	int ans=0;
	for(int i=1;i<sqrt(x);i++)
		if(x%i==0)
			ans++;
	return 2*ans;
}

int main()
{
	int sum=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
		sum+=work(i);
	cout<<sum<<endl;
	return 0;
}
