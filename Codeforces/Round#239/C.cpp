#include<cstdio>
#include<cstdlib>
#include <iostream>
#include<cmath>
using namespace std;
int N,M;
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	int i,j,k,osu;
	double LHD1,LHD2;
	cin>>N>>M;
	if(N<M) i=N,N=M,M=i; k=M/gcd(N,M); osu=N/gcd(N,M); 
	for(i=1;i<N;i++)
	{
		LHD1=N*N-i*i;
		LHD2=sqrt(LHD1);
		if(LHD2==floor(LHD2))
		{
			j=int(LHD2);
			if(i%osu==0&&j%osu==0) 
			{
				cout<<"YES"<<endl;
				cout<<"0 0"<<endl;
				cout<<-i<<" "<<j<<endl;
				cout<<(j/osu)*k<<" "<<(i/osu)*k<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
