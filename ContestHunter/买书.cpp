#include <iostream>
#include <cstring>
#define MAXN 1000010

using namespace std;
long long N,M,K,Ans;
int A[MAXN];

void init()
{
	cin>>N>>M>>K;
	Ans=M/((N+1)/2)*K;
	for(int i=1;i<=N;i++)
		cin>>A[i];	
}

void Buy()
{
	for(int i=1;i<=(N+1)/2;i++)
	{
		if(A[i/2-1]<Ans)
			Ans=A[i/2-1];
		if(N%2==0)
			Ans=0;
	}
}

int main()
{
	init();
	Buy();
	cout<<Ans<<endl;
	return 0;
}

