#include <cstdio>
#include <cstring>

using namespace std;

int n;
long long ans;

int main()
{
	scanf("%d",&n);
	ans=1;
	for(int i=0;i<6;i++)
		ans*=(n-i);
	for(int i=1;i<=6;i++)
		ans/=i;
	printf("%lld\n" ans);
	return 0;
}
