#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define MAXN
#define SpeedUp ios::sync_with_stdio(false)
#define FILE
using namespace std;
long long f[20000],a[20000];
long long n,c,k;
inline int cmp(const void *a,const void *b){return *(long long *)a-*(long long *)b;}
void init()
{
	SpeedUp;
	#ifdef FILE
	freopen("dividea.in","r",stdin);
//	freopen("dividea.out","w",stdout);
	#endif
}

int main()
{
	init();
	scanf("%lld%lld%lld",&n,&k,&c);
	long long i,j,god;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(long long),cmp);
	for(i=1;i<=n;i++) f[i]=1000000000;
	f[k]=(a[k]-a[1])*(a[k]-a[1])+c; f[0]=0;
	for(i=k+1;i<=n;i++) 
	{
	  for(j=i-k;j>=0;j--) 
	  {
	  	god=f[j]+(a[i]-a[j+1])*(a[i]-a[j+1])+c;
	  	if (god<f[i]) f[i]=god;
	  }
    }
    printf("%lld\n",f[n]);
	return 0;
}

