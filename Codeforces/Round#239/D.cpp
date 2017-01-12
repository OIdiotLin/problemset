#include<cstdio>
#include<cstdlib>
#include <iostream>
#define MOD 1000000007
using namespace std;
int N,LHD[2000],f[2000];
int main()
{
	int i,j,s;
	cin>>N;
	for(i=1;i<=N;i++) 
		cin>>LHD[i];
	f[1]=2;
	for(i=2;i<=N;i++)
	{
		if(LHD[i]==i) f[i]=2; else 
		{
			s=2;
			for(j=LHD[i];j<=i-1;j++) s=(s+f[j])%MOD;
			f[i]=s;
		}
	}
	s=0;
	for(i=1;i<=N;i++) s=(s+f[i])%MOD;
	cout<<s<<endl;
	return 0;
}

