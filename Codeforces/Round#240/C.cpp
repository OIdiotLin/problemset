#include <iostream>
#include <cstring>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
//#define FILE
using namespace std;

int N,K;

void A()
{
	int pair=(N/2);
	int k1=K-(N-2)/2;
	cout<<k1<<" "<<2*k1<<" ";
	
	int cnt=1;
	for(int i=6*k1+1;cnt<=N-2;i--,cnt++)
	{
		cout<<i<<" ";
	}
}

void work()
{
	cin>>N>>K;
	if(N==1 && K==0)
	{
		cout<<"1"<<endl;
		return;
	}
	if(N/2>K || N==1 || K==0)
	{
		cout<<-1<<endl;
		return;
	}
	A();
}

int main()
{
	work();
	return 0;
}

