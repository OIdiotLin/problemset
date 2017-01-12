#include <iostream>
#include <cstdio>
using namespace std;


const long long A[]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,\
				32768,65536,131072,262144,524288,1048576,2097152,\
				4194304,8388608,16777216,33554432,67108864,134217728,\
				268435456,536870912,1073741824,2147483648,4294967296};

int main()
{
	#ifdef FILE
	freopen("watera.in","r",stdin);
	freopen("waterb.out","w",stdout);
	#endif
	
	long long N,K;
	scanf("%lld%lld",&N,&K);
	
	for(int i=1;i<=K-1;i++)
		for(int j=1;;i++)
		{
			if((A[j]<N && A[j+1]>N) || A[j+1]==N)
			{
				N-=A[j];
				break;
			}
		}
	
	for(int i=1;;i++)
	{
		if(A[i]<N && A[i+1]>N)
		{
			printf("%lld\n",A[i+1]-N);
			break;
		}
		else if(A[i]==0)
		{
			printf("0\n");
			break;
		} 
	}
	
	return 0;
}
