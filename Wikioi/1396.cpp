#include <iostream>
#include <cmath>

using namespace std;

int work(int limit)
{
	int sum=0;
	for(int i=1;i<sqrt(limit);i++)
	{
		if(limit%i==0)
			sum+=(i+limit/i);
		else 
			continue;
	}
	return sum;
}

int main()
{
	int N,m;
	cin>>N;
	while(N--)
	{
		cin>>m;
		cout<<work(m)<<endl;
	}
	return 0;
}
